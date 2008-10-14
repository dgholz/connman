/*
 *
 *  Connection Manager
 *
 *  Copyright (C) 2007-2008  Intel Corporation. All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
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

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <connman/plugin.h>
#include <connman/element.h>
#include <connman/rtnl.h>
#include <connman/log.h>

static void rtnllink_newlink(unsigned short type, int index,
					unsigned flags, unsigned change)
{
	DBG("index %d", index);
}

static void rtnllink_dellink(unsigned short type, int index,
					unsigned flags, unsigned change)
{
	DBG("index %d", index);
}

static struct connman_rtnl rtnllink_rtnl = {
	.name		= "rtnllink",
	.newlink	= rtnllink_newlink,
	.dellink	= rtnllink_dellink,
};

static int rtnllink_init(void)
{
	return connman_rtnl_register(&rtnllink_rtnl);
}

static void rtnllink_exit(void)
{
	connman_rtnl_unregister(&rtnllink_rtnl);
}

CONNMAN_PLUGIN_DEFINE("rtnllink", "RTNL link detection plugin", VERSION,
						rtnllink_init, rtnllink_exit)
