// archery.c  弓技
#include <ansi.h>
inherit SKILL;

mapping *arrows_action = ({
        ([     "action" :      "$N將$c搭於$w之上﹐往$n的$l射去",
               "parry" :       -20,
               "dodge" :       -10,
               "damage_type" : "刺傷",
        ]),
});
mapping *bow_action = ({
        ([  "action":               "$N舉起$w狠狠地往$n$l砸去",
            "damage_type":  "瘀傷",
        ]),
        ([  "action":               "$N吃力地揮舞$w試著打傷$n",
            "damage_type":  "瘀傷",
        ]),
});
mapping query_action(object me, object weapon)
{
  int skill_level, limit;
  object wpn = me->query_temp("weapon");
  int i;
  i=wpn->query("arrow/amount");
  if( i == 1 ) {
          tell_object(me,
  HIY"\n你的" + wpn->query("arrow/name") + "已經用完了﹗﹗\n\n"NOR);
          wpn->set("arrow/id","none");
          wpn->set("arrow/name","空的");
          wpn->set("weapon_prop/damage",wpn->query("bow/attack"));
          me->set_temp("apply/damage",wpn->query("bow/attack"));
  }
  if( i > 0 ) {
          i--;
          wpn->set("arrow/amount",i);
          return arrows_action[random(sizeof(arrows_action))];
  }
  if( i <= 0 ) {
          return bow_action[random(sizeof(bow_action))];
  }
}
