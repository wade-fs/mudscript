inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short",HIR + "極火山寨" + NOR + "  地下一層  " + YEL + "休息室" + NOR);
        set ("long",@LONG
這裡是一個寬敞的方形空間，頭頂上是黃沙覆蓋的土地，周圍依
舊是由黃土牆所包圍著，在這片寬敞的空間中，擺滿了石桌與石椅，
各式各樣的武器則擺在土牆旁。
LONG);
        set("exits",([			//設定出口
"north":__DIR__"fortress05",
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}
