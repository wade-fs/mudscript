//yuawaist.c//
//調整wear remove的參數不正確 by blazakira 2011/7/9

#include <ansi.h>
inherit EQUIP;

void create()
{
  set_name(HIY"天蠶絲帶"NOR, ({"belt"}) );
  set_weight(100);
  if ( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "由天蠶絲所製成之腰帶，但卻極其堅軔。\n");
    set("unit", "付");
    set("armor_type", "waist");
    set("material", "leather");
    set("value", 50000);
    set("armor_prop/armor",15);
//    set("need_class","dancer");
//    set("wear_msg", HIM"$N"HIM"把$n"HIM"繫在腰上，一陣溫暖的感覺湧上心頭。\n"NOR);
//    set("unequip_msg", YEL"$N"YEL"將$n"YEL"卸了下來，心中感到一股失落感。\n"NOR);
  }
  setup();
}

int wear()
{
  object obj = this_object();
  object me = environment();
  int ret = ::wear();
  if(query("equipped") && me->query("class")=="dancer" && !me->query_temp("have_wear_belt")) { //dancer一派才有額外技能加成
    if(environment(me))
      message_vision(HIM"$N"HIM"把$n"HIM"繫在腰上，一陣溫暖的感覺湧上心頭。\n"NOR,me,obj);
    me->add_temp("apply/unarmed", 10);
    me->set_temp("have_wear_belt",1);
  }
  return ret;
}

int unequip()
{
  object obj = this_object();
  object me = environment();
//  int result = ::unequip();
  if(!query("equipped") && me->query("class")=="dancer" && me->query_temp("have_wear_belt") == 1) {
    if(environment(me))
      message_vision(YEL"$N"YEL"將$n"YEL"卸了下來，心中感到一股失落感。\n"NOR,me,obj);
    me->add_temp("apply/unarmed", -10);
    me->delete_temp("have_wear_belt");
  }
  return ::unequip();
}
