//附註：取消原先的心跳增加天賦的判定 改為裝備時 就依條件給予對應的天賦
//並改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/7/20

#include <ansi.h>
inherit EQUIP;

void create()
{
  set_name(HIR + "赤"+HIG + "麟"+HIC + "肩甲" + NOR,({"Red chilin armband","armband"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","當年綠毛老祖大戰赤燄麒麟七七四十九天，從赤燄麒麟身上的鱗片所提煉而成。");
    set("unit","個");
    set("value",1750);
    set("material","crimsonsteel");
    set("armor_type","armbands");
    set("armor_prop/armor",10);
    set("armor_prop/unarmed", 10);
    set("armor_prop/dodge", 10);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_steal",1);
    set("no_save",1); 
    set("wear_msg","$n" + HIM + "不住的震動，彷彿期待即將來臨的戰鬥...\n" + NOR+HIR + "赤麟凶性引發了$N" + HIR + "的鬥心，$N" + HIR + "的膽識增加了!!\n" + NOR);
    set("unequip_msg",HIR + "赤麟的獸性逐漸平息下來!!\n" + NOR);
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
    if(me->query("origional_cor")) { //先恢復原先的天賦
      me->set("cor",me->query("origional_cor"));
      me->delete("origional_cor");
    }
//    message_vision("$n" + HIM + "不住的震動，彷彿期待即將來臨的戰鬥...\n" + NOR,me,this_object());
//    message_vision(HIR + "赤麟凶性引發了$N的鬥心，$N的膽識增加了!!\n" + NOR,me);
    k = (me->query("combat_exp"))/1000000;
    if( me->query("combat_exp") > 245000000 )
      k = 245+(me->query("combat_exp")-245000000)/5000000;

//    me->set("origional_cor",me->query_cor(1));
//    if(me->query("setgift-mk"))
//      me->set("origional_cor",me->query("setgift/cor"));

    if( !me->query("eq-mark/red-chilin-armband") )
    {
      if( k > 35 )
        k=35;
    }
    if( me->query("eq-mark/red-chilin-armband") == 1 )
    {
      if( k > 70 )
        k=70;
    }
    if( me->query("eq-mark/red-chilin-armband") == 2 )
    {
      if( k > 105 )
        k=105;
      if( k < 35 )
        k=35;
    }
    if( me->query("eq-mark/red-chilin-armband") == 3 )
    {
      if( k > 140 )
        k=140;
      if( k < 70 )
        k=70;
    }
    if( me->query("eq-mark/red-chilin-armband") == 4 )
    {
      if( k > 175 )
        k=175;
      if( k < 70 )
        k=70;
    }
    if( me->query("eq-mark/red-chilin-armband") == 5 )
    {
      if( k > 210 )
        k=210;
      if( k < 105 )
        k=105;
    }
    if( me->query("eq-mark/red-chilin-armband") == 6 )
    {
      if( k > 245 )
        k=245;
      if( k < 105 )
        k=105;
    }
    if(!me->query_temp("apply/cor_red_chilin_armband")) //避免暈倒後再呼叫wear()函數導致天賦不斷累計
    {
      me->set_temp("apply/cor_red_chilin_armband",k);
      me->add_temp("apply/cor",k);
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
//    message_vision(HIR + "赤麟的獸性逐漸平息下來!!\n" + NOR,me);
    me->delete("armband_add_gift");
    if(me->query_temp("apply/cor_red_chilin_armband")) {
      me->add_temp("apply/cor",-me->query_temp("apply/cor_red_chilin_armband"));
      me->delete_temp("apply/cor_red_chilin_armband");
    }
  }
  return result;
}

void heart_beat()
{
  object me=environment();
  int karsw,cor,kar;
  if( !objectp(me) || !query("equipped") ) {
    set_heart_beat(0);
    return;
  }
  cor = me->query_cor(1);
  kar = me->query_kar(1);
  if (!me->query_temp("apply/kar_fire_bird_leggings"))
    karsw =15;
  else
    karsw =30;

  if(this_object()->query("equipped"))
  {  
    if(me->is_fighting() && random(cor+kar) < karsw )
    {
      if( me->query("water") > 100 )
      {
        me->add("water",-1);
      }
    }
  }
  else
  {
    set_heart_beat(0);
  }
}
