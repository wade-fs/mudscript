//  段雲的武器
//修正wield && unwi時的顏色錯誤 by blazakira 2010/10/27
//將add("kee")調整為receive_damage的攻擊參數 且 更改使用者的判定為me = this_player()>>me = environment(this_object()) by blazakira 2011/4/16

#include <weapon.h>
#include <ansi.h>

inherit STABBER;
int timer,wait,limit;
object user;

void create()
{
//  object me=this_player();
  set_name(HIC + "飄雲扇" + NOR, ({"cloudy fan", "fan"}) );
  set_weight(12000);
  set("six_no_delay",1);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "柄");
    set("long","這是段家的傳家之寶, 握有此扇, 便是段家的傳人, 據說此扇在對敵時還有神奇的功\能喔。\n");
    set("value", 10000);
    set("material", "crimsonsteel");
  }
  init_stabber(100);
  setup();
}

void init()
{
  add_action("do_drop","drop");
  add_action("do_auc","auc");
//  add_action("do_wield","wield");
  add_action("do_give","give");
//  add_action("do_unwield","unwield");
}
/*
int do_wield(string str)
{
  ::wield();
  if( query("equipped") )
  {
    user = this_player();
    if(!user) user=environment();
    if(!user) return 0;
    if(user->query("marks/six_sp")==3 && user->query("family/family_name")=="段家"){
      message_vision(HIC + "$N將$n" + HIC + "握在手上，感覺到丹田中流入一股奇異的氣流。\n" + NOR,user,this_object());
      set_heart_beat(1);
    }
  }
}
*/
int wield()
{
  int result = ::wield();
  if( query("equipped"))
  {
    user = environment(this_object());
    if(user->query("marks/six_sp")==3 && user->query("family/family_name")=="段家"){
      message_vision(HIC + "$N將$n" + HIC + "握在手上，感覺到丹田中流入一股奇異的氣流。\n" + NOR,user,this_object());
      set_heart_beat(1);
    }
  }
  return result;
}
/*
int do_unwield(string str)
{
  if(str=="cloudy fan" || str=="fan" || str=="all")
  if( query("equipped") )
  {
    if(user)
      message_vision(HIC + "$N將$n" + HIC + "收起, 隨意的插在腰間。\n" + NOR,user,this_object());
    set_heart_beat(0);
  }
}
*/
int unequip()
{
  int result = ::unequip();
  if( query("equipped"))
  {
    user = environment(this_object());
    message_vision(HIC + "$N將$n" + HIC + "收起, 隨意的插在腰間。\n" + NOR,user,this_object());
    set_heart_beat(0);
  }
  return result;
}

int do_drop(string str)
{
  if(str=="cloudy fan" || str=="fan" || str=="all")
  if( query("equipped") )
  {
    message_vision(HIC + "$N將$n" + HIC + "收起, 隨意的插在腰間。\n" + NOR,user,this_object());
    set_heart_beat(0);
  }
}

int do_give(string str)
{
  if(str=="cloudy fan" || str=="fan" || str=="all")
  if( query("equipped") )
  {
    message_vision(HIC + "$N將$n" + HIC + "收起, 隨意的插在腰間。\n" + NOR,user,this_object());
    set_heart_beat(0);
  }
}

int do_auc(string str)
{
  if(str=="cloudy fan" || str=="fan" || str=="all")
  if( query("equipped") )
  {
    message_vision(HIC + "$N將$n" + HIC + "收起, 隨意的插在腰間。\n" + NOR,user,this_object());
    set_heart_beat(0);
  }
}

