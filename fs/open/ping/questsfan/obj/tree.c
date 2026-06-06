//奇怪的大樹------by dhk 2000.5.7
#include "/open/open.h"
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("" + GRN + "高大的樹" + NOR + "", ({ "tall tree","tree" }) );
    set_weight(1000000);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "怎麼看都覺得這棵大樹怪怪的，搖搖看﹝shaking_tree﹞不知道會怎樣？\n");
       set("unit", "棵");
       set("value", 150);
       set("no_sell",1);
       set("no_auc",1);
       set("no_give",1);
       set("no_get",1);
      }
    setup();
}
void init()
{
  add_action("do_shake","shaking_tree");
}
int do_shake()
{
  object me = this_player();
  if(me->query_temp("meetgod_1") != 1)
{
  write("" + HIR + "忽然樹間一道紅色的身影迅速掠過！" + NOR + "\n");
  me->set_temp("meetgod_1",1);
}
  else
  if(me->query_temp("meetgod_1") == 1)
  {
  write("" + HIR + "忽然樹間一道紅色的身影迅速掠過！" + NOR + "\n");
  write("" + HIC + "忽然間四周仙音繚繞：『" + HIG + "藏仙谷，谷中仙，仙緣昇，昇得意" + HIC + "』" + NOR + "\n");
  me->set_temp("meetgod_2",1);
  }
  return 1;
}

