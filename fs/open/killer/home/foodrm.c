#include "/open/open.h"
inherit ROOM;
void create ()
{
  set ("short", "殺手\餐\廳");
  set ("long", @LONG
這裡是殺手們練習後，用\餐\的好地方。四周已經有不少人在吃飯了。
由他們愉悅的神情與狼吞虎嚥的樣子，看來這裡的食物還蠻好吃的。
牆上貼著一份價目表(table)我想你還是先看看的好。
看完之後，想吃什麼可以用(order)叫\餐\
LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "table" : "如果想叫\餐\，請用order XXXX決定既可，老闆會盡快服務的。\n
             A : 陽春麵          30  coins\n
             B : 香肉爐          70  coins\n
             C : 溫州大餛飩     100  coins\n
             D : 海陸大\餐\     150  coins\n
            ",
  ]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"r18",
  "east" : __DIR__"sr0",
  "north" : __DIR__"leerm",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "table" : "幹嘛！多看兩眼也不會比較便宜呀！\n",
]));

  setup();
}
void init()
{
	add_action("do_order","order");
}
int do_order(string str)
{
 object me;

        me=this_player();
	if( str == "" )
	  return notify_fail("喂。。你想叫什麼東西呀？\n");
        switch(str)
        {
         case "A":
         { 
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"你想撐死嗎？會餓才來吧！.......\n");
            return 1;
          }
          if(!me->can_afford(30))
          {
           tell_object(me,"想吃霸王\餐\嗎？帶點錢來吧。\n");
           return 0;
          }
          me->add("food",40);
          me->add("water",50);
          me->pay_money(30);
          tell_object(me,"一碗熱騰騰的陽春麵端了上來，令你吃的不亦樂乎。\n");
          return 1;
         }
         case "B":
         { 
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"你想撐死嗎？會餓才來吧！.......\n");
            return 1;
          }
          if(!me->can_afford(70))
          {
           tell_object(me,"想吃霸王\餐\嗎？帶點錢來吧。\n");
           return 0;
          }
          me->add("food",90);
          me->add("water",50);
          me->pay_money(70);
          tell_object(me,"一爐熱騰騰的香肉端了上來，令你吃的不亦樂乎。\n");
          return 1;
         }
         case "C":
         { 
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"你想撐死嗎？會餓才來吧！.......\n");
            return 1;
          }
          if(!me->can_afford(100))
          {
           tell_object(me,"想吃霸王\餐\嗎？帶點錢來吧。\n");
           return 0;
          }
          me->add("food",100);
          me->add("water",110);
          me->pay_money(100);
          tell_object(me,"一碗熱騰騰的溫州大餛飩端了上來，令你吃的不亦樂乎。\n");
          return 1;
         }
         case "D":
         { 
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"你想撐死嗎？會餓才來吧！.......\n");
            return 1;
          }
          if(!me->can_afford(150))
          {
           tell_object(me,"想吃霸王\餐\嗎？帶點錢來吧。\n");
           return 0;
          }
          me->add("food",150);
          me->add("water",150);
          me->pay_money(150);
          tell_object(me,"一整套的海陸大\餐\端了上來，令你吃的不亦樂乎。\n");
          return 1;
         }
        }
       return notify_fail("喂。。你想叫什麼東西呀？\n");
}
