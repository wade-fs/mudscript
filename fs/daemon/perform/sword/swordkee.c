#include <combat.h>
#include <ansi.h>
inherit SSERVER;
inherit F_FUNCTION;
int perform(object me, object target)
{
   object *enemy,weapon;
   int damage,i,fun;
   object victim;
   victim=this_player()->enemy();
   enemy=me->query_enemy();
   i=sizeof(enemy);
   fun=me->query("functions/swordkee/level");
if(me->query("class") != "swordsman")
  return notify_fail("你的職業無法使出劍氣。\n");
if( me->query("force") < 250)
  return notify_fail("你的內力不夠。\n");
if( me->query_skill("sword",1) < 70 )
  return notify_fail("你的基本劍術太差了。\n");
if( !me->is_fighting() )
  return notify_fail("劍氣要戰鬥中才能使用。\n");
if(!objectp(weapon=me->query_temp("weapon")) || (string)weapon->query("skill_type")!="sword")
  return notify_fail("要有劍才能發劍氣。\n");
if(fun==100) 
 {
    message_vision(HIC"$N大喝一聲發出所有劍氣!!!\n\n"HIB"一招"HIR"劍氣"HIW"破敵"HIY"---"HIG"  『"HIR"石破天驚"HIG"』!!!\n\n"NOR,me);
damage=me->query_skill("sword",1)*7+random(200);
 }
else if(fun<=20) 
 {

message_vision("[1;30m$N將內力貫注在劍上﹐猛然一揮, 只揮出幾道零星的劍氣！[0m\n",me);
    damage=me->query_skill("sword",1);
 }
else if(fun<=40&&fun>=21) 
 {
    message_vision("[1;31m$N將內力貫注在劍上﹐猛然一揮﹐數道劍氣騰出, 並分擊在場各個敵人！[0m\n",me);
    damage=me->query_skill("sword",1)*3/2;
 }
else if(fun<=60&&fun>=41) 
 {
    message_vision("[1;34m$N將內力貫注在劍上﹐猛然一揮﹐數十道劍氣騰出，劍氣分別射向四面八方！[0m\n",me);
    damage=me->query_skill("sword",1)*2;
 }
else if(fun<=80&&fun>=61) 
 {
    message_vision("[1;32m$N將內力貫注在劍上﹐猛然一揮﹐只見一道耀眼的青銅劍氣騰出直逼在場所有生物！[0m\n",me);
    damage=me->query_skill("sword",1)*3;
 }
else if(fun>=81&&fun<=99) 
 {
    message_vision("[1;33m$N將內力貫注在劍上﹐猛然一揮﹐黃金劍氣頓時籠罩全身, 並向外擴散分擊各對手！[0m\n",me);
   damage=me->query_skill("sword",1)*4;
 }
  me->add("force",-50);
  me->start_busy(1);
  while(i--) {
  if(!me || !enemy[i]) continue;
if(environment(me)!=environment(enemy[i])) continue;   
    if(random(me->query_skill("sword"))*10>enemy[i]->query_skill("dodge")+enemy[i]->query_skill("parry"))
      {
        enemy[i]->receive_wound("kee",damage);
        message_vision(HIR"$N閃躲不及﹐劍氣已在其身上劃出一道血淋淋的傷痕！\n"NOR,enemy[i]);
        enemy[i]->start_busy(1);
        COMBAT_D->report_status(enemy[i],1);
      }
    else 
{
message_vision(YEL"$N側身一閃﹐避開了劍氣！\n"NOR,enemy[i]);
}
          }
if(fun<100) { function_improved("swordkee",random(300));}
return 1;
}

