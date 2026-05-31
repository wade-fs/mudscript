#include <ansi.h>
inherit SKILL;
inherit SSERVER;

void force_damage(object me, object victim, object weapon, int damage);

int valid_enable(string usage) { return usage=="force"; }


mapping *force_action = ({
([      "post_action": (: force_damage :) ])
});

int practice_skill(object me)
{
        return notify_fail("真˙黑牙神功\只能從運用(exert)中增加熟練度。\n");
}
string perform_action_file(string action)
{
        return CLASS_D("killer")+"/ninja-force/"+action;
}
int valid_learn(object me)
{
tell_object(me,"真˙黑牙神功\無法從學習中獲得進展, 必須自己修行方有成果!!\n");
return 0;
}
