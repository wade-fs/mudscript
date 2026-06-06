#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("密碼羅盤", ({ "compass" }) );
        set("long","有著指針的羅盤，下面還標示著『密碼』，（check)看看吧！\n");
        set_weight(10);
        set("unit", "組");
        set("value", 0);
        set("no_sell", 1);
        set("no_give", 1);
        set("no_auc", 1);
        set("no_drop", 1);
        setup();
}

void init ()
{
 add_action ("do_watch","check");
}

int do_watch(string arg)
{
   int sk;
   object ob,me,target;
   string str;
   me = this_player();
   ob = this_object();

   if( arg != "密碼" )
       return notify_fail("你檢查什麼呀？﹖\n");
   if (me->query("class") != "killer")
   {
      tell_object(me,"作弊！去死吧！！你發現自己有點發昏，然後就不醒人事了！\n"); 
       me->move("/open/death/start");
      return 1;
   }

   if( me->query_temp("firstpart") != 10)
   {//基本上很不合理，因為送進去與設定都在同一處
     tell_object(me,"你看了一眼，居然發現自己有點發昏，然後就不醒人事了！\n"); 
     me->move("/open/killer/room/masterm.c");
     me->delete_temp("firstpart");
     destruct(this_object());
     return 1;
   }
   tell_object(me,"          辛         \n"); 
   tell_object(me,"          |          \n"); 
   tell_object(me,"      ----戊-----    \n"); 
   tell_object(me,"          |          \n"); 
   tell_object(me,"          乙         \n"); 
   tell_object(me,"陸2,捌3，肆1，貳4，參2，玖3 \n"); 
return 1;
}
