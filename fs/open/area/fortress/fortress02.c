inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short",HIR + "極火山寨" + NOR + "  走道");
        set ("long",@LONG
一條細長的走道，上面黃沙覆蓋，兩側是黃土牆。
LONG);
        set("exits",([			//設定出口
"down":__DIR__"fortress03",
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}
