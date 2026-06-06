#include <ansi.h>
#include <room.h>
inherit ROOM;
                
void create ()
{
  set ("short", "休息室");
  set ("long", @LONG
這是殺手們接受特訓後的休息的地方  
在這兒有一小水池(water),池水似乎有點髒，但是還是可以喝的,
不過我想還是不要喝比較好，拿來洗東西倒是不錯的建議。
可以聽到地下傳來一陣陣淙淙的水聲,想必是地下水源所發出的


LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r0.c",
  "west" : __DIR__"restrm.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "water" : "池水雖然有點怪顏色,但是你還是可以在這兒喝水(drink) 
",
   ]));
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}

void init()
{
   add_action("do_drink", ({"drink"}) );
   add_action("do_enter",({"enter"}));
   add_action("do_wash",({"wash"}));
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
    tell_object(me,"你從池中舀了幾口水喝，發現池水似乎有怪味......\n");
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
who->move(__DIR__"stonerm.c");
   return 1;
   }
      return 0;
}

int do_wash(string arg)
{
   object who;

   who=this_player();

   if(present("herb",who))
   {
     tell_object(who,"\n你將富士山秘草放入這個怪顏色的水池中，
      嘩啦地洗了起來～\n\n");
     tell_object(who,HIW"只見一陣奇怪的顏色變化～～ \n"NOR);
     tell_object(who,"秘草發出了奇異的光芒，應該可以了吧。。。 \n");
   }
   if(who->query_temp("herb_1")==1)
   {
     tell_object(who,HIW"但是由於你再一次洗秘草～～ \n"NOR);
     tell_object(who,"使得秘草發出了金色的光芒，終於可以了！ \n");
     who->set_temp("herb_1",2);
   }
   who->set_temp("herb_1",1);
   return 1;
}  
