//這裡是魔界村最重要的功能,讓玩家可以休息save
//其中點餐的功能改自殺手的餐廳,希望wataru不要生氣...........
//room:/u/e/eva/village/room/room-50.c        made by eva

#include <room.h>
#include <ansi.h>
#include "../village.h"

inherit ROOM;

void create ()
{
  set ("short", "魔界村旅店");
	set( "build", 846 );
  set ("long", @LONG

    這裡是魔界村的旅店, 由於魔界村是魔界的避風港, 這裡又是魔
界村唯一一家的旅店, 再加上美麗動人的老闆, 也難怪這裡時常擠滿
著客人!
    這裡供應餐點及外帶, 你可以在牆上清楚的看到菜單(menu), 至
於外帶請打(list)!

LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "menu" : "
               A.挶鱉肉           價格:50文
               B.醃漬魔豬肉       價格:80文
               C.火烤黑龍排       價格: 1銀
               D.孔雀全席         價格: 5銀
如需要餐\點 , 請打order <餐\號>, 即可立即嘗到鮮美的食物!

",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/mogi/village/npc/h_boss" : 1,
]));
  set("light_up", 1);
  set("no_magic", 1);
  set("no_transmit", 1);
//   set("valid_startroom",1);
  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/mogi/dragon/liuroom",
  "out" : __DIR__"room-46",
]));
  set("no_fight", 1);
  set("evil", 1);
  set("no_auc", 1);

  setup();
}

void init()
{
    add_action("do_order","order");
}

int do_order(string str)
{
    object me;
    int foods,waters,moneys;
    me=this_player();
    if( str!="a" && str!="A" && str!="b" && str!="B" && str!="c" && str!="C" && str!="d" && str!="D")
        {
        return notify_fail("你連自己要點什麼都不清楚嗎!?....\n");
        }
    switch(str)
        {
        case "a":
        case "A":
            {
            moneys=50;
            foods=50;
            waters=40;
            }
            break;
        case "b":
        case "B":
            {
            moneys=80;
            foods=85;
            waters=65;
            }
            break;
        case "c":
        case "C":
            {
            moneys=100;
            foods=120;
            waters=90;
            }
            break;
        case "d":
        case "D":
            {
            moneys=500;
            foods=400;
            waters=400;
            }
        }
    if(!me->can_afford(moneys))
        {
        return notify_fail("沒錢就不要充大爺嘛!.....\n");
        }
    if((int)me->query("food") >= (int)me->max_food_capacity())
        {
        return notify_fail("你已經吃不下任何東西了!!.....\n");
        }
    me->pay_money(moneys);
if ((me->query("food")+foods)>me->max_food_capacity())
    {
    me->set("food",me->max_food_capacity());
    }
else
    {
    me->add("food",foods);
    }
if ((me->query("water")+waters)>me->max_water_capacity())
    {
    me->set("water",me->max_water_capacity());    
    }
else
    {
    me->add("water",waters);
    }
    tell_object(me,"你狼吞虎嚥的吞下桌上的食物!...\n");
    return 1;
}

