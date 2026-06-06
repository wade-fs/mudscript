// dreamdance.c//cgy

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;

mapping *action = ({
        ([      
                "action"     :               "$N使出一招「飛燕翱翔」﹐雙腿呈燕尾狀以優美的姿態向著$n疾飛而至",
                "dodge"      :                10,
                "parry"      :               -20,
                "damage"     :                30,
                "force"      :                20,
                "damage_type":               "瘀傷"
        ]),
        ([     
                "action"     :               "$N身形倏然萬變，使出一招「雲霧飄緲」，趁著$n驚愕之際，雙掌向$n拍去",
                "dodge"      :               -5,
                "parry"      :               -30,
                "damage"     :                20,
                "force"      :                40,
                "damage_type":               "瘀傷"
        ]),
        ([   
                "action"     :               "$N身體向上飄起﹐兩腿如落葉飛花般﹐向著$n當頭罩落，正是夜夢天舞中的「落英繽紛」",
                "dodge"      :                10,
                "parry"      :               -35,
                "damage"     :                60,
                "force"      :                80,
                "damage_type":               "瘀傷"
        ]),
        ([  
                "action"     :               "$N雙腿向前蹬出﹐身體化為一道美麗的虹彩，使出一招「飛花逐月」擊向$n",
                "dodge"      :                15,
                "parry"      :               -25,
                "damage"     :                100,
                "force"      :                100,
                "damage_type":               "瘀傷"
        ]),
        ([ 
                "action"     :               "$N雙手如鳥翼般向上平舉﹐使出一招「白鶴掠翼」﹐擊向$n",
                "dodge"      :               -15,
                "parry"      :                10,
                "damage"     :                120,
                "force"      :                150,
                "damage_type":               "瘀傷"
        ]),
        ([
                "action"     :               "$N柔指舒張﹐姿態優美，忽然對著$n全身大穴疾點﹐令$n難以招架，正是夜夢天舞中的「天女散花」",
                "dodge"      :               -25,
                "parry"      :               -15,
                "damage"     :                140,
                "force"      :                180,
                "damage_type":               "瘀傷"
        ]),
        ([
                "action"     :               "$N身體開始旋轉﹐由緩而急﹐美妙的身形如鳳凰般向空飛起，身體四周形成一股強勁的氣流擊向$n，正是夜夢天舞最終絕學「鳳舞九天」",
                "dodge"      :                40,
                "parry"      :                20,
                "damage"     :                170,
                "force"      :                250,
                "damage_type":               "瘀傷"
        ]),
        ([
                 "action"     :               "" + HIC + "$N配合著夜夢天舞 舞著奇妙的步伐, 舞姿之曼妙 彷如貂蟬再世令$n看得入神 忽地$N幻化成熾熱的" + HIR + "朱雀" + NOR + " 無情的灼傷$n",
                "dodge"      :                45,
                "parry"      :                25,
                "damage"     :                140,
                "force"      :                200,
                "damage_type":               "瘀傷"
        ]),
        ([
                "action"     :               "" + HIG + "$N感受到王昭君下嫁匈奴的無奈 引起$N的殺意 急速旋轉自身形成一股怨憤之風 撲殺一切.." + NOR + "",
                "dodge"      :                45,
                "parry"      :                25,
                "damage"     :                160,
                "force"      :                230,
                "damage_type":               "瘀傷"
        ]),
        ([
               "action"     :               "" + HIY + "竇娥的冤屈突如其來湧入$N的心頭 一陣苦痛激起$N的潛能 發揮夜夢法鑑的極致" + HIC + " 滿天飛雪" + HIY + "侵襲$n...." + NOR + "",
                "dodge"      :                50,
                "parry"      :               35,
                "damage"     :                180,
                "force"      :                250,
                "damage_type":               "瘀傷"
        ]),


});
int valid_learn(object me)
{
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
                           return   notify_fail("學夜夢天舞必需空手。\n");
        if(me->query("max_force")<50)
                return notify_fail(" 乖徒兒，內力上限要 50 喔﹐多加油喔!!\n");
        return 1;
}


int valid_enable(string usage)
{
        return ( usage=="unarmed" || usage=="parry" );
}


mapping query_action(object me, object weapon)
{
        int skill_level, limit;
        skill_level = (int)(me->query_skill("dreamdance", 1));
        limit= skill_level;
 if(!me->query("get_dan_sp",1))
  {     if (limit < 28 )
                return action[random(2)];
        if (limit < 56 )
                return action[random(4)];
        if (limit < 84)
                return action[random(6)];
        else    
                return action[random(7)];
   }

else
{       
         if (limit < 90)
           return action[random(1)+7];
        else if(limit<95)
           return action[random(2)+7];
        else       
          return action[random(3)+7];
        } 
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 40 )
                return notify_fail("你的體力不夠了﹐休息一下再練吧。\n");
        if( (int)me->query("force") < 5 )
                return notify_fail("你的內力不夠了﹐休息一下再練吧。\n");
        me->receive_damage("kee", 40);
        me->add("force", -5);
        return 1;
}

/*
string perform_action_file(string action)
{
        return CLASS_D("dancer")+"/dreamdance/"+action;
}
*/
