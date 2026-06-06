// made by ccat
// 二版,改正以往須call 一個隱形怪獸的缺點,使用的變數也大為簡化.
//改變wear形式為int wear() (參考殺意魔戒) 並補上持有者昏倒之後就不發動的判斷 by blazakira 2011/8/26

#include <ansi.h>
#include <armor.h>
inherit EQUIP;
inherit SSERVER;

void create()
{
  set_name( "冰雪神戒",({"ice_ring"}) );
  set_weight(2500);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long","一只產於北海的神奇藍寶石指戒，閃爍著詭異的藍光。\n");
    set("unit", "件");
    set("value",5000);
    set("material","steal");
    set("no_sell", 1); //不然就得多攔 action sell
    set("armor_type","finger");
    set("armor_prop/armor",7);
    set("wear_msg","$N戴上了$n，四周亮起了淡淡藍光。\n");
    set("unequip_msg","$N脫下了$n，$n奇異的藍光也隨之消逝。\n");
  }
  setup();
}
/*
void init()
{
  add_action("do_drop","drop"); 
  add_action("do_auc","auc"); 
  add_action("do_wear","wear");
  add_action("do_give","give");
  add_action("do_remove","remove");
}

int do_wear(string str)
{ 
  ::wear();
  if ( query("equipped") )
  {
    user = this_player(); // 取得使用者
    kar = user->query_kar();
    message_vision("$N戴上了冰雪神戒,四周亮起了淡淡藍光.\n",user);
    set_heart_beat(1);
  }
}

int do_drop(string str)
{
  if (str=="ice_ring" || str=="all")
    if( query("equipped") )
    {
      message_vision("$N脫下了冰雪神戒,冰雪神戒奇異的藍光也隨之消逝.\n",user);
      set_heart_beat(0);
    }
}

int do_give(string str)
{
  if (str=="ice_ring" || str=="all")
  if( query("equipped") )
  {
     message_vision("$N脫下了冰雪神戒,冰雪神戒奇異的藍光也隨之消逝.\n",user); 
     set_heart_beat(0);
  }
}

int do_remove(string str)
{
  if (str=="ice_ring" || str=="all")
    if( query("equipped") )
    {
      if(user)
        message_vision("$N脫下了冰雪神戒,冰雪神戒奇異的藍光也隨之消逝.\n",user);
      set_heart_beat(0);
    }
}

int do_auc(string str)
{
  if (str=="ice_ring" || str=="all")
    if( query("equipped") )
    {
      message_vision("$N脫下了冰雪神戒,冰雪神戒奇異的藍光也隨之消逝.\n",user);
      set_heart_beat(0);
    }
}
*/
void heart_beat()
{
  object *enemy,who,target,user,me=this_object();
  int i,dodge,kar;
  user = environment(me);
  if( !me || !user || !objectp(user) || !query("equipped") )
  {
    set_heart_beat(0);
    return;
  }
  if( user->is_fighting() && user->query_temp("unconcious") != 1 )
  {
    if( random(kar+70) > 70) // 運氣高,機率高
    {
      enemy=user->query_enemy();
      i=random(sizeof(enemy));
      target=offensive_target(user);
      if(!target) {
        return ;
      }
      dodge = target->query_skill("dodge");
      if( random(180) > dodge) 
      {
        message_vision(HIC+"一陣寒風自冰雪神戒捲出，瞬間把$N凍結了!!!\n"+NOR,target);
        target->start_busy(2);
      } else {
        message_vision(HIC+"一陣寒風自冰雪神戒捲出，但見$N隨風一擺\，躲過了去...\n"+NOR,target);
      }
    }
  }
  return;
}
