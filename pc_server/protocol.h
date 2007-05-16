/**
 * @file   protocol.h
 * @author Adenilson Cavalcanti
 * @date   Tue May  8 09:08:59 2007
 *
 * @brief  Protocol handling functions/codes goes here.
 *
 * I'm still working on a protocol for handling events and data
 * exchange between the cellphone and PC.
 *
 */

/*  Copyright (C) 2007  Adenilson Cavalcanti <savagobr@yahoo.com>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; by version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __PROTOCOL_PC__
#define __PROTOCOL_PC__

#include <string.h>


/** Command event codes */
enum { UP, DOWN, LEFT, RIGHT, NONE } codes;

/** Command event codes, what we expect to receive from
 * cell phone.
 */
static char *cell_key_code[] = { "UP",
			  "DOWN",
			  "LEFT",
			  "RIGHT"
};

/** Mouse event codes, what we expect to receive from
 * cell phone.
 */
static char *cell_mouse_code[] = { "MOUSE_MOVE",
			   "MOUSE_BUTTON_PRESS",
			   "MOUSE_BUTTON_RELEASE",
			   "MOUSE_BUTTON_RIGHT",
			   "MOUSE_BUTTON_LEFT",
			   "MOUSE_BUTTON_MIDDLE",
			   "MOUSE_SCROLL_UP",
			   "MOUSE_SCROLL_DOWN"
};


/** Special character to describe end of command */
static const char CMD_BREAK = '\n';


/** Convert a cell event to correspondent X window event code.
 *
 *
 * @param event String with event/command.
 * @param length Length of string command.
 *
 * @return A code representing the event or NONE otherwise.
 * \todo: turn this code to a vector with loop... several if/elses are
 * not beauty.
 *
 */
static int ecell_convert_ewindow(char *event, int length)
{
	int res = NONE;
	if (!strncasecmp(event, cell_key_code[UP], length))
		res = UP;
	else if (!strncasecmp(event, cell_key_code[DOWN], length))
		res = DOWN;
	else if (!strncasecmp(event, cell_key_code[LEFT], length))
		res = LEFT;
	else if (!strncasecmp(event, cell_key_code[RIGHT], length))
		res = RIGHT;

	return res;
};


#endif
