inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short",HIR"極火山寨"NOR"  地下一層");
        set ("long",@LONG
一條細長的走道，上面黃沙覆蓋，兩側是黃土牆。
南邊傳來陣陣打呼聲，還有一條路往西。
LONG);
        set("exits",([			//設定出口
"west":__DIR__"fortress04",
"south":__DIR__"fortress08",
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}
