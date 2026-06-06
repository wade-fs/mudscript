// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","炎日村街道");
		set("long", "這個地方實在是太熱了，就連村裡的人都無法忍受，幾乎整天都
待在家裡，街道上冷冷清清的，一旁的小屋不時傳出人們因為受不了
而發出的哀叫，真不知道這種日子要到什麼時候才會結束。
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "south" :  __DIR__"street04",
			"north" :  __DIR__"mount01",   
      ]));
        setup();
}
