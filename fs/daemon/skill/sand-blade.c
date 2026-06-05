//金風細雨樓之黃沙萬里刀法 by roger && taifar

#include <combat.h>
#include <ansi.h>
void sp_attack(object me,object victim,object weapon,int damage);
inherit SKILL;
mapping *action = ({
(["action":HIY + "$N飛躍於上，刀光瞬間耀眼刺目，一式" + HIW + "『日落沙丘』" + HIY + "急墜直下，只見一線閃光挾著劇烈風壓落向$n頭上" + NOR,
        "damage":       400,
        "force":        400,
        "post_action":          (: sp_attack:),
        "damage_type":  "砍傷",
        "weapon"     :  "情刀",
        ]),
(["action":HIY + "$N將$w" + HIY + "反手一握，靜如豹\獵，雙眼彷彿穿透了$n的心，飛閃一式" + HIW + "『月冷大漠』" + HIY + "刀氣如斷月雷光直朝$n縱剖而去" + NOR,
           "damage":           400,
           "force":            400,
           "post_action":          (: sp_attack:),
           "damage_type":  "割傷",
          ]),
(["action":HIY + "$N振刀激塵使出一式" + HIW + "『萬里崩沙』" + HIY + "，瞬間飛沙走石，每一微小塵粒都是殺機，黃沙將$n完全封在土霧之中" + NOR,
           "damage":      400,
           "force":       400,
           "post_action":          (: sp_attack:),
           "damage_type":  "砍傷",
           ]),

(["action":HIY + "$N使刀若劍，" + HIW + "『黃沙萬里刀法』" + HIY + "中的一式" + HIW + "『百點甘露』" + HIY + "在漫天塵沙之中圈出閃閃殺漪，點點錯雜卻盡數指向$n的眉心" + NOR,
        "damage":       400,
        "force":        400,
        "post_action":          (: sp_attack:),
        "damage_type": "劈傷",
            ]),
(["action":HIY + "$N忽揚一式" + HIW + "『燥捲風沙』" + HIY + "使得突進而來的$n不得不退，並趁勢追攻，只見風沙交天混雜著刀氣向$n捲去" + NOR,
        "damage":       400,
        "force":        400,
        "post_action":          (: sp_attack:),
        "damage_type": "劈傷",
        ]),

});

int valid_enable(string usage)
{
        return (usage=="blade")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

void sp_attack(object me,object victim, object weapon,int damage)
{
 object *enemy,target,env;
 int i,j;

 env = environment(me);
 enemy=me->query_enemy();
 i=sizeof(enemy);

 for(j=0;j < i;j++){
  target=enemy[j];
    if( env == environment(target) )
    {
     target->receive_damage("kee",150);
     COMBAT_D->report_status(target);
    }
                   }

}

