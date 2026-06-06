inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short",HIR"極火山寨"NOR"  地下一層");
        set ("long",@LONG
一條細長的走道，上面黃沙覆蓋，兩側是黃土牆。
一條三叉路，透過土牆的一些細縫，南邊是一個小型的廳堂，還有兩
條路往東、西。
LONG);
        set("exits",([			//設定出口
"west":__DIR__"fortress03",
"south":__DIR__"fortress07",
"east":__DIR__"fortress05",
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}
