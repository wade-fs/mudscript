// ph_hat.c
//附註：取消原先的心跳增加天賦的判定 改為裝備時 就依條件給予對應的天賦
//並改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20

#include <ansi.h>
#include <armor.h>
inherit EQUIP;

void create()
{
  set_name(HIB + "閻"+HIY + "月"+HIW + "披風" + NOR,({"Dark Moon Cloak","cloak"}));
  set_weight(3000);
  set("armor_type","cape");
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "件");
    set("value",100000);
    set("material","silk");
    set("armor_prop/armor",10);
    set("armor_prop/force",7);
    set("armor_prop/move",7);
    set("armor_prop/dodge",9);
    set("armor_prop/attack",8);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1);
    set("wear_msg",HIM + "從$n" + HIM + "裡，隱隱發出陣陣涼意。\n" + NOR+HIB + "$N" + HIB + "以夜之一族慣有的沉靜掃視四週，$N" + HIB + "的定性增加了!!\n" + NOR);
    set("unequip_msg",HIB + "夜之氣息隨著閻月披風的卸下而消失。\n" + NOR);
  }
  setup();
}

int query_autoload()
{
  return 1;
}

int wear()
{
  object me;
  int k,result = ::wear();
  if( query("equipped"))
  {
    me=environment();
    if(me->query("origional_cps")) { //先恢復原先的天賦
      me->set("cps",me->query("origional_cps"));
      me->delete("origional_cps");
    }
//    message_vision(HIM + "從$n" + HIM + "裡，隱隱發出陣陣涼意。\n" + NOR,me,this_object());
//    message_vision(HIB + "$N以夜之一族慣有的沉靜掃視四週，$N的定性增加了!!\n" + NOR,me);
    k = (me->query("combat_exp"))/1000000;
    if( me->query("combat_exp") > 245000000 )
    k = 245+(me->query("combat_exp")-245000000)/5000000;
//    me->set("origional_cps",me->query_cps());
//    if(me->query("setgift-mk"))
//      me->set("origional_cps",me->query("setgift/cps"));

    if( !me->query("eq-mark/dark-moon-cloak") )
    {
      if( k > 35 )
        k=35;
    }
    if( me->query("eq-mark/dark-moon-cloak") == 1 )
    {
      if( k > 70 )
        k=70;
    }
    if( me->query("eq-mark/dark-moon-cloak") == 2 )
    {
      if( k > 105 )
        k=105;
      if( k < 35 )
        k=35;
    }
    if( me->query("eq-mark/dark-moon-cloak") == 3 )
    {
      if( k > 140 )
        k=140;
      if( k < 70 )
        k=70;
    }
    if( me->query("eq-mark/dark-moon-cloak") == 4 )
    {
      if( k > 175 )
        k=175;
      if( k < 70 )
        k=70;
    }
    if( me->query("eq-mark/dark-moon-cloak") == 5 )
    {
      if( k > 210 )
        k=210;
      if( k < 105 )
        k=105;
    }
    if( me->query("eq-mark/dark-moon-cloak") == 6 )
    {
      if( k > 245 )
        k=245;
      if( k < 105 )
        k=105;
    }
    if(!me->query_temp("apply/cps_dark_moon_cloak")) //避免暈倒後再呼叫wear()函數導致天賦不斷累計
    {
      me->set_temp("apply/cps_dark_moon_cloak",k);
      me->add_temp("apply/cps",k);
    }

    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  object me=environment();
  int result = ::unequip();
  if( !query("equipped") )
  {
//    message_vision(HIB + "夜之氣息隨著閻月披風的卸下而消失。\n" + NOR,me);
    me->delete("cloak_add_gift");
    if(me->query_temp("apply/cps_dark_moon_cloak")) {
      me->add_temp("apply/cps",-me->query_temp("apply/cps_dark_moon_cloak"));
      me->delete_temp("apply/cps_dark_moon_cloak");
    }
  }
  return result;
}

void heart_beat()
{
  object me=environment();
  int karsw,cps,kar;
  if( !objectp(me) || !query("equipped") ) {
    set_heart_beat(0);
    return;
  }
  cps = me->query_cps(1);
  kar = me->query_kar(1);
  if (!me->query_temp("apply/kar_legging_add_gift"))
    karsw =20;
  else
    karsw =35;

  if(this_object()->query("equipped"))
  {  
    if(me->is_fighting() && random(cps+kar) < karsw )
    {
      if( me->query("atman") > (me->query("max_atman")/2) ) me->add("atman",-2);
      if( me->query("force") > (me->query("max_force")/2) ) me->add("force",-2);
      if( me->query("mana")  > (me->query("max_mana")/2)  ) me->add("mana",-2);
    }
  }
  else
  {
    set_heart_beat(0);
  }
}
