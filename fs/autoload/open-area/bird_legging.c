// kame_suit.c
//附註：取消原先的心跳增加天賦的判定 改為裝備時 就依條件給予對應的天賦
//並改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20

#include <ansi.h>
inherit EQUIP;

void create()
{
  set_name(HIR + "火鳥" + HIW + "脛甲" + NOR,({"fire bird leggings","leggings"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","用不死鳥之聖軀製作而成的奇異之甲。\n");
    set("unit","件");
    set("value",150000);
    set("material","silk");
    set("armor_type","leggings");
    set("armor_prop/armor", 10);
    set("armor_prop/dodge",9);
    set("armor_prop/parry",5);
    set("armor_prop/attack",5);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1); 
    set("wear_msg","$n" + HIM + "燃起一道火焰，五光十色甚是眩麗。\n" + NOR+HIY + "$N" + HIY + "像不死鳥般沐浴於奇蹟之焰中，$N" + HIY + "的福緣增加了!!\n" + NOR);
    set("unequip_msg",HIY + "奇蹟之焰逐漸熄滅...\n" + NOR);
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
    if(me->query("origional_kar")) { //先恢復原先的天賦
      me->set("kar",me->query("origional_kar"));
      me->delete("origional_kar");
    }
//    message_vision("$n" + HIM + "燃起一道火焰，五光十色甚是眩麗。\n" + NOR,me,this_object());
//    message_vision(HIY + "$N像不死鳥般沐浴於奇蹟之焰中，$N的福緣增加了!!\n" + NOR,me);
    k = (me->query("combat_exp"))/1000000;
    if( me->query("combat_exp") > 245000000 )
    k = 245+(me->query("combat_exp")-245000000)/5000000;
//    me->set("origional_kar",me->query("kar"));
//    if(me->query("setgift-mk"))
//      me->set("origional_kar",me->query("setgift/kar"));

    if( !me->query("eq-mark/bird-legging") )
    {
      if( k > 35 )
        k=35;
    }
    if( me->query("eq-mark/bird-legging") == 1 )
    {
      if( k > 70 )
        k=70;
    }
    if( me->query("eq-mark/bird-legging") == 2 )
    {
      if( k > 105 )
        k=105;
      if( k < 35 )
        k=35;
    }
    if( me->query("eq-mark/bird-legging") == 3 )
    {
      if( k > 140 )
        k=140;
      if( k < 70 )
        k=70;
    }
    if( me->query("eq-mark/bird-legging") == 4 )
    {
      if( k > 175 )
        k=175;
      if( k < 70 )
        k=70;
    }
    if( me->query("eq-mark/bird-legging") == 5 )
    {
      if( k > 210 )
        k=210;
      if( k < 105 )
        k=105;
    }
    if( me->query("eq-mark/bird-legging") == 6 )
    {
      if( k > 245 )
        k=245;
      if( k < 105 )
        k=105;
    }
    if(!me->query_temp("apply/kar_fire_bird_leggings")) //避免暈倒後再呼叫wear()函數導致天賦不斷累計
    {
      me->set_temp("apply/kar_fire_bird_leggings",k);
      me->add_temp("apply/kar",k);
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
//    message_vision(HIY + "奇蹟之焰逐漸熄滅...\n" + NOR,me);
    me->delete("legging_add_gift");
    if(me->query_temp("apply/kar_fire_bird_leggings")) {
      me->add_temp("apply/kar",-me->query_temp("apply/kar_fire_bird_leggings"));
      me->delete_temp("apply/kar_fire_bird_leggings");
    }
  }
  return result;
}

void heart_beat()
{
  object me=environment();
  int karsw,kar;
  if( !objectp(me) || !query("equipped") ) {
    set_heart_beat(0);
    return;
  }
  kar = me->query_kar(1);
  if (!me->query_temp("apply/kar_legging_add_gift"))
    karsw =15;
  else
    karsw =30;

  if(this_object()->query("equipped"))
  {  
    if(me->is_fighting() && random(kar+kar) < karsw )
    {
      if( me->query("food") > 100 )
      {
        me->add("food",-1);
      }
    }
  }
  else
  {
    set_heart_beat(0);
  }
}