void heart_beat()
{
  object *enemy,weapon;
  int i,j,force_level,hurt,k,stat,be,fun,power;
  user = environment(this_object());
//  if(!user) user=this_player();
//  if(!user) user=previous_object();
  if(!user) return ;
  be = user->query("bellicosity",1);
//加入發出的時間性,由swy反應出現率太高故以發出後過10次heart_beat來延長其時間by bss
//由玩家反應殺氣高的意義已經不存在,所以調整為殺氣高的話可以等的少一點
  if(be<3000 && be>=2000) limit=6;
  if(be<2000 && be>=1000) limit=8;
  if(be<1000) limit=10;
  if(be>3000 || user->query("six_spsp")) limit=4;
  if(user->query("six_spsp") && user->query("env/quick_fan")) limit=2;
  if(wizardp(user) && user->query("env/quick_fan")) limit=2;
//這行是給wiz看的
  if(wizardp(user)) printf("limit=%d\n",limit);
  if(wait)
  {
    timer=timer+1;
    if(timer>=limit)
    {
      timer=0;
      wait=0;
    }
    else
    {
     return;
    }
  }
  if(be > 3000) be=3000;
  be=be/50;
  if(user->query("six_spsp")) be=60;
  if(wizardp(user)) be=80;
  if(user->is_busy()) be=0;
  k = user->query_int();
  if(user->query_skill_mapped("force")=="sunforce")
  {
    force_level=user->query_skill("sunforce",1);
    stat=0;
  }
  else
  {
    force_level=user->query_skill("sunforce",1);
    stat=1;
  }
  if(!stat)
  {
    hurt=force_level+((random(6)+k)*20);
  }
  else
  {
    hurt=force_level+((random(6)+k)*20);
    hurt=hurt/2;
  }
  if(user->query("env/quick_fan")) hurt=1000+random(10000)+hurt;
  if ( !objectp(user) )
  {
    set_heart_beat(0);
    return;
  }
  if(user->query("env/quick_fan")) be=80;
  power=1;
  weapon=user->query_temp("secondary_weapon");
  if(weapon){
    if(weapon->query("finger-fan",1)){ //左手拿的是飄陽扇
      fun=user->query("functions/fan-finger/level");
      if(fun >= 100){
        hurt=hurt*2;
        power=2;
      }
    }
  }
  if( user->is_fighting() && query("equipped") && user->query("marks/six_sp")==3 && user->query("family/family_name")=="段家")
  {
    if( be > random(100) && user->query("force") > 500 && !wait)
    {
      wait=1;
      enemy=user->query_enemy();
      j=sizeof(enemy);
      if(j>4) j=4;
      message_vision("

    " + HIM + "$N忽然從$n" + HIM + "感覺到一股奇怪的氣流流入腦中

      " + HIY + "煞那間領悟到了大理段氏的絕招" + BLINK+HIR + "『浴  火  鳳  凰』" + NOR + "

       " + HIG + "身體化作一隻巨大的" + HIR + "火鳳凰" + HIG + ", 朝敵人攻去
" + HIR + "
  :           .
   ::          :   :
   :::.        :: ::
   ::" + HIY + "*" + HIR + ":.
   ::::::.       :::.::: ::
   ::`:`: `.       :::.:::.:::  :
   ::    `  `     ::::::::.:::.::
   :::.        .::::::::::::.:::  :
   ::::.     .::::::::::::::::: :'            ::
   ::::::.  ..::::::::::::::::::.::  .          .
   ::::::::::::::::::::::::::::::::::::'          ::
   :::::::::::::::::::::::::::::::::..          .::
   ::::::::::::::::::::.::::::.      .::::::.      .::'
   `:::::::::::::::::::::.          `::::::::::'
    :::::::::::::::.   `      .:::::::::.
    :`::::::::::::::::.  .::::::::.    `::::::.
    :  `:::::::::::::::::::::   `::::::.      `::::.
    ::   `::::::::::::'         `::::.    ``::.   ::'
    ` :.                `::::. .      :: .


\n" + NOR,user,this_object());

      for(i=0;i<j;i++)
      {
        if(!enemy[i]) continue;
        if(95 > random(100) || enemy[i]->is_busy())  //因出現率少了,所以命中率就多了by bss
        {
          message_vision(HIY + "$N慘被" + HIR + "火鳳凰" + HIY + "所擊中, 造成了嚴重的灼傷。\n" + NOR,enemy[i]);
//          enemy[i]->add("kee",-(hurt));
          enemy[i]->receive_damage("kee",hurt,user);
          enemy[i]->start_busy(1*power);
          enemy[i]->apply_condition("burn",random(10)*power);
          COMBAT_D->report_status(enemy[i],0);
        }
        else
        {
          message_vision(HIW + "$N猛運護體勁氣,在身體四週佈起一道氣牆,剛好的抵禦住了" + HIR + "火鳳凰" + HIW + "的侵襲。\n" + NOR,enemy[i]);
          COMBAT_D->report_status(enemy[i], 0);
        }
      }
      user->add("force",-300);
    }
  }
  return;
}
