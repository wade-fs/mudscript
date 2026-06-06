inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","神光之扉");
set("long",@LONG
浩然正氣飄蕩在此處的空氣當中，面前一個略呈半透明的人形，全身上下
竟散發著神一般的氣息，沒錯，他就是三百年前曾決戰魔界金典的英雄和尚，
只是當他死了之後，為了防止第二個魔也佛誕生，決定使神元長存於魔宮內，
想要阻擋一切欲接觸佛也魔和魔界金典的人，三百年來，也的確無人能越雷池
一步，他的英雄真經造詣，亦更加超凡入聖。

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("no_magic",1);
        set("no_kill",1);
        set("no_plan",1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "north"     : __DIR__"room38",
        "south"     : __DIR__"room36",
      ]));
        set("objects", ([ /* sizeof() == 1 */
        "/open/magic_palace/npc/hero_monk.c" : 1,
      ]));
        setup();
}

int valid_leave(object me,string dir)
{
	object obj = present("Hero Monk");
        if( dir == "north" )
        {
        	if(!me->query_temp("can_fight_final"))
        	{
        	if(obj)  return notify_fail(HIC"小水滴說道:『施主真有能力除去魔也佛嗎，先讓貧僧試一下身手吧(accept_test)!!』\n"NOR);
                }
        }

return 1;
}
