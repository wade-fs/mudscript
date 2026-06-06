inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "有情天");
        set ("long", @LONG
登上有情天，有一尊石像站立在最高點，你走近一看，竟然是一
尊女子石像，冷冷的空氣中伴隨著的是一種孤獨的感覺，有情的天地
之中，獨有這樣的癡情，竟化成無情的等待，時間的流逝，歲月的刻
畫，美麗的女子石像也禁不住這樣無情的摧殘。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "down"    : __DIR__"mon40",
]));
        set("objects",([
        __DIR__ "obj/statue.c":1,
]));
        setup();
}

void init()
{
        add_action("turn_statue","turn");
}
int turn_statue(string arg)
{
        object me = this_player();
        object room = this_object();
        object soul = present("die soul",room);
        
        if(me->query_temp("icestorm/ice_spell")==4)
        {
        if(!arg || arg != "statue")
                return notify_fail("你想轉動什麼？\n");
                message_vision("
$N" + HIR + "用盡全身的力氣，將雕像給硬生生的轉了一圈。" + HIY + "\n
忽然從地面傳來「隆隆」幾聲，竟出現了一個直徑三尺多的大洞。\n
" + NOR,me);
                message_vision(HIC + "蝶魂忽然說道：嗯...接下來$N就只能靠自己了，奴家該走了...\n" + NOR,me);
                room->add("exits/enter","/open/mon/hole");
                me->set_temp("icestorm/ice_spell",5);
                call_out("del_exit",30,me);
                destruct(soul);
                return 1;
        }
}
int valid_leave(object me, string dir)
{
        object guard;
        object ob = this_object();

        if(dir == "enter" && !me->query_temp("icestorm/ice_spell")==5)
                return notify_fail("蝶魂將你攔下，並說道：您並非有能力幫助奴家之人，請恕奴家無禮...\n");
                return ::valid_leave(me,dir);
}
int del_exit(object me)
{
        object ob = this_object();
        
        tell_room(me,HIR + "忽然「口匡！」的一聲，洞口又關了起來...\n" + NOR);
        ob->delete("exits/enter");
}
