//星夜豔夢刀法 by roger && taifar
//金風細雨第九樓樓主李夢枕skill
#include <combat.h>
#include <ansi.h>
void sp_attack(object me,object victim,object weapon,int damage);
void sp_attack1(object me,object victim,object weapon,int damage);
void sp_attack2(object me,object victim,object weapon,int damage);
inherit SKILL;
mapping *action = ({
(["action":HIC"$N輕舞$w使出一式"HIY"『夜女清芬』"HIC"，刀光悠遠，像麗人倩影圈撒淡淡香氳，豔烈的刀氣瞬間直奔$n喉間"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "post_action":          (: sp_attack1:),
        "damage_type":  "砍傷",
        "weapon"     :  "情刀",
        ]),
(["action":HIC"$N刀鋒側轉使出一式"HIY"『夕若蘅芷』"HIC"，伴著紅紅刀光沁出郁郁香氣，刃隨風捲，赤虹刀氣如夕霞突落在$n眼前"NOR,
           "damage":           850,
           "force":            850,
           "damage_type":  "割傷",
        "post_action":          (: sp_attack1:),
        "damage_type":  "砍傷",
           "weapon"     :  "情刀",
          ]),
(["action":HIC"$N倏地迴刀，一式"HIY"『夢醉風鈴』"HIC"的破風聲猶如一串風過時的鈴響，刀氣形成美麗的弧線高掠過空直墜$n腦門"NOR,
           "damage":      850,
           "force":       850,
           "damage_type":  "砍傷",

        "post_action":          (: sp_attack:),
        "post_action":          (: sp_attack1:),
           "weapon"     :  "情刀",
           ]),

(["action":HIC"$N飛身一式"HIY"『星香蕉葉』"HIC"，刀光輪轉，身影輕的就像一陣微風迫近$n，刃裂狂旋，亂掃$n的四肢"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "damage_type": "劈傷",
        "weapon"     :  "情刀",
            ]),
(["action":HIC"$N壓身反轉刀柄突刺$n的雙膝使出"HIY"『星夜醉夢刀法』"HIC"中的"HIY"『睡露海棠』"HIC"，在眨眼間回刀上揚平掃落刃襲向$n$l"NOR,
        "damage":       850,
        "force":        850,
        "damage_type": "劈傷",
        "post_action":          (: sp_attack:),
        "weapon"     :  "情刀",
        ]),
(["action":HIC"$N提足劃上"HIY"『星夜醉夢刀法』"HIC"，使出了一式『借柳掛月』，$w在空中旋出粼粼弧光颯成銀月，月凜刀氣直落$n$l"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (: sp_attack:),
        "damage_type": "劈傷",
        "weapon"     :  "情刀",
        ]),
(["action":HIC"$N若有似無，藉由"HIY"『星夜醉夢刀法』"HIC"刀意，使出了一式『如夢似醉』，$w在$N手中劃出陣陣銀光直落$n$l"NOR,
        "damage":       850,
        "force":        850,
        "post_action":          (:sp_attack2:),
        "damage_type": "劈傷",
        "weapon"     :  "情刀",
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
 int i;
 if(random(100) > 50 && !me->query_temp("conti")){
message_vision(HIM"\n$N隨風一笑，情刀流香郁郁，星光迷離，刀光一散如細細的雨般往$n灑去，令人陶醉 \n"NOR,me,victim);
  victim->start_busy(2);
  me->set_temp("conti",1);
   for(i=0;i<5;i++)
    
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                   
  me->delete_temp("conti");
                     }
}
void sp_attack1(object me,object victim, object weapon,int damage)
{
 int i;
 if(random(100) > 50 && !me->query_temp("conti")){
message_vision(HIM"\n$N隨風一笑，情刀流香郁郁，星光迷離，刀光一散如細細的雨般往$n灑去，令人陶醉 \n"NOR,me,victim);
  me->set_temp("conti",1);
   for(i=0;i<2;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);

  me->delete_temp("conti");
                     }
}
void sp_attack2(object me,object victim, object weapon,int damage)
{
 message_vision(sprintf(HIC"$N人隨意轉，轉眼間來到$n身後，$n發覺急忙轉身回擋，只見$N繞到另一側並使出其本身真氣發出流星般的一擊 \n"NOR),me,victim);
 victim->start_busy(2);
 message_vision(sprintf(HIC"$n中招後愣了一下，瞬間$N浩翰真氣已席捲而至 \n"NOR),me,victim);
 victim->apply_condition("tsunami",random(4)+2);
 COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
 }

