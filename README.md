# pesterchum-tag
UnrealIRCd module for '+pesterchum' message tag.

Trying to see if this could serve as an alternative to Pesterchum's current method of communicating its unique statuses. Currently this is done via a PRIVMSG containing: PESTERCHUM:BEGIN, PESTERCHUM:BLOCK, PESTERCHUM:CEASE, or PESTERCHUM:TIME, which shows up as garbage for users using different clients.

This module is extremely barebones and doesn't do any validity checking for values in its current state.
