//麗玉蝶蘭指法 by roger && taifar
//金風細雨第八樓樓主林靜詩skill
//修正攻擊對象的錯誤 by blazakira 2011/2/10
#include <combat.h>
#include <ansi.h>
void sp_attack(object me,object victim,object weapon,int damage);
inherit SKILL;
mapping *action = ({
(["action":HIC + "$N一式" + HIM + "『麗柳沓心』" + HIC + "指氣輝光搖曳，虛影織成一片扼守，一道烈而陰柔的指氣劃穿幻網直搗$n心窩" + NOR,
        "damage":       250,
        "force":        250,
        "post_action":          (: sp_attack:),
        "damage_type":  "刺傷",
        "weapon"     :  "虹華指氣",
        ]),
(["action":HIC + "$N左右雙化使出了" + HIM + "『玉洛櫻周』" + HIC + "，左手五指似影似幻，指氣流竄， 右手五指剛柔兼變曲向$n的身周各處" + NOR,
           "damage":           250,
           "force":            250,
           "damage_type":  "割傷",
           "weapon"     :  "虹華指氣",
          ]),
(["action":HIC + "$N翩然若蝶飄飄使出一式" + HIM + "『蝶憫流鐘』" + HIC + "，身影殘殘，不費吹灰之力的閃過$n的攻擊襲向$n$l" + NOR,
           "damage":      250,
           "force":       250,
           "damage_type":  "刺傷",
           "weapon"     :  "虹華指氣",
           ]),

(["action":HIC + "$N曲繞若蛇壓身極低，一式" + HIM + "『麗玉蝶蘭指』" + HIC + "中的" + HIM + "『蘭泉潛鏡』" + HIC + "鎖住了$n的下盤，華瀅指氣如流水潺潺" + NOR,
        "damage":       250,
        "force":        250,
        "post_action":          (: sp_attack:),
        "damage_type": "刺傷",
        "weapon"     : "虹華指氣",
            ]),
(["action":HIC + "$N輕盈地飛滑揚上使出一式" + HIM + "『麗玉蝶蘭指』" + HIC + "中的" + HIM + "『芙蓉雙燕』" + HIC + "，兩股指氣一前一後的向$n遊襲而去" + NOR,
        "damage":       250,
        "force":        250,
        "damage_type": "刺傷",
        "weapon"     : "虹華指氣",
        ]),
(["action":HIC + "$N使出一式" + HIM + "『煌輪翻舞』" + HIC + "，只見$N十指輪彈，華麗的指氣漫天亂墜迫向$n" + NOR,
        "damage":       250,
        "force":        250,
        "post_action":          (: sp_attack:),
        "damage_type": "刺傷",
        "weapon"     : "虹華指氣",
        ]),

});

int valid_enable(string usage)
{
        return (usage=="unarmed")||(usage=="stabber")||(usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

void sp_attack(object me,object victim, object weapon,int damage)
{
 int i;
 if(random(100) > 50 && !me->query_temp("conti")){
message_vision(HIM + "\n$N分氣雙手，飛身迴繞，十指華光柔爍散出多道指氣襲向$n\n" + NOR,me,victim);
  victim->start_busy(1);
  me->set_temp("conti",1);
   for(i=0;i<5;i++)
    
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
                   
  me->delete_temp("conti");
                     }
}

