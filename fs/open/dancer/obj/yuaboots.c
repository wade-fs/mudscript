//dancerboots//
//調整wear remove的參數不正確 by blazakira 2011/7/9

#include <ansi.h>
inherit EQUIP;

void create()
{
  set_name(MAG + "鳳舞靴" + NOR,({"boots"}) );
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else{
    set("long","
這是月牙兒專用的舞靴，相傳為傅劍寒所贈的鳳羽所製，非但外觀極其
美麗，相傳更有不可思議之效。\n");
    set("unit","雙");
    set("value",20000);
    set("no_save",1);
    set("armor_prop/armor",30);
    set("armor_prop/move",10);
    set("material","leather");
    set("gender_only","女性");
    set("armor_type","boots");
//    set("need_class","dancer");
  }
  setup();
}

int wear()
{
  object obj = this_object();
  object me = environment();
  int ret = ::wear();
  if(query("equipped") && me->query("class")=="dancer" && !me->query_temp("have_wear_boots")) { //dancer一派才有額外技能加成
    if(environment(me))
      message_vision(HIM + "$N穿上鳳舞靴忽然感到身子輕盈了起來，好似要飛一般。\n" + NOR,me);
    me->add_temp("apply/unarmed", 5);
    me->add_temp("apply/dodge",10);
    me->set_temp("have_wear_boots",1);
  }
  return ret;
}

int unequip()
{
  object obj = this_object();
  object me = environment();
  if(!query("equipped") && me->query("class")=="dancer" && me->query_temp("have_wear_boots") == 1) {
    if(environment(me) )
      message_vision(YEL + "$N" + YEL + "將$n" + YEL + "脫了下來，感到身體一沉，又恢復原狀了。\n" + NOR,me,obj);
    me->add_temp("apply/unarmed", -5);
    me->add_temp("apply/dodge",-10);
    me->delete_temp("have_wear_boots");
  }
  return ::unequip();
}



