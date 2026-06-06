// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","山坡上");
		set("long", "陡峭的山路加上炎熱的天氣，讓你每踏出一步，身體就越來越沉
重，身體好像快被融化一樣開始漸漸的失去自主，這山上因為久旱的
關係而寸草不生，連個遮蔽的地方都沒有，看來你得一股作氣的向上
走了。
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "up" :  __DIR__"mount05",
			"down" :  __DIR__"mount03",  
            "west" :  __DIR__"temple",			
      ]));
        setup();
}
