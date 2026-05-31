
#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;
void power(object me, object victim, object weapon, int damage);
void power1(object me, object victim, object weapon, int damage);
void power2(object me, object victim, object weapon, int damage);
mapping *action = ({
   ([
        "action":
"只見$N一步躍空,使出了"HIW"『白虎落山』"NOR",手中$w氣勢滂漙有開劈石之勢直向$n逼去",
        "dodge"      :                25,
        "parry"      :                25,
        "damage"     :                80,
        "force"      :                80,
        "damage_type":               "劈傷"
   ]),
  ([
        "action"     :
"$N身子緩緩打斜縱身躍出,藉由旋轉之勢,打出了"HIB"『惡蛟渡江』"NOR"強大的氣勁挾帶著滾滾風沙,$w宛如惡蛟般地兇猛,直撲$n而去",
        "dodge"      :                20,
        "parry"      :                20,
        "damage"     :                90,
        "force"      :                90,
        "damage_type":               "劈傷"
   ]),
  ([
        "action"     :
"$N神情從容,手裡$w心隨意轉,一轉眼已攻至$n眼前,$N才緩緩道出"HIR"『血燕歸巢』"NOR"這招名稱",
        "dodge"      :                15,
        "parry"      :                15,
        "damage"     :                 90,
        "force"      :                100,
        "damage_type":               "劈傷"
   ]),
  ([
        "action"     :
"$N大喝一聲,眼中充滿血光,霎那間腦海裡只有殺,一時間將山賊的本性完全顯露出來,手握$w無情地向$n砍殺,一招"HIC"『怒斬修羅』"NOR"連神也躲不過",
        "dodge"      :                10,
        "parry"      :                10,
        "damage"     :                100,
        "force"      :                100,
        "damage_type":               "劈傷"
   ]),
  ([
        "action"     :
"$N將手中$w一攔,以極快的手法向$n攻去,正是"HIG"『疾 狼 斬』"NOR"～",
         "dodge"      :                5,
         "parry"      :                5,
         "damage"     :                110,
         "force"      :                110,
         "damage_type":               "斬傷"
   ]),
([
         "action"     :
"$N運起全身勁力﹐勁貫$w﹐使出一招"BLINK+HIW"『袍丁宰牛』"NOR"$N以全身勁力砍向$n$l",
         "dodge"      :               -5,
         "parry"      :               -5,
         "damage"     :                130,
         "force"      :                130,
         "damage_type":               "斬傷"
   ]),
  ([
         "action"     :
"$N縱身躍起﹐行如影、快如風﹐一招"HIY"『金燕橫空』"NOR"﹐分別劈向$n四肢",
         "dodge"      :               -10,
         "parry"      :               -10,
         "damage"     :                140,
         "force"      :                140,
         "post_action":               (: power :),
         "damage_type":               "劈傷"
  ]),
([
         "action"     :
"$N運起全身功\力,氣集於$w使出一招"BLINK+HIR"『鬼氣貫腦』"NOR"斧勁極快的的波及到$n",
         "dodge"      :               -15,
         "parry"      :               -15,
         "damage"     :                150,
         "force"      :                150,
         "damage_type":               "劈傷"
   ]),
  ([
         "action"     :
"$N橫起$w﹐氣貫丹田、反轉$w﹐使出一招"HIR"『驚天狂龍破』"NOR"﹐$w的瑞氣朝$n身上四射過去",
         "dodge"      :               -20,
         "parry"      :               -20,
         "damage"     :                170,
         "force"      :                170,
         "post_action":               (: power :),
         "damage_type":               "割傷"
  ]),
  ([
         "action"     :
"$N舉起$w來﹐內力一提、勁貫雙手﹐頓時飛沙走石、狂風四起﹐$N使出一招"HIB"『擂鼓震山川』"NOR"﹐使出了前所未有的超爆狂力朝$n身上狂劈過去",
         "dodge"      :               -30,
         "parry"      :               -30,
         "damage"     :                190,
         "force"      :                190,
         "post_action":               (: power :),
         "damage_type":               "劈傷"
  ]),
});
void power(object me, object victim, object weapon, int damage)

{

int i;
 if(me->query("combat_exp") >= 300000 )
 if(me->query("force")>100&&me->query("force_factor"))      

{
   for(i=1;i<=4;i++)
{
    switch(i)
{

case 1:
message_vision(sprintf("$N見$n的攻勢瓦解決定使出獨門招式之"HIY"『春秋詩斷愁』"NOR"，直取$n的四處要害。\n"),me);


message_vision(sprintf("$N步伐如醉，使出『春秋詩斷愁』－－－"BLINK+HIB"【 春 風 拂 人 醉 】"NOR"，直劈$n的胸部。\n"),me,victim);
break;


case 2:
message_vision(sprintf("$N身輕如燕，使出『春秋詩斷愁』－－－"BLINK+HIY"【 飛 花 逐 人 香 】"NOR"，砍向$n的背部。\n"),me,victim);
break;


case 3:
message_vision(sprintf("$N深鎖緊眉，使出『春秋詩斷愁』－－－"BLINK+HIC"【 秋 意 愁 不 斷 】"NOR"，直取$n的頭部。\n"),me,victim);
break;


case 4:
message_vision(sprintf("$N行如快風，使出『春秋詩斷愁』－－－"BLINK+HIW"【 柳 葉 隨 人 癡 】"NOR"，斬向$n的咽喉。\n"),me,victim);
break;
}
     if(me->query_skill("snow-martial",1)>random(150))
{
message_vision(sprintf("結果被$N確確實實的劈中要害，$n身上已血流不止.\n"),me,victim);
            victim->receive_wound("kee",60,me);
          COMBAT_D->report_status(victim, 1);
   me->add("force",-60);
}else{

message_vision(sprintf("結果$N的攻擊被$n輕鬆避了開來。\n"),me,victim);
}
}
}
}
int valid_learn(object me)
{
       
        if(me->query("max_force")<100)
               return notify_fail("喂! 小子, 內力上限要 100 喔﹐等你長大點再來。\n");
        if(me->query_skill("force",1)<10)
               return notify_fail("你的內功\火候不夠﹐不能練破極斧法。\n");
        return 1;

}

 

int valid_enable(string  usage)  {

        if(this_player()->query_skill("max-axe",1) >= 70)
         {
            return (usage=="axe")||(usage=="parry");
         }
             return usage=="axe";
}

 

mapping query_action(object me, object weapon)

{
   int skill;
   skill=me->query_skill("max-axe", 1);
   if( skill < 20)
      return action[random(3)];
   else if( skill < 40)
      return action[random(4)];
   else if( skill < 60)
      return action[random(5)];
   else if( skill < 80)
      return action[random(9)];
   else if( skill < 90)
      return action[random(10)];
   else 
      return action[random(10)];   

}

int practice_skill(object me)

{
        if( (int)me->query("kee") < 30 )
                      return  notify_fail("你的氣不夠﹐無法練習破極斧法。\n");
        if( (int)me->query("force") < 5 )
                   return  notify_fail("你的內力不夠﹐不能練習破極斧法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)

{
        return CLASS_D("axeman")+"/max-axe/"+action;
}

  


