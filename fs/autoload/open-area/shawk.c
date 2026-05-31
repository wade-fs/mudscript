//附註：改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20

#include <armor.h>
#include <ansi.h>
inherit HEAD;
inherit SSERVER;

void create()
{
  set_name(HIY"銀鷹頭盔"NOR,({"silver-hawk"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit","頂");
    set("value", 0);
    set("material","gem");
    set("long","皇室所使用之頭盔，有強大防護力及特殊功\效。\n");
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("thunder",1);
    set("no_steal",1);
    set("no_save",1);
    set("wear_msg",HIC"戴上了$n"HIC"後，一股神聖的力量籠罩了$N"HIC"。\n"NOR);
    set("unequip_msg",HIC"$N"HIC"脫下了$n"HIC"神聖的力量隨之離去。\n"NOR);
  }
  setup();
  set("armor_prop/move",  2);
  set("armor_prop/dodge", 3);
  set("armor_prop/parry", 4);
//  set("armor_prop/force", 5);
  set("armor_prop/armor", 50);
  set("armor_prop/magic", 30);
  set("armor_prop/force",30);
}

int query_autoload()
{
  return 1;
}

int wear()
{
  object me;
  int result = ::wear();
  if( query("equipped"))
  {
    me=environment();
//    message_vision(HIC"戴上了銀鷹頭盔後，一股神聖的力量籠罩了$N。\n"NOR,me);
    set_heart_beat(1);
    if( me && !me->query_temp("wear_silver_hawk") )
    {
      if(me->query("class")=="blademan")  me->add_temp("apply/blade", 10);
      if(me->query("class")=="fighter")   me->add_temp("apply/unarmed",10);
      if(me->query("class")=="swordsman") me->add_temp("apply/sword",10);
      if(me->query("class")=="scholar")   me->add_temp("apply/stabber",10);
      if(me->query("class")=="bandit")    me->add_temp("apply/unarmed",10);
      if(me->query("class")=="marksman")  me->add_temp("apply/archery", 10);
      if(me->query("class")=="prayer")    me->add_temp("apply/unarmed",10);
      if(me->query("class")=="poisoner")  me->add_temp("apply/whip",10);
      if(me->query("class")=="taoist")    me->add_temp("apply/whip",10);
      if(me->query("class")=="killer")    me->add_temp("apply/dagger",10);
      if(me->query("class")=="doctor")    me->add_temp("apply/stabber", 10);
      if(me->query("class")=="bonze")     me->add_temp("apply/unarmed",10);
      if(me->query("class")=="officer")   me->add_temp("apply/dagger",10);
      if(me->query("class")=="dancer")    me->add_temp("apply/unarmed",10);
      me->set_temp("wear_silver_hawk",1);
      me->set_temp("thunder",100);
    }
  }
  return result;
}

int unequip()
{
  object me=environment();
  int result = ::unequip();
  if( !query("equipped") )
  {
//    message_vision(HIC"$N脫下了銀鷹頭盔神聖的力量隨之離去。\n"NOR,me);
    set_heart_beat(0);
    if( me && me->query_temp("wear_silver_hawk") == 1 )
    {
      if(me->query("class")=="blademan")  me->add_temp("apply/blade", -10);
      if(me->query("class")=="fighter")   me->add_temp("apply/unarmed",-10);
      if(me->query("class")=="swordsman") me->add_temp("apply/sword",-10);
      if(me->query("class")=="scholar")   me->add_temp("apply/stabber",-10);
      if(me->query("class")=="bandit")    me->add_temp("apply/unarmed",-10);
      if(me->query("class")=="marksman")  me->add_temp("apply/archery", -10);
      if(me->query("class")=="prayer")    me->add_temp("apply/unarmed",-10);
      if(me->query("class")=="poisoner")  me->add_temp("apply/whip",-10);
      if(me->query("class")=="taoist")    me->add_temp("apply/whip",-10);
      if(me->query("class")=="killer")    me->add_temp("apply/dagger",-10);
      if(me->query("class")=="doctor")    me->add_temp("apply/stabber", -10);
      if(me->query("class")=="bonze")     me->add_temp("apply/unarmed",-10);
      if(me->query("class")=="officer")   me->add_temp("apply/dagger",-10);
      if(me->query("class")=="dancer")    me->add_temp("apply/unarmed",-10);
      me->delete_temp("wear_silver_hawk");
      me->delete_temp("thunder");
    }
  }
  return result;
}

void heart_beat()
{
  object me=environment();
  int rate,cor,con,kar,itt,spi,cps,mexp;
  int ekee=me->query("max_kee",1);
  if( !objectp(me) ) {
    set_heart_beat(0);
    return;
  }
  kar = me->query_kar(1);
  con = me->query_con(1);
  cps = me->query_cps(1);
  spi = me->query_spi(1);
  itt = me->query_int(1);
  mexp = me->query("combat_exp")/1000000;
  rate = con+spi+kar+itt+mexp;
  if( me->is_fighting() && query("equipped") && me->query("eff_kee") < ekee)
  {
    if( random(rate) > 65)
    {
      me->receive_curing("kee",(me->query("max_force"))/20);
      me->receive_heal("kee",(me->query("max_force"))/20);
      message_vision(HIW+"\n銀鷹頭盔散發出神聖的光輝，$N頓時覺的神清氣爽。\n"+NOR,me);
    }
  }
  return;
}
