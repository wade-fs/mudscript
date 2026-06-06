// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","小徑");
		set("long", "好不容易走出了那片枯\木林，但是仍然不知道這裡到底是哪裡，
眼前的路是一條彎曲的小徑，不知道要將你引去哪裡，道路在這裡
向南邊和東邊延伸
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "east" :  __DIR__"path05",
			"south" :  __DIR__"path03",   
      ]));
        setup();
}
