// made by Daniel  .......老酥咧....
#include <ansi.h>
inherit COMBINED_ITEM;
void create()
{
set_name("神龍活氣丸",({"dragon pill","pill"}));
set("long","此乃銀針獨門醫術所煉製的神丹,服用後可增強內勁爆發力。\n");
set("unit","顆");
set("base_unit","顆");
set("value",10000);
set("base_weight",100);
set("medicine_times",8);
     set_amount(1);
}
void init()
{
      if( this_player()==environment() )
          add_action("do_eat","eat");
}
int do_eat(string arg)
{
   object me;
    me = this_player();
if(!arg||arg!="dragon pill")return notify_fail("你要幹啥?\n");
        message_vision(
  "$N拿出一顆$n吞了下去。\n"
        ,me, this_object());
 me->apply_condition("strong",10);
 me->set_temp("strong",1);
 if((int)me->query_temp("strong")<2) {
 write("你吃了之後﹐全身筋骨舒軟了一下。\n"
      "你發覺內勁似忽增加不少...\n");
 write("這神龍活氣丸雖好﹐並不適於連續食用﹐否責....!!\n");
 me->set("force_factor",29);
 me->set("enforceup",1);
       }else{
 message_vision(HIR + "$N突然覺得五臟六腑一陣劇痛﹐鮮血由七竅狂噴而出！\n" + NOR, me);
 me->die();
 }
   add_amount(-1);
    return 1;
}


