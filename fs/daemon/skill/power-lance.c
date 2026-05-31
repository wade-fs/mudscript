// made in hide  :P

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void booldk(object me,object victim,object weapon,int damage);
void power(object me, object victim, object  weapon, int damage);

void busyk(object me, object victim, object  weapon, int damage);

 

mapping *action = ({

   ([
        "action":
"$N使出爆力美學基本式﹐一招"HIR"「爆裂殘擊」"NOR"﹐對準$n的肚子狠狠的一捅",

        "dodge"      :               -25,

        "parry"      :               -20,

        "damage"     :                20,

        "force"      :                50,

        "damage_type":               "捅傷"

   ]),
  ([
        "action"     :
"$N猶如屠夫般發展攻勢﹐使出一招"HIM"「暴徒狂殺」"NOR"拿起$w來一直往$n身上攻去",

        "dodge"      :               -50,

        "parry"      :               -10,

        "damage"     :                30,

        "force"      :                80,

        "damage_type":               "刺傷"

   ]),
  ([
        "action"     :
"$N狂亂鬼叫﹐傢伙一提﹐使出一招"HIC"「狂爆傲喉」"NOR"往$n的喉部一槍刺去",

        "dodge"      :               -10,

        "parry"      :               -25,

        "damage"     :                60,

        "force"      :                100,

        "damage_type":               "刺傷"
   ]),

  ([
        "action"     :
"$N聚集所有力量﹐使出爆力美學的"HIY"「爆舞煽掛」"NOR"$N舞起$w來分別擊向$n的頭喉心",

        "dodge"      :               -30,

        "parry"      :               -5,

        "damage"     :                90,

        "force"      :                150,

        "damage_type":               "刺傷"

   ]),

  ([

        "action"     :
"$N氣運丹田手中$w高舉於頭上﹐一招"HIG"「爆岩斬」"NOR"將力氣慣於雙臂﹐突乎其然斬向$n",
         "dodge"      :               -30,

         "parry"      :               -30,

         "damage"     :                110,

         "force"      :                180,

         "damage_type":               "斬傷"

   ]),
([
         "action"     :
"$N運起全身功\力﹐氣集於$w使出一招"BLINK+HIR"「爆炎槍尖屠」"NOR"尖上的"HIR"火舌緩緩蠕動"NOR"煞那間"HIR"火舌"NOR"突乎其然奔向$n",
         "dodge"      :               -20,

         "parry"      :               -45,

         "damage"     :                130,

         "force"      :                220,

         "damage_type":               "灼傷"

   ]),

  ([

         "action"     :
"$N橫起槍來﹐使出爆力美學一式「"HIC"超"HIR"爆"HIW"裂"HIY"狂嘯擊」"NOR"﹐使出了前所未有的超爆狂力朝$n身上狂刺過去",

         "dodge"      :               -50,

         "parry"      :               -50,

         "damage"     :                160,

         "force"      :                350,

         "post_action":               (: busyk :),

         "damage_type":               "刺傷"

  ]),

 ([      "action"     :             "$N使出爆力美學火爆式\n"
                              "<<"HIR"『爆能格鬥殺人法』"NOR">>\n"
                        HIY"$N單手拿著$w疾步奔向$n，連環使出殺人技巧\n"
                              "『 連蹴轉身空烈閃身單翼衝 』\n"
                              "$N像暴徒般向$n使出爆裂攻擊\n"NOR,
                 "dodge"     :                80,

                 "parry"     :                50,

                 "damage"    :                160,

                 "force"     :                150,

                 "post_action":               (: booldk :),

                 "damage_type":               "刺傷",

  ]),
 ([      "action"     :       "$N使出爆力美學超爆式\n"
                          "<<"HIY"『浮身亂彈擊』"NOR">>\n"
              HIC"$N將全身能量，準備一次爆發出來﹐此時$N全身充滿了力氣\n"
                     "$N感覺到全身向著了火一樣﹐全身爆出無數光芒\n"
                        "$N像飢虎直衝$n﹐狂亂般的攻擊$n\n"NOR,
                 "dodge"     :                80,

                 "parry"     :                50,

                 "damage"    :                170,

                 "force"     :                150,

                 "post_action":               (: power :),

                 "damage_type":               "刺傷",

  ]),

});

 

int valid_learn(object me)

{

        object ob;

 

        if((int)me->query("max_force")<150)

                return notify_fail("你的內力不夠﹐不能練爆力美學。\n");

 
        if( (string)me->query_skill_mapped("force")!= "spforce")

                return notify_fail("爆力美學必需配合爆烈心法才能用。\n");

 
        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "lance" )

                return notify_fail("你必須有槍才能練槍法。\n");

 

        return 1;   

}

 
int valid_enable(string usage)

{

        return ( usage=="lance" )||(usage=="parry");

}

 


mapping query_action(object me, object weapon)

{

   return action[random(sizeof(action))];

}

 

void booldk(object me, object victim, object  weapon, int damage)

{

        int i,time = random((int)me->query_skill("power-lance",1)/20 ) ;

	if( me->query("force_factor") >= 10 )

	{

          if( me->query_temp("booldk") == 0 )

	  {
            me->set_temp("booldk",1);
message_vision(sprintf(BLINK+HIM"$N藉由鮮血,使自身殺氣提升到最高峰,槍槍直取死穴。\n"NOR),me);

	    for(i=0;i<=time;i++)

            me->add("force",-70);

	      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

            me->delete_temp("booldk");

	  }

	}
}

 
void busyk(object me, object victim, object weapon, int damage)
{

  if(random(500) < me->query("bellicosity"))

  if(random(100) < me->query_skill("speed-lance",1))

{

  victim->set("start_busy",2);

  me->add("force",-50);

  message_vision(sprintf(BLINK+HIY"$N趁著$n招架不住時,繼續出招,槍勢之疾$n已快撐不住了.\n"NOR),me,victim);

}

}

 
void power(object me, object victim, object  weapon, int damage)

{
    int dept, i, test,pow,pow1;
        pow1 = 0;
        pow  = 0;

        if(!me->query_temp("power" ))

                dept = (int)(me->query_skill("power-lance", 1)/15 + 1);

                me->set_temp("power", 1);

                for(i = 0;i < dept; i++)
                {
                          pow = random(10)+4;

                          pow1 = pow1+0.5*pow;

                        me->set_temp("apply/attack", pow1);

                        message_vision(

                       HIG"$N使出爆力美學之超爆式『浮身亂彈擊』﹐拿起傢伙狂亂般的捅向$n。\n"NOR , me, victim);

                        victim->add("kee",-1*pow1);

                        me->add("force",-7);

           COMBAT_D->report_status(victim);

                }

                me->delete_temp("apply/attack");

                me->delete_temp("power");

        }


 

 

int practice_skill(object me)

 {

        if( (int)me->query("kee") < 30

        ||      (int)me->query("force") < 5)

                return notify_fail("你的內力或氣不夠﹐不能練爆力美學。\n");

        me->receive_damage("kee", 30);

        me->add("force", -5);

        return 1;

 }

 

string perform_action_file(string action)

{
        return CLASS_D("soldier")+"/soldier/"+action;

}

 

 

