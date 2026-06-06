// by Alucard 2009/09
inherit ROOM;
#include <ansi.h>
#include <mudlib.h>
#include <command.h>
void create () {
        set("short","炎日村口");
		set("long", "經過了漫長的路程，終於來到一個像村莊的地方了，現在的你就
好像快被蒸發一樣，全身汗流浹背，還搞不清楚狀況的你巴不得趕快
離開這裡。這裡是這村莊的入口，在你身旁立著一塊石碑，上頭刻著
斗大的三個字－炎日村。
" );
        set("no_auc", 1);
        set("no_transmit", 1);
		set("no_scale",1);
		set("no_chome",1);
        set("light_up",-1);
		set("outdoors", "/open/main");
        set("exits", ([
            "north" :  __DIR__"street01",
			"south" :  __DIR__"path05",   
      ]));
        setup();
}
