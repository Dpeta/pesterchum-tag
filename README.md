# pesterchum-tag
UnrealIRCd module for '+pesterchum' message tag.

Trying to see if this could serve as an alternative to Pesterchum's current method of communicating its unique statuses. Currently this is done via a PRIVMSG containing: PESTERCHUM:BEGIN, PESTERCHUM:BLOCK, PESTERCHUM:CEASE, or PESTERCHUM:TIME, which shows up as garbage for users using different clients. Since [979173c33d07c6d32a87aaa054bc0dba905cf6ab](https://github.com/Dpeta/pesterchum-alt-servers/commit/979173c33d07c6d32a87aaa054bc0dba905cf6ab) it should be possible to send:

- ``@+pesterchum=BEGIN TAGMSG caninelikeGunman`` instead of ``PRIVMSG caninelikeGunman PESTERCHUM:BEGIN``.
- ``@+pesterchum=CEASE TAGMSG caninelikeGunman`` instead of ``PRIVMSG caninelikeGunman PESTERCHUM:CEASE``.
- ``@+pesterchum=BLOCK TAGMSG caninelikeGunman`` instead of ``PRIVMSG caninelikeGunman PESTERCHUM:BLOCK``.
- ``@+pesterchum=TIME>F777777:00 TAGMSG #q`` instead of ``PRIVMSG #q PESTERCHUM:TIME>F777777:00``.

Unlike the PRIVMSG method, the tags don't show up for non-Pesterchum users.

This module is pretty barebones rn and doesn't do any validity checking for values in its current state.

## INSTALL
1. Move 'pesterchum-tag.c' to 'unrealircd/modules/third' in unrealIRCd's source. 
2. Run ``make`` and ``make install`` again.
3. Include ``loadmodule "third/pesterchum-tag";`` somewhere in your config file.
