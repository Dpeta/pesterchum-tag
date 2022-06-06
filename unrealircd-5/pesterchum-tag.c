/*
 *   Modeled after the message tag modules from the UnrealIRCd repo.
 *   https://github.com/unrealircd/unrealircd
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 1, or (at your option)
 *   any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include "unrealircd.h"

ModuleHeader MOD_HEADER
  = {
	"third/pesterchum-tag", /* name */
	"1.1", /* version */
	"+pesterchum client tag", /* description */
	"Shou", /* author */
	"unrealircd-5", /* module API version */
	};

/* Variables */
long CAP_PESTERCHUM_TAG = 0L;

/* Forward declarations */
int pchum_mtag_is_ok(Client *client, char *name, char *value);
void mtag_add_pchum(Client *client, MessageTag *recv_mtags, MessageTag **mtag_list, char *signature);

MOD_INIT()
{
	ClientCapabilityInfo cap;
	ClientCapability *c;
	MessageTagHandlerInfo mtag;

	memset(&cap, 0, sizeof(cap));
	cap.name = "pesterchum-tag";
	c = ClientCapabilityAdd(modinfo->handle, &cap, &CAP_PESTERCHUM_TAG);
	
	memset(&mtag, 0, sizeof(mtag));
	mtag.name = "+pesterchum";
	mtag.is_ok = pchum_mtag_is_ok;
	mtag.clicap_handler = c;
	MessageTagHandlerAdd(modinfo->handle, &mtag);

	HookAddVoid(modinfo->handle, HOOKTYPE_NEW_MESSAGE, 0, mtag_add_pchum);

	return MOD_SUCCESS;
}

MOD_LOAD()
{
	return MOD_SUCCESS;
}

MOD_UNLOAD()
{
	return MOD_SUCCESS;
}

/** This function verifies if the client sending the mtag is permitted to do so.
 */
int pchum_mtag_is_ok(Client *client, char *name, char *value)
{
	return 1;
}

void mtag_add_pchum(Client *client, MessageTag *recv_mtags, MessageTag **mtag_list, char *signature)
{
	MessageTag *m;

	if (IsUser(client))
	{
		m = find_mtag(recv_mtags, "+pesterchum");
		if (m)
		{
			m = duplicate_mtag(m);
			AddListItem(m, *mtag_list);
		}
	}
}
