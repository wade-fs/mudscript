// lungshan.c
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void berserk(object me,object victim,object weapon,int damage);


mapping *action = ({
        ([      
                "action"     :              
"$N大喊呂洞賓:「呂洞賓:醉酒提壺力千鈞」,$N手成提酒狀,兩手往$n的雙肩一捉",
                "dodge"      :               -25,
                "parry"      :               -20,
                "damage"     :                30,
                "force"      :                50,
                "damage_type":               "捉傷"
        ]),
        ([     
                "action"     :              
"$N大喊「韓湘子:擒腕擊胸醉吹蕭」,$N捉住$n的手,往他的胸部猛撞",
                "dodge"      :               -50,
                "parry"      :               -10,
                "damage"     :                20,
                "force"      :                80,
                "damage_type":               "撞傷"
        ]),
        ([   
                "action"     :              
"$N大喊「張果老:醉酒拋杯醉連環」,$N成醉步狀,搖搖擺\擺\往$n踢去",
                "dodge"      :               -10,
                "parry"      :               -25,
                "damage"     :                70,
                "force"      :                100,
                "damage_type":               "踢傷"
        ]),
        ([  
                "action"     :              
"$N大喊「籃采和:單提敬酒攔腰破」,$N成半躺狀,手往$n的腰步一扣",
                "dodge"      :               -30,
                "parry"      :               -5,
                "damage"     :                90,
                "force"      :                120,
                "damage_type":               "扣傷"
        ]),
        ([ 
                "action"     :               "$N縱身一躍﹐使出瀧山拳奧義「山泉群湧」﹐拳如連珠般一連數十拳擊向$n$l",
                "dodge"      :               -30,
                "parry"      :               -30,
                "damage"     :                170,
                "force"      :                150,
                "post_action":               (: berserk :),
                "damage_type":               "瘀傷"
        ]),
        ([
                "action"     :              
"$N大喊「鐵拐李:旋肘膝撞醉還真」,$N收起收起一腳,搖搖擺\擺\一手卻將$n夾住",
                "dodge"      :               -20,
                "parry"      :               -45,
                "damage"     :                220,
                "force"      :                240,
                "damage_type":               "夾傷"
        ]),
        ([
                "action"     :              
"$N大喊「曹國舅:仙人敬酒鎖喉扣」,$N手成持杯狀,往$n的脖子一捉",
                "dodge"      :               -50,
                "parry"      :               -50,
                "damage"     :                280,
                "force"      :                300,
                "damage_type":               "捉傷"
        ]),
        ([
                "action"     :
"$N大喊「漢鍾離:醉步抱罈窩心頂」,$N頭一伸,往$n一撞",
                "dodge"      :               -30,
                "parry"      :               -5,
                "damage"     :                90,
                "force"      :                120,
                "damage_type":  "撞傷"
       ]),
       ([
               "action"      :
"$N大喊「何仙姑:彈腰敬酒醉盪步」,$N腰一彎,突然雙手往$n的臉部一彈",
               "dodge"      :               -30,
               "parry"      :               -5,
               "damage"     :                90,
               "force"      :                120,
               "damage_type":  "彈傷"
       ]),
});

int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
        return   notify_fail("學醉拳必須空手。\n");
        return   1;
}

int valid_enable(string usage)
{
        return ( usage=="unarmed" );
}


mapping query_action(object me, object weapon)
{
int skill_level, limit;
        skill_level = (int)(me->query_skill("drunk", 1));
        limit= (int)(skill_level/10);
        if (limit < 4 )
                return action[random(4)];
        if (limit < 7 )
                return action[random(limit)];
        else if (limit < 9)
                return action[random(6)];
        else
                return action[random(sizeof(action))];
}

void berserk(object me, object victim, object  weapon, int damage)
{
    int lose, i, test,pow,pow1;
        pow1 = 0;
        pow  = 0;
        if(!me->query_temp("berserk" ))
        {
                lose = (int)(me->query_skill("drunk", 1)/20 + 1);
                me->set_temp("berserk", 1);
                for(i = 0;i < lose; i++)
                {
                        pow = random(6);
                        pow1 = pow1+pow;
                        me->set_temp("apply/attack", pow1);
                        message_vision(
                       
"[1;33m$N使出八仙齊賀壽,如山泉湧出般打向$n各致命弱點。^[[0m\n" , me, victim);
                        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"));
                }
                me->delete_temp("apply/attack");
                me->delete_temp("berserk");
        }
} 


int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("你的體力不夠了﹐休息一下再練吧。\n");
        if( (int)me->query("force") < 3 )
                return notify_fail("你的內力不夠了﹐休息一下再練吧。\n");
        if( (int)me->query_skill("literate") <= (
(int)(me->query_skill("drunk", 1)*0.75) ) )
                return
notify_fail("你的武學知識不足﹐似乎無法參悟醉拳的最高奧秘");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}

string perform_action_file(string action)
{
        return CLASS_D("fighter")+"/drunk/"+action;
}

