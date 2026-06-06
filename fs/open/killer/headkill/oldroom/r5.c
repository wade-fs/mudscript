#include <ansi.h>
#include <room.h>
inherit ROOM;
                
void create ()
{
  set ("short", "休息室");
  set ("long", @LONG
 這是殺手們完成任務後的休息的地方  
在這兒有一小水池(water),池水非常清澈,
可以聽到地下傳來一陣陣淙淙的水聲,想必是地下水源所發出的

然而目前的水池，雖然仍有清水源源不覺得冒出，
但是看見水底的通道似乎早已被，石頭所掩蓋住，
想必是當年想要以炸藥炸死各派傳人的時候，故意斷掉所有通路。
但是，細心的你發現，水底的石頭附近，並沒有長青苔。
似乎，並非長時間不動的岩石，難不成水底通道並沒有被封住？
LONG);

  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r4",
  "east" : __DIR__"r6",
  "south" : __DIR__"r8.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "water" : "池水非常清澈,你可以在這兒喝水(drink) 
",
   ]));
/*
  set("objects", ([ 
  "/open/killer/npc/trainer2.c" : 2,]));
*/
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}
void init()
{
   add_action("do_drink", ({"drink"}) );
   add_action("do_enter",({"enter"}));
}
int do_drink(string arg)
{
  object me;
  if (!arg || arg=="" )
  {
  me = this_player();
  if ( (int)me->query("water") >= (int)me->max_water_capacity() )
    {
    tell_object(me,"你已經一口水也喝不下了.......\n");
    return 1;
    }
    tell_object(me,"你從池中舀了幾口水喝......\n");

    me->add("water",40);
  return 1;  
}
    return 1;
}

int do_enter(string arg)
{
   object who;
   who=this_player();
   if(who->query("class")!="killer")
   return notify_fail("這是殺手專用密道,一般人無法進入!\n");
   if((arg="water") || (arg=="water")) {
   message_vision(GRN"$N進入了小水池中\n"NOR,who);
   tell_object(who,"\n你只聽到～～～～嘩啦～～～～
    ～～～～～～～～～～～～～～～～～～～～～～～～～嘩啦～～～\n\n");
   tell_object(who,HIW"只見一陣強大的水勢迎面而來～～ \n"NOR);
   tell_object(who,"你在無法反抗之下被水流帶往他處 \n");
tell_object(who,HIC"\n你感覺水勢減弱,隨便亂抓之下,抱住一顆大石頭 \n\n"NOR);
	who->move(__DIR__"r7.c");
   return 1;
   }
      return 0;
}
