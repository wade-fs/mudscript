inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","紫光之扉");
set("long",@LONG
只見面前的人全身黑色裝束，披風冉冉飄曳，身旁雷電縱橫交加，
你立刻省悟，他就是四絕高手裡的萬世教主--巴斯八，但他擅長的符咒
魔法似乎遭到某種神奇力量的意志而無法發揮，現在可是除去這個萬世
魔王以揚名立萬的大好時機啊!!

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "south"     : __DIR__"room31",
        "northwest" : __DIR__"room36",
      ]));
        set("objects", ([ /* sizeof() == 1 */
        "/open/magic_palace/npc/4-2.c" : 1,
      ]));

        setup();
}

void init()
{
	add_action("do_catch","catch");
}

int do_catch(string str)
{
    object me = this_player();
    object king = present("World King");
    if(king)
    {
    message_vision(HIW + "\n巴斯八冷笑道：「這點小技倆在我面前是行不通的。」\n" + NOR,me);
    me->start_busy(2);
    king->kill_ob(me);
    }
    return 1;
}

int valid_leave(object me,string dir)
{
	object obj = present("World King");
        if( dir == "northwest" )
        {
        	if(obj)  return notify_fail(HIM + "巴斯八" + HIW + "喝道:『當我是白痴嗎，讓你來來去去的!?』\n" + NOR);
        }

return 1;
}
