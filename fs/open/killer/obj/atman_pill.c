inherit COMBINED_ITEM;
#include <ansi.h>

void create()
{
        set_name(HIC"聚靈丹"NOR, ({"atman pill","pill"}) );
set("long","比殺手密藥更具療效的藥丸, 不易取得, 可以恢復靈力.\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("no_sell",1);
        set("value",0);
        set_amount(1);
setup();
}

void init()
{
  if( this_player()==environment() )
  {
    add_action("eat_pill", "eat");
  }
}

int eat_pill(string arg)
{      

   object ob,me=this_player();
   int max_atman,atman;

   if( !arg )                      return 0;
   arg=lower_case(arg);
   if( !ob = present(arg,me) )     return 0;
   if( ob != this_object() )       return 0;
   if (me->query("class") == "killer" && me->query("atman") < me->query("max_atman")*70)
   {
     tell_object(me,"你吃下之後感到靈力大量恢復!!!\n");
     me->add("atman",4000);
     add_amount(-1);
     return 1;
   }
   if (me->query("class") == "dancer" && me->query("atman") < me->query("max_atman")*100)
   {
     tell_object(me,"你吃下之後感到靈力大量恢復!!!\n");
     me->add("atman",6000);
     add_amount(-1);
     return 1;
   }
   if (me->query("atman") < me->query("max_atman")*50)
   {
     tell_object(me,"你吃下之後感到靈力漸漸恢復!!!\n");
     me->add("atman",2000);
     add_amount(-1);
     return 1;
   }
     tell_object(me,"你靈力過於充足, 再吃也是無用!!!\n");
     return 1;
}
