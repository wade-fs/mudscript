#include "/open/open.h"
inherit ROOM;
void create ()
{
  set ("short", "\\\U + ");
  set ("long", @LONG
o̬O̽m߫A\\\naC|Pwg֤HbYFC
ѥL̴rPT]`ˤlAݨӳo̪ZnYC
WKۤ@ت(table)ڷQA٬OݬݪnC
ݧAQYiH(order)s\\\
LONG);

  set("item_desc", ([ /* sizeof() == 2 */
  "table" : "pGQs\\\AХorder XXXXMwJiA|ɧ֪AȪC\n
             A : K          30  coins\n
             B : l          70  coins\n
             C : Ŧ{j_     100  coins\n
             D : j\\\     150  coins\n
            ",
  ]));
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"r18",
  "east" : __DIR__"sr0",
  "north" : __DIR__"leerm",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "table" : "FIhݨⲴ]|KyrI\n",
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
	  return notify_fail("ޡCCAQsFrH\n");
        switch(str)
        {
         case "A":
         { 
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"AQܡH|j~ӧaI.......\n");
            return 1;
          }
          if(!me->can_afford(30))
          {
           tell_object(me,"QYQ\\\ܡHaIӧaC\n");
           return 0;
          }
          me->add("food",40);
          me->add("water",50);
          me->pay_money(30);
          tell_object(me,"@J˪KѺݤFWӡAOAY֥GC\n");
          return 1;
         }
         case "B":
         { 
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"AQܡH|j~ӧaI.......\n");
            return 1;
          }
          if(!me->can_afford(70))
          {
           tell_object(me,"QYQ\\\ܡHaIӧaC\n");
           return 0;
          }
          me->add("food",90);
          me->add("water",50);
          me->pay_money(70);
          tell_object(me,"@l˪׺ݤFWӡAOAY֥GC\n");
          return 1;
         }
         case "C":
         { 
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"AQܡH|j~ӧaI.......\n");
            return 1;
          }
          if(!me->can_afford(100))
          {
           tell_object(me,"QYQ\\\ܡHaIӧaC\n");
           return 0;
          }
          me->add("food",100);
          me->add("water",110);
          me->pay_money(100);
          tell_object(me,"@J˪Ŧ{j_ݤFWӡAOAY֥GC\n");
          return 1;
         }
         case "D":
         { 
          if ((int)me->query("food") >= (int)me->max_food_capacity())
          {
            tell_object(me,"AQܡH|j~ӧaI.......\n");
            return 1;
          }
          if(!me->can_afford(150))
          {
           tell_object(me,"QYQ\\\ܡHaIӧaC\n");
           return 0;
          }
          me->add("food",150);
          me->add("water",150);
          me->pay_money(150);
          tell_object(me,"@Mj\\\ݤFWӡAOAY֥GC\n");
          return 1;
         }
        }
       return notify_fail("ޡCCAQsFrH\n");
}
