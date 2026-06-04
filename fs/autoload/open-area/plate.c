//附註：取消原先的心跳增加天賦的判定 改為裝備時 就依條件給予對應的天賦
//並改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20

#include <ansi.h>
inherit SSERVER;
inherit EQUIP;

void create()
{
  set_name(HIW + "聖靈戰甲" + NOR,({"Holy Ghost Plate","plate"}) );
  set_weight(5000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("meterial","crimsonsteel");
    set("armor_type","cloth");
    set("unit","件");
    set("value", 100000);
    set("armor_prop/armor", 50);
    set("armor_prop/parry", 12);
    set("armor_prop/magic", 8);
    set("armor_prop/spells", 8);
    set("armor_prop/attack", 5);
    set("armor_prop/force", 5);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1); 
    set("long","
這套戰甲是由波斯王國所製，受過波斯勇者鮮血的灌溉，上下都散發出
一股霸氣，據說穿上之人可以橫掃戰場，所向披靡。\n");
    set("wear_msg","$n" + HIM + "內傳出一陣聖潔的天音...\n" + NOR+HIW + "聖靈的力量源源不斷湧入$N" + HIW + "內心，$N" + HIW + "的靈性增加了!!\n" + NOR);
    set("unequip_msg",HIW + "靈氣逐漸回歸聖靈戰甲!!\n" + NOR);
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
    if(me->query("origional_spi")) { //先恢復原先的天賦
      me->set("spi",me->query("origional_spi"));
      me->delete("origional_spi");
    }
//    message_vision("$n" + HIM + "內傳出一陣聖潔的天音...\n" + NOR,me,this_object());
//    message_vision(HIW + "聖靈的力量源源不斷湧入$N內心，$N的靈性增加了!!\n" + NOR,me);
    k = (me->query("combat_exp"))/1000000;
    if( me->query("combat_exp") > 245000000 )
      k = 245+(me->query("combat_exp")-245000000)/5000000;

//    me->set("origional_per",me->query_per(1));
//    if(me->query("setgift-mk"))
//      me->set("origional_spi",me->query("setgift/spi"));

    if( !me->query("eq-mark/holy-ghost-plate") )
    {
      if( k > 35 )
        k=35;
    }
    if( me->query("eq-mark/holy-ghost-plate") == 1 )
    {
      if( k > 70 )
        k=70;
    }
    if( me->query("eq-mark/holy-ghost-plate") == 2 )
    {
      if( k > 105 )
        k=105;
      if( k < 35 )
        k=35;
    }
    if( me->query("eq-mark/holy-ghost-plate") == 3 )
    {
      if( k > 140 )
        k=140;
      if( k < 70 )
        k=70;
    }
    if( me->query("eq-mark/holy-ghost-plate") == 4 )
    {
      if( k > 175 )
        k=175;
      if( k < 70 )
        k=70;
    }
    if( me->query("eq-mark/holy-ghost-plate") == 5 )
    {
      if( k > 210 )
        k=210;
      if( k < 105 )
        k=105;
    }
    if( me->query("eq-mark/holy-ghost-plate") == 6 )
    {
      if( k > 245 )
        k=245;
      if( k < 105 )
        k=105;
    }
    if(!me->query_temp("apply/spi_holy_ghost_plate")) //避免暈倒後再呼叫wear()函數導致天賦不斷累計
    {
      me->set_temp("apply/spi_holy_ghost_plate",k);
      me->add_temp("apply/spi",k);
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
//    message_vision(HIW + "靈氣逐漸回歸聖靈戰甲!!\n" + NOR,me);
    me->delete("plate_add_gift");
    if(me->query_temp("apply/spi_holy_ghost_plate")) {
      me->add_temp("apply/spi",-me->query_temp("apply/spi_holy_ghost_plate"));
      me->delete_temp("apply/spi_holy_ghost_plate");
    }
  }
  return result;
}

void heart_beat()
{
  object me=environment();
  int karsw,spi,kar;
  if( !objectp(me) || !query("equipped") ) {
    set_heart_beat(0);
    return;
  }
  spi = me->query_spi(1);
  kar = me->query_kar(1);
  if (!me->query_temp("apply/kar_fire_bird_leggings"))
    karsw =20;
  else
    karsw =35;

  if(this_object()->query("equipped"))
  {  
    if(me->is_fighting() && random(spi+kar) < karsw )
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
