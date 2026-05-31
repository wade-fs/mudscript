#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void berserk(object me,object victim,object weapon,int damage);
void sound(object me,object victim,object weapon,int damage);
void punch(object me,object victim,object weapon,int damage);
mapping *action = ({
        ([      "action":               "$N撲上來張嘴往$n的$l狠狠地一咬",
                "dodge":                -200,
                "parry":                -200,
                "damage":                200,
                "force":                300,
                "damage_type":  "咬傷",
                "post_action":               (: sound :)

        ]),
        ([      "action":               "$N撲上來張嘴往$n的$l狠狠地一咬",
                "dodge":                -200,
                "parry":                -200,
                "damage":                200,
                "force":                300,
                "damage_type":  "咬傷",
                "post_action":               (: punch :)

        ]),
        ([      "action":               "$N撲上來張嘴往$n的$l狠狠地一咬",
                "dodge":                -200,
                "parry":                -200,
                "damage":                320,
                "force":                450,
                "damage_type":  "咬傷",
                "post_action":               (: berserk :)

        ]),
        ([      "action":               "$N撲上來張嘴往$n的$l狠狠地一咬",
                "dodge":                -200,
                "parry":                -200,
                "damage":                390,
                "force":                500,
                "damage_type":  "咬傷",
                "post_action":               (: berserk :)
        ]),
});

int valid_learn(object me)
{
        return 1;
}

int valid_enable(string usage)
{
        return usage=="unarmed";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

int practice_skill(object me)
{
        return 1;
}
void berserk(object me, object victim, object  weapon, int damage)
{
int j = 0;
int k = 1 + random(2);
if(me->query_temp("earthkill")!=1)
 {
  if(me->query("combat_exp") > 18000000)
  {
   me->set_temp("earthkill",1);
   for(j = 0;j < k; j++)
    {
      COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    }
   me->delete_temp("earthkill");
  }else
       {
      	me->set_temp("earthkill",1);
      	COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
      	me->delete_temp("earthkill");
       }
 }
}

void sound(object me, object victim, object  weapon, int damage)
{
  object room = environment(me);
  if(me->query_temp("earthkill")!=1)
  {
   message_vision(HIG"\n$N發出一聲攝人的怒吼，整個"+room->query("short")+""HIG"因而震動。\n"NOR,me,victim);
   if(random(2)!=1)
   {
    message_vision(HIR"$n首當其衝，頓時神智不清，幾欲昏厥。\n"NOR,me,victim);
    victim->receive_wound("kee",200+random(200));
    COMBAT_D->report_status(victim);
   }else{
    message_vision(HIW"$n運足內功\強抗，毫髮無傷。\n"NOR,me,victim);
    victim->add("force",-100);
        }
  }
}

void punch(object me, object victim, object  weapon, int damage)
{
  object room = environment(me);
  if(me->query_temp("earthkill")!=1)
  {
   message_vision(HIM"\n$N突然提高速度，以排山倒海般的氣勢向$n衝去。\n"NOR,me,victim);
   if(random(2)!=1)
     {
      message_vision(HIB"$n被撞個滿懷，強大的衝擊力使得$n一時無法動彈。\n"NOR,me,victim);
      victim->add("kee",-200-random(200));
      COMBAT_D->report_status(victim);
     }else{
           message_vision(HIW"$n及時閃過這要命的衝撞，嚇出一身冷汗。\n"NOR,me,victim);
           victim->add("gin",-50);
          }
  }
}
