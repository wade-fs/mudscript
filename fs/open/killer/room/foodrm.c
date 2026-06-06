#include "/open/open.h"
inherit ROOM;
void create ()
{
  set ("short", "殺手餐\廳");
	set( "build", 231 );
  set ("long", @LONG
    這裡是殺手們練習後，用餐的好地方。四周已經有不少人在吃飯了。
由他們愉悅的神情與狼吞虎嚥的樣子，看來這裡的食物還蠻好吃的。
牆上貼著一份價目表(table)我想你還是先看看的好。
看完之後，想吃什麼可以用(forder)叫餐
LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/killer/island/npc/luton.c" : 1,
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "table" : "如果想叫餐\，請用forder XXXX決定既可，老闆會盡快服務的。

             A : 陽春麵          1  兩金子

             B : 香肉爐          2  兩金子

             C : 溫州大餛飩      3  兩金子

             D : 海陸大餐\        5  兩金子

           \n ",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "table" : "幹嘛！多看兩眼也不會比較便宜呀！
",
]));
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"leerm",
  "west" : __DIR__"r18",
  "east" : __DIR__"sr0",
]));
  set("light", 10);

  setup();
}
void init()
{
	add_action("do_order","forder");
}
int do_order(string str)
{
 object me;
 int i;
 	me=this_player();
 	i=me->query("water");
	if( i == 0 ) i = 1;
	if( i > 1 &&  i < 1000 ) i = 1;
	if( i >= 1000 && i < 2000 ) i = i*10;
	if( i >= 2000 && i < 3000 ) i = i*20;
	if( i >= 3000 && i < 4000 ) i = i*30;
	if( i >= 4000 && i < 5000 ) i = i*40;
	if( i >= 5000 && i < 6000 ) i = i*50;
	if( i >= 6000 && i < 7000 ) i = i*60;
	if( i >= 8000 && i < 9000 ) i = i*70;
	if( i >= 9000 )	i=i*100;
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
          if(!me->can_afford(10000+i))
          {
           tell_object(me,"想吃霸王餐\嗎？帶點錢來吧。\n");
           return 0;
          }
          me->add("food",40);
          me->add("water",50);
          me->pay_money(10000+i);
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
          if(!me->can_afford(20000+i))
          {
           tell_object(me,"想吃霸王餐\嗎？帶點錢來吧。\n");
           return 0;
          }
          me->add("food",90);
          me->add("water",50);
          me->pay_money(20000+i);
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
          if(!me->can_afford(30000+i))
          {
           tell_object(me,"想吃霸王餐\嗎？帶點錢來吧。\n");
           return 0;
          }
          me->add("food",100);
          me->add("water",110);
          me->pay_money(30000+i);
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
          if(!me->can_afford(50000+i))
          {
           tell_object(me,"想吃霸王餐\嗎？帶點錢來吧。\n");
           return 0;
          }
          me->add("food",150);
          me->add("water",150);
          me->pay_money(50000+i);
          tell_object(me,"一整套的海陸大餐\端了上來，令你吃的不亦樂乎。\n");
          return 1;
         }
        }
       return notify_fail("喂。。你想叫什麼東西呀？\n");
}


