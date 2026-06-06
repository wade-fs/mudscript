inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","閃光之扉");
set("long",@LONG
強大無匹的皇者霸氣迎面而來，你差點被嚇得魂不守魄，沒辦法，
位居四絕之首的九魔龍--完顏烈火就是如此的霸、如此的強，瞧!!他以
霸王金身直接硬食周圍魔怪的幽冥鬼氣，氣勢之鋒銳絲毫不見消減，運
足十二成功力吧，否則你是絕對沒有勝算的。
LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "south"     : __DIR__"room30",
        "north"     : __DIR__"room36",
      ]));
        set("objects", ([ /* sizeof() == 1 */
        "/open/magic_palace/npc/4-1.c" : 1,
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
    object dragon = present("Nine Dragon");
    if(dragon)
    {
    message_vision(HIW"\n完顏烈火冷笑道：「這點小技倆在我面前是行不通的。」\n"NOR,me);
    me->start_busy(2);
    dragon->kill_ob(me);
    }
    return 1;
}

int valid_leave(object me,string dir)
{
	object obj = present("Nine Dragon");
        if( dir == "north" )
        {
        	if(obj)  return notify_fail(HIR"完顏烈火"HIW"冷笑道:『兀那小子，以為這裡是你家!?說走就走!?』\n"NOR);
        }

return 1;
}
