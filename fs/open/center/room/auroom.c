// Room: /open/center/room/auroom.c
// copy from //u/c/chun/shop/auroom.c

#include "/open/open.h"
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","黑市");
        set("long",@LONG
這是黑市，專門喊標物價用的。
LONG );

        set("exits",([
	  "out"	:	__DIR__"bank",
        ]));
	set("objects", ([
	    CENTER_NPC"auc_man"	:	1,
	]) );
	set("light_up",1);
        set("no_clean_up",1);
        setup();
}
