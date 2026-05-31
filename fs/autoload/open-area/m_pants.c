//目前暫未開放的eq 但是已為玩家所獲得 因此改為apply的判斷以避開與另一件戰功eq的疊加導致天賦無限疊加的bug by blazakira 2011/6/24
//改變wear形式為int wear() (參考殺意魔戒) by blazakira 2011/10/11

#include <ansi.h>
inherit EQUIP;

void create()
{
/*
  if (me->query("gender")=="男性")
    set_name(HIM"風雅"HIW"紳褲"NOR,({"magical pants","pants"}));
  if (me->query("gender")=="女性")
    set_name(HIM"誘惑"HIW"飄裙"NOR,({"magical skirt","skirt"}));
  if (me->query("gender")=="女性")
    set("long","傳聞中樹妖舞風揚和花精淡情悠身上之物。");
  if (me->query("gender")=="男性")
    set("long","傳聞中英雄真經傳人木無言身上之物。");
*/
  set_name(HIM"誘惑"HIW"飄裙"NOR,({"magical skirt","skirt"}));
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","傳聞中樹妖舞風揚和花精淡情悠身上之物。");
    set("unit","件");
    set("value",1750);
    set("material","crimsonsteel");
    set("armor_type","pants");
    set("armor_prop/armor",10);
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
  }
  setup();
}

int query_autoload()
{
  return 1;
}

void init()
{
  object me;
  me=environment();
  if (me->query("gender")=="男性") {
    set_name(HIM"風雅"HIW"紳褲"NOR,({"magical pants","pants"}));
    set("long","傳聞中英雄真經傳人木無言身上之物。");
    set("wear_msg","$n"HIM"發出異樣的光芒，$N"HIM"彷彿換了一個人似的。\n"NOR);
    set("unequip_msg","$N"HIM"脫下了$n"HIM"恢復往昔的樣貌。\n"NOR);
  }
  if (me->query("gender")=="女性") {
    set_name(HIM"誘惑"HIW"飄裙"NOR,({"magical skirt","skirt"}));
    set("long","傳聞中樹妖舞風揚和花精淡情悠身上之物。");
    set("wear_msg","$n"HIM"發出異樣的光芒，$N"HIM"彷彿回到十八歲似的。\n"NOR);
    set("unequip_msg","$N"HIM"脫下了$n"HIM"恢復往昔的樣貌。\n"NOR);
  }
//  add_action("do_wear","wear");
}

int wear()
{
  int result = ::wear();
  if( query("equipped"))
  {
    set_heart_beat(1);
  }
  return result;
}

int unequip()
{
  int result = ::unequip();
  if( !query("equipped") )
  {
    set_heart_beat(0);
  }
  return result;
}
/*
int do_wear(string str)
{
  if (me->query("gender")=="男性")
  {
    if(str=="all" || str=="pants" || str=="magical pants" )
    {
      ::wear();
      if(!me) me=environment();
      if(!living(me)) me=this_player();
      if(!me) me=previous_object();
      if( query("equipped") )
      {
        set_heart_beat(1);
        message_vision(HIW"風雅紳褲"HIM"發出異樣的光芒，$N彷彿換了一個人似的。\n"NOR,me);
      }
    }
  }

  if (me->query("gender")=="女性")
  {
    if(str=="all" || str=="skirt" || str=="magical skirt" )
    {
      ::wear();
      if(!me) me=environment();
      if(!living(me)) me=this_player();
      if(!me) me=previous_object();
      if( query("equipped") )
      {
        set_heart_beat(1);
        message_vision(HIW"誘惑飄裙"HIM"發出異樣的光芒，$N彷彿回到十八歲似的。\n"NOR,me);  
      }
    }
  }
}
*/
void heart_beat()
{
  object me=environment();
  int k;
  if( !this_object() || !me ) return;
  k = (me->query("combat_exp"))/2000000;

  if(this_object()->query("equipped"))
  {  
    if(!me->query("pants_add_gift"))
    {
      message_vision(HIM"神奇的光芒籠罩著$N全身上下，$N的容貌增加了!!\n"NOR,me);
      me->set("pants_add_gift",1);
//      me->set("origional_per",me->query_per());
//      me->add("per",k);
      me->set("origional_per",10); //因為未開放 因此使用bug入手的不知情玩家 恢復容貌為原始值10 by blazakira
      me->add_temp("apply/per",k); //有例外的就請他提出說明 如何入手此裝備與天賦超過10的證據吧（笑 by blazakira
    }
  }
  else
  {
    if(me->query("pants_add_gift"))
    {
      message_vision(HIM"神奇的光芒逐漸消退，$N又變回自己了!!\n"NOR,me);
      me->delete("pants_add_gift");
      me->set("per",10);
      me->add_temp("apply/per",-k);
    }
    set_heart_beat(0);
  }
}
