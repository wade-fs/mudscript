//調整wield 遭遇屠龍刀這類會砍斷武器時所出現的wield函數錯誤 by blazakira 2010/12/9

#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
  set_name("魔氣匕", ({ "evil dagger","dagger" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "把");
    set("long", "這是一把由真˙黑牙神功\藉由體內鬥氣所形成的匕首。\n");
    set("value", 0);
    set("no_auc",1);
    set("no_sell",1);
    set("no_give",1);
    set("no_put",1);
    set("no_drop",1);
    set("no_get",1);
    set("no_save",1);
    set("material", "steel");
  }
  init_dagger(90);
  set("wield_msg", "$N從懷中摸出一把$n握在手中。\n");
  set("unwield_msg", "$N將手中的$n藏入懷中。\n");
  setup();
}

//mixed hit_ob( object me,object victim)
mixed hit_ob( object me, int damage)
{
  int fun,h,i;
  object weapon;
//  me=this_player();
  me=environment();
  fun=me->query("functions/make-dagger/level");
  h=me->query("darkforce/make_dag/exp");
  if (h>300) h=300;
  if(me->is_fighting() && query("equipped") && me->query("darkforce/make_dag/exp") > 0 && me->query("bellicosity") > 500
      && me->query("force") > 200 && me->query_temp("earthkill")!=1)
  {
    if(random(fun) > 70)
    {
      message_vision(HIC"\n$N"HIC"透過兵器將殺氣轉成體力！\n"NOR,me); //沒有扣對手的任一數值 所以改寫敘述為自身相關 by blazakira
      me->receive_curing("kee",h);
      me->receive_heal("kee",h);
      me->add("bellicosity", -50);
      if (me->query("force") < me->query("max_force")/2) {me->add("force",h);} //原設計竟然有回force呢 tsk
    }
  }
}

int wield()
{
/*
object me;
if(!me=this_player()) me=environment(this_object()); //blazakira的版本
魔女洋子(建彰： 說 (下午 09:00):
所以 我才會認為 this_player 抓不到
魚缸@台北 說 (下午 09:02):
改成environment()->query_skill ..應該就好了
*/
 if(environment()->query_skill("shadow-kill",1) > 0)
  return notify_fail("你必續放棄闇影匕首才能使用此裝備!!\n");
 else 
 {
  ::wield();
 }
 return 1;
}
