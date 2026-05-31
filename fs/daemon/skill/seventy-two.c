// 如來神掌  by weiwei and smooth
//whatup整合少林技能
//調整少林技能並刪除目前沒有的設定 by blazakira 2010/10/20

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping query_action(object me, object victim, object weapon)
{
  int skill_level, limit;
  mixed *ac;
  string *sks;
  sks = ({
    "rulai",
    "fire-blade",
    "bonze-martial",
    "damon-sword",
    "dragon-claw",
    "star-stick"
  });
  victim = offensive_target(me);

  skill_level = (int)(me->query_skill("seventy-two", 1));
  ac = ({SKILL_D("rulai")->query_action(me,victim,weapon) });
  foreach(string sk in sks)
  {
    if(me->query("env/"+sk)) {
      ac += ({ SKILL_D(sk)->query_action(me,victim,weapon) });
    }
  }

  return ac[random(sizeof(ac))];
}

int valid_enable(string usage) 
{
  return 1;
  return (usage=="unarmed")||(usage=="parry");
}

int valid_learn(object me)
{
  return 1;
}

int practice_skill(object me)
{
  return 1;
}
