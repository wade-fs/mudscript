// sp force eq by cgy
//改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/8/4

#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
  set_name(HIC + "古龍紋玉佩" + NOR , ({"dragon_gem"}) );
  set_weight(1000);
  if ( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "塊");
    set("value", 0);
    set("material","steel");
    set("long","這是一上等和闐玉所雕成之玉佩，摸上去有溫潤的感覺。\n");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_save",1);
    set("armor_prop/armor",10);
//    set("armor_prop/force",50);
    set("armor_type","neck");
//    set("need_class","fighter");
    set("need_exp",1000000);
    set("wear_msg",HIM + "$N" + HIM + "戴起$n" + HIM + "，頓時感到一股暖流充斥全身。\n" + NOR);
    set("unequip_msg",YEL + "$N" + YEL + "脫下了$n" + YEL + "，身上的溫軟感覺也隨之消失。\n" + NOR);
  }
  setup();
}

int wear()
{
  object me;
  int result = ::wear();
  me=environment();
  if( query("equipped") && !me->query_temp("have_wear_dragongem") )
  {
    if(me->query("class")=="fighter")
      me->add_temp("apply/force",50);
    else
      me->add_temp("apply/force",10);
    me->set_temp("have_wear_dragongem",1);
  }
  return result;
}

int unequip()
{
  object me=environment();
  int result = ::unequip();
  if( !query("equipped") && me->query_temp("have_wear_dragongem") )
  {
    if(me->query("class")=="fighter")
      me->add_temp("apply/force",-50);
    else
      me->add_temp("apply/force",-10);
    me->delete_temp("have_wear_dragongem");
  }
  return result;
}
