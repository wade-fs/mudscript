inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short",HIR + "極火山寨" + NOR + "  地下一層  " + YEL + "大廳" + NOR);
        set ("long",@LONG
這裡是一個寬敞的方形空間，頭頂上是黃沙覆蓋的土地，周圍依
舊是由黃土牆所包圍著，腳下是綢緞鋪地。
LONG);
        set("exits",([			//設定出口
"north":__DIR__"fortress07",
"south":__DIR__"fortress10",
]));
        set("objects",([		//設定物件
__DIR__"npc/robber02":2,
__DIR__"npc/leader01":1,
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}

int valid_leave(object me,string dir)		//房間移動方向
{
        if(dir=="south")
        {
                if(present("thief",environment(me)) || present("robber",environment(me)))
                        return notify_fail(HIR + "極火山寨的小嘍嘍吼著：想過去！當我是死人啊！\n" + NOR);
        }
return 1;
}
