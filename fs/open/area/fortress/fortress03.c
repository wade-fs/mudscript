inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short",HIR"極火山寨"NOR"  地下一層");
        set ("long",@LONG
一條細長的走道，上面黃沙覆蓋，兩側是黃土牆。
一條三叉路，往上是你來時的路，南方傳來笑聲，還有一條往東的路
。
LONG);
        set("exits",([			//設定出口
"up":__DIR__"fortress02",
"south":__DIR__"fortress06",
"east":__DIR__"fortress04",
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}
