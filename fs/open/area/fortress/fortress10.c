inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short",HIR + "極火山寨" + NOR + "  地下一層  " + YEL + "大廳" + NOR);
        set ("long",@LONG
這裡放置著一座鋪著虎皮的座椅，兩側設有扶把，其中左側的扶
把上還擺著一個虎頭，虎頭上有一個焦黑的掌印，就在虎頭的眉間，
這致命的一掌，讓這老虎永遠的被躺在這裡當裝飾品。
LONG);
        set("exits",([			//設定出口
"north":__DIR__"fortress09",
]));
        set("objects",([		//設定物件
__DIR__"npc/robber02":2,
//__DIR__"npc/leader02":1,
"/open/firedancer/npc/leader02":1,		//記錄得獎...之後消除...
]));
	set("no_transmit",1);
        set("light_up",-1);		//無亮光
setup();
}

int valid_leave(object me,string dir)		//房間移動方向
{
        if(dir=="north")
        {
                if(present("thief",environment(me)) || present("robber",environment(me)))
                        return notify_fail(HIR + "極火山寨大寨主喊著：別讓他給跑了！！\n極火山寨的小嘍嘍擋住了你的去路！！\n" + NOR);
        }
return 1;
}
