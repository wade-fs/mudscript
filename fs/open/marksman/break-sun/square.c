// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","炎日村廣場");
		set("long", "廣場本來是村子裡最多人聚集的地方，而在炎日村裡卻完全看不
到這種景象，越是空曠的地方，人越是少，人們都想避開這要命的陽
光，而光是站在這裡，就像油鍋上的螞蟻般，快被烤熟了。
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "north" :  __DIR__"street03",
			"south" :  __DIR__"street02",
            "west" :  __DIR__"street08",
			"east" :  __DIR__"street09",
      ]));
	    set("objects",([ 
        __DIR__"npc/man" : 1,		
      ]));
        setup();
}
