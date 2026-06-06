// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","民房");
		set("long", "這是一間簡陋的屋子，頭頂上的屋簷勉勉強強能夠遮蔽一些陽光
，這間屋子除了一張桌子和幾張椅子之外，幾乎沒有別的東西，家中
的孩子們因為炎熱天氣而不時哭鬧，搞得每個人都更加心浮氣燥。
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "east" :  __DIR__"street04",		
      ]));
	    set("objects",([ 
        __DIR__"npc/kid" : 1,
        __DIR__"npc/man" : 1,
        __DIR__"npc/woman" : 1,		
      ]));
        setup();
}
