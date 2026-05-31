//會與另一件增加per的裝備疊加效果以至於重置原始天賦為35up(大多玩家原始值為10) 因此改為apply的判斷以避開 by blazakira 2011/6/25
//附註：取消原先的心跳增加天賦的判定 改為裝備時 就依條件給予對應的天賦 by blazakira

#include <ansi.h>
inherit EQUIP;

void create()
{
  set_name(HIC"神喻"HIW"腰帶"NOR,({"divine belt","belt"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","女媧補天過程中不小心遺留在這世間的神物，傳聞此物具有美化人心的效果。\n");
    set("unit","條");
    set("value",1750);
    set("material","crimsonsteel");
    set("armor_type","waist");
    set("armor_prop/armor",15);
    set("armor_prop/dodge",10);
    set("armor_prop/move",10);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1);
    set("wear_msg","$n"HIM"發出神奇的光芒。\n"NOR+HIM"神奇的光芒籠罩著$N"HIM"全身上下，$N"HIM"的容貌增加了!!\n"NOR);
    set("unequip_msg",HIM"神奇的光芒逐漸消退，$N"HIM"又變回自己了!!\n"NOR);
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
    if(me->query("origional_per")) { //先恢復原先的天賦
      me->set("per",me->query("origional_per"));
      me->delete("origional_per");
    }
//    message_vision("$n"HIM"發出神奇的光芒。\n"NOR,me,this_object());
    k = (me->query("combat_exp"))/2000000;

    if( me->query("combat_exp") > 490000000 )
      k = 245+(me->query("combat_exp")-490000000)/5000000;

//    if(!me->query("belt_add_gift"))
    {
//      message_vision(HIM"神奇的光芒籠罩著$N全身上下，$N的容貌增加了!!\n"NOR,me);
//      me->set("belt_add_gift",1); //因為使用的是apply/per 所以應該不需要此mark來額外判定 畢竟apply增加在temp裡 離線就會清除 但目前保留是因為 有些玩家久未上線 仍持有這mark 可能會造成wiz判斷bug的困擾 所以保留 by blazakira
//      me->set("origional_per",me->query_per(1));
//    if(me->query("setgift-mk"))
//      me->set("origional_cor",me->query("setgift/cor"));

      if( !me->query("eq-mark/divine-belt") )
      {
        if( k > 35 )
          k=35;
      }
      if( me->query("eq-mark/divine-belt") == 1 )
      {
        if( k > 70 )
          k=70;
      }
      if( me->query("eq-mark/divine-belt") == 2 )
      {
        if( k > 105 )
          k=105;
        if( k < 35 )
          k=35;
      }
      if( me->query("eq-mark/divine-belt") == 3 )
      {
        if( k > 140 )
          k=140;
        if( k < 70 )
          k=70;
      }
      if( me->query("eq-mark/divine-belt") == 4 )
      {
        if( k > 175 )
          k=175;
        if( k < 70 )
          k=70;
      }
      if( me->query("eq-mark/divine-belt") == 5 )
      {
        if( k > 210 )
          k=210;
        if( k < 105 )
          k=105;
      }
      if( me->query("eq-mark/divine-belt") == 6 )
      {
        if( k > 245 )
          k=245;
        if( k < 105 )
          k=105;
      }
      if(!me->query_temp("apply/per_divine_belt")) //避免暈倒後再呼叫wear()函數導致天賦不斷累計
      {
        me->set_temp("apply/per_divine_belt",k);
        me->add_temp("apply/per",k);
      }
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
    if( !me ) me=environment();
//    message_vision(HIM"神奇的光芒逐漸消退，$N又變回自己了!!\n"NOR,me);
    me->delete("belt_add_gift");
    if(me->query_temp("apply/per_divine_belt")) {
      me->add_temp("apply/per",-me->query_temp("apply/per_divine_belt"));
      me->delete_temp("apply/per_divine_belt");
    }
  }
  return result;
}
