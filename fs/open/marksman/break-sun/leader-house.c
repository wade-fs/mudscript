// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","村長家");
		set("long", "這裡是炎日村的村長家，裡頭坐著一位愁眉苦臉的老頭兒，想必
是為了這持續十幾年的異像而煩惱吧，真希望能為他想想辦法。
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "south" :  __DIR__"street06",		
      ]));
	    set("objects",([ 
        __DIR__"npc/sheik" : 1,             
      ]));
        setup();
}
