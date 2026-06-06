#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("老舊的牛皮", ({ "papers" }) );
        set("long","好老舊的牛皮，或許可以（watch)吧！\n");
        set_weight(10);
        set("unit", "張");
        set("value", 0);
        set("no_sell", 1);
        set("no_give", 1);
}

void init ()
{
 add_action ("do_watch","watch");
}

int do_watch(string arg)
{
   int sk;
   object ob,me,target;
   string str;
   me = this_player();
   ob = this_object();

   if( arg != "papers" )
       return notify_fail("你想看什麼呀？﹖\n");
   if( me->query_temp("mission3") != 2)
   {
     tell_object(me,"你看了一眼，居然發現自己有點發昏，然後就不醒人事了！\n"); 
     me->move("/open/killer/home/masterm.c");
     return 1;
   }
   tell_object(me,"往旭日升起的方向，走三步\n"); 
   tell_object(me,"往山之陰的方向，走一步\n"); 
   tell_object(me,"不往東南北的方向，走兩步\n"); 
   tell_object(me,"往陸地最多的方向，走一步\n"); 
   tell_object(me,"往總壇在京城的方向，走兩步\n"); 
   set_temp("mission3",3);
}
