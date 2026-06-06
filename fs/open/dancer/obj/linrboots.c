//dancerboots//
//調整wear remove的參數不正確 by blazakira 2011/8/11

#include <ansi.h>
inherit EQUIP;

void create()
{
  set_name(MAG + "玲瓏靴" + NOR,({"boots"}) );
  set_weight(2000);
  if ( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","
這是水靈兒專用的舞靴，相傳為傅劍寒所贈的鳳羽所製，非但外觀極其
美麗，相傳更有不可思議之效。\n");
    set("unit","雙");
    set("value",20000);
    set("armor_prop/armor",20);
    set("armor_prop/dodge",8);
//    set("armor_prop/move",8);
    set("no_save",1);
    set("material","leather");
    set("armor_type","boots");
    set("gender_only","女性");
    set("wear_msg", HIM + "$N穿上$n" + HIM + "忽然感到身子輕盈了起來，好似要飛一般。\n" + NOR);
    set("unequip_msg", YEL + "$N將$N" + YEL + "脫了下來，感到身體一沉，又恢復原狀了。\n" + NOR);
  }
  setup();
}

int wear()
{
  object me=environment();
  int ret = ::wear();
  if( query("equipped") && !me->query_temp("have_wear_boots") )
  {
//    message_vision(HIM + "$N穿上玲瓏靴忽然感到身子輕盈了起來，好似要飛一般。\n" + NOR,me);
    if(me->query("class")=="dancer")  me->add_temp("apply/unarmed", 5);
    if(me->query("class")=="dancer")  me->add_temp("apply/dodge",8);
    me->set_temp("have_wear_boots",1);
  }
  return ret;
}

int unequip()
{
  object me=environment();
  if( query("equipped") && me->query_temp("have_wear_boots")==1 )
  {
//    message_vision(YEL + "$N將玲瓏靴脫了下來，感到身體一沉，又恢復原狀了。\n" + NOR,me);
    if(me->query("class")=="dancer")  me->add_temp("apply/unarmed", -5);
    if(me->query("class")=="dancer")  me->add_temp("apply/dodge",-8);
    me->delete_temp("have_wear_boots");
  }
  return ::unequip();
}
