// dragon-dagger.c
// 盤龍匕

#include <combat.h>
#include <ansi.h>

inherit SKILL;
void sp1(object me, object victim, object  weapon, int damage);
void sp2(object me, object victim, object  weapon, int damage);

mapping *action = ({
([  "action"      :     "$N一招"HIW"『"HIM"盤龍出谷"HIW"』"NOR
                        "﹐手中$w往外劃出﹐向$n直衝而來。",
    "dodge"       :     -20,
    "damage"      :     100,
    "damage_type" :     "刺傷",
    "post_action":      (:call_other,__FILE__,"damage_weapon":),
]),
([  "action"      :     "$N手中$w一挺出﹐一招"HIW"『"HIM"龍奔四海"HIW"』"NOR
                        "如狂龍班往$n刺去。",
    "dodge"       :     -30,
    "damage"      :     150,
    "damage_type" :     "刺傷",
    "post_action":      (:call_other,__FILE__,"damage_weapon":),
]),
([  "action"      :     "$N一招"HIW"『"HIM"強龍併肩"HIW"』"NOR
                        "將手中$w往$n鄭去﹐隨即飛身踢去﹐並接回$w。",
    "damage"      :     200,
    "dodge"       :     -40,
    "parry"       :     -30,
    "force"       :     100,
    "damage_type" :     "刺傷",
    "post_action":      (:call_other,__FILE__,"damage_weapon":),
]),
([  "action"      :     "$N使出"HIW" 盤龍匕法 之 『 困 』字訣"NOR
                        ",以守帶攻的向$n襲去。",
    "damage"      :     160,
    "damage_type":      "刺傷",
    "post_action" :  (: sp1 :),
]),
([  "action"      :     "$N使出"HIW" 盤龍匕法 之 『 生 』字訣"NOR
                        ",以守帶攻的向$n襲去。",
    "damage"      :     140,
    "damage_type":      "刺傷",
    "post_action" :  (: sp2 :),
]),
});

void sp1(object me, object victim, object  weapon, int damage)
{
     int skill,i,j;
      skill = me->query_skill("dragon-dagger",1);
     if( me->query("force") > skill && !me->query_temp("conti"))
     {
            if(skill >=50)
              i=2;
                else
                i=1;
        victim->start_busy((int)i);
        message_vision(HIW"$N轉眼間化做數十個身影,迷惑了$n。\n"NOR,me,victim);
        if(70 > random(100))
        {
                if(!me->query_temp("conti"))
                {
                        me->set_temp("conti",1);
                        j=skill/10;
                        message_vision(BLINK+HIY"$N眼看$n被『 困 』字訣所迷惑，奮不顧身的使出連續技!!!\n"NOR,me,victim);
                        for(i=0;i<j;i++)
                        {
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                        }
                        me->delete_temp("conti");
                        message_vision(HIR"$N因為使出連續技而氣血混亂，連忙閉目調息。\n"NOR,me);
                        me->start_busy(1);
                         victim->delete_busy();
                         victim->start_busy(1);
                }
        }
        me->add("force",-skill);
     }else victim->start_busy(1);
     return;
}
void sp2(object me, object victim, object  weapon, int damage)
{
     int skill;
    skill = me->query_skill("dragon-dagger",1)*4;
        if( me->query("force") > skill && !me->query_temp("conti"))
     {
       me->receive_curing("kee",skill);
       me->receive_heal("kee",skill);
       me->add("force",(int)(-skill/2) );
       message_vision(HIW"$N吸取天地靈氣,回復了傷口。\n"NOR,me);
     }else me->receive_curing("kee",100);
     return;
}
int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") !="dagger")
        return notify_fail("你要有匕首才能練盤龍匕。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="dagger"||usage=="parry";
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

string perform_action_file(string action)
{
        return CLASS_D("officer")+"/dragon-dagger/"+action;
}
