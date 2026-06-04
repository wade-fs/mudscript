// dreamdance.c//cgy

#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void dance(object me, object victim, object weapon);
mapping *action = ({
        ([
                "action"     :               "$N使出一招[1;32m「飛燕翱翔」[0m﹐雙腿呈燕尾狀以優美的姿態向著$n疾飛而至",
                "dodge"      :                10,
                "parry"      :               -20,
                "damage"     :                30,
                "force"      :                20,
                "damage_type":               "瘀傷",
        ]),
        ([
                "action"     :               "$N身形倏然萬變，使出一招[1;32m「雲霧飄緲」[0m，趁著$n驚愕之際，雙掌向$n拍去",
                "dodge"      :               -5,
                "parry"      :               -30,
                "damage"     :                20,
                "force"      :                40,
                "damage_type":               "瘀傷",
        ]),
        ([
                "action"     :               "$N身體向上飄起﹐兩腿如落葉飛花般﹐向著$n當頭罩落，正是夜夢天舞中的[1;32m「落英繽紛」[0m",
                "dodge"      :                10,
                "parry"      :               -35,
                "damage"     :                60,
                "force"      :                80,
                "damage_type":               "瘀傷",
        ]),
        ([
                "action"     :               "$N雙腿向前蹬出﹐身體化為一道美麗的虹彩，使出一招[1;32m「飛花逐月」[0m擊向$n",
                "dodge"      :                15,
                "parry"      :               -25,
                "damage"     :                100,
                "force"      :                100,
                "damage_type":               "瘀傷",
        ]),
        ([
                "action"     :               "$N雙手如鳥翼般向上平舉﹐使出一招[1;32m「白鶴掠翼」[0m﹐擊向$n",
                "dodge"      :               -15,
                "parry"      :                10,
                "damage"     :                120,
                "force"      :                150,
                "damage_type":               "瘀傷",
        ]),
        ([
                "action"     :               "$N柔指舒張﹐姿態優美，忽然對著$n全身大穴疾點﹐令$n難以招架，正是夜夢天舞中的[1;32m「天女散花」[0m",
                "dodge"      :               -25,
                "parry"      :               -15,
                "damage"     :                140,
                "force"      :                180,
                "damage_type":               "瘀傷",
        ]),
        ([
                "action"     :               "$N身體開始旋轉﹐由緩而急﹐美妙的身形如鳳凰般向空飛起，身體四周形成一股強勁的氣流擊向$n，正是夜夢天舞最終絕學[1;32m「鳳舞九天」[0m",
                "dodge"      :                40,
                "parry"      :                20,
                "damage"     :                170,
                "force"      :                250,
                "damage_type":               "瘀傷",
        ]),
        ([
                 "action"     :               "" + HIR + "☆☆☆☆☆" + HIC + "配合著夜夢天舞 舞著奇妙的步伐, 舞姿之曼妙彷如貂蟬再世" + HIR + "☆☆☆☆☆
　　　　" + HIC + "令$n看得入神 忽地$N幻化成熾熱的" + HIR + "朱雀" + HIC + " 無情的灼傷$n" + NOR + "",
                "dodge"      :                45,
                "parry"      :                25,
                "damage"     :                200,
                "force"      :                200,
                "damage_type":               "瘀傷",
                "post_action" : (: dance :),
        ]),
        ([
                "action"     :               "" + HIW + "◎◎◎◎◎" + HIG + "$N感受到王昭君下嫁匈奴的無奈 引起$N的殺意" + HIW + "◎◎◎◎◎
　　　　　" + HIG + " 急速旋轉自身形成一股怨憤之風 撲殺一切.." + NOR + "",
                "dodge"      :                45,
                "parry"      :                25,
                "damage"     :                220,
                "force"      :                230,
                "damage_type":               "瘀傷",
                "post_action" : (: dance :),
        ]),
        ([
               "action"     :               "" + HIM + "※※※※※" + HIY + "竇娥的冤屈突如其來湧入$N的心頭 一陣苦痛激起$N" + HIM + "※※※※※
　　　　　   " + HIY + "的潛能發揮夜夢法鑑的極致" + HIC + " 滿天飛雪" + HIY + "侵襲$n...." + NOR + "",
                "dodge"      :                50,
                "parry"      :               35,
                "damage"     :                240,
                "force"      :                250,
                "damage_type":               "瘀傷",
                "post_action" : (: dance :),
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

void dance(object me, object victim, object weapon)
{
if (me->query("combat_exp") > 1000000 && me->query_temp("dance1")!=1 && me->query_temp("rainbow-steps")&& random(100) < me->query("functions/rainbow-steps/level"))
{
if (me->query_temp("dance1")!=1) me->set_temp("dance1",1);
message_vision(HIW + "\n$N踏著舞步不斷的向$n發動攻擊。\n" + NOR,me,victim);
COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
me->delete_temp("dance1");
}
}

mapping query_action(object me, object weapon)
{
int skill_level, limit,k,i,kee;
object victim,*enemy;
victim = offensive_target(me);
if(!victim) return action[random(10)];
skill_level = (int)(me->query_skill("dreamdance", 1));
limit= skill_level;
k = random(100);
if(me->query_temp("weapon"))
{
weapon=me->query_temp("weapon");  //扣自己force 50
if((me->query("class")=="dancer")&&(weapon->query("id")=="maple ribbon"))
{
if(me->query("id")==("cgy"))
{
message_vision(HIY + "\n  $N手上的" + HIW + "楓" + HIG + "之" + HIM + "舞" + HIY + "和$N產生感應,剎那間$N領悟了夜夢天舞的奧秘!!\n" + NOR,me,victim);
message_vision(HIY + "使出了究極奧義" + HIR + " 秋 " + HIW + " 風 " + HIG + " 掃 " + HIC + " 落 " + HIM + " 葉 " + HIY + "$N手上的" + HIW + "楓" + HIG + "之" + HIM + "舞" + HIY + "向著$n急速席捲纏繞而去!!\n\n" + NOR,me,victim);
message_vision(HIR + "        ＊         " + HIY + "        ＊         " + HIC + "        ＊         " + HIG + "        ＊        \n" + NOR,me,victim);
message_vision(HIR + "      ＊＊＊       " + HIY + "      ＊＊＊       " + HIC + "      ＊＊＊       " + HIG + "      ＊＊＊      \n" + NOR,me,victim);
message_vision(HIR + "  ＊  ＊＊＊  ＊   " + HIY + "  ＊  ＊＊＊  ＊   " + HIC + "  ＊  ＊＊＊  ＊   " + HIG + "  ＊  ＊＊＊  ＊  \n" + NOR,me,victim);
message_vision(HIR + "＊＊＊ ＊＊ ＊＊＊ " + HIY + "＊＊＊ ＊＊ ＊＊＊ " + HIC + "＊＊＊ ＊＊ ＊＊＊ " + HIG + "＊＊＊ ＊＊ ＊＊＊\n" + NOR,me,victim);
message_vision(HIR + " ＊＊＊＊＊＊＊＊  " + HIY + " ＊＊＊＊＊＊＊＊  " + HIC + " ＊＊＊＊＊＊＊＊  " + HIG + " ＊＊＊＊＊＊＊＊ \n" + NOR,me,victim);
message_vision(HIR + "   ＊＊＊＊＊＊    " + HIY + "   ＊＊＊＊＊＊    " + HIC + "   ＊＊＊＊＊＊    " + HIG + "   ＊＊＊＊＊＊   \n" + NOR,me,victim);
message_vision(HIR + "      ＊＊＊       " + HIY + "      ＊＊＊       " + HIC + "      ＊＊＊       " + HIG + "      ＊＊＊      \n\n" + NOR,me,victim);
 for(i=0;i<10;i++)
{
message_vision(HIR + "$n但覺眼前所見盡是無窮無盡的楓葉飛舞,瞬時$n被火紅的楓葉所席捲,全身痛苦不己。\n" + NOR,me,victim);
victim->receive_damage("kee",10000,me);
victim->apply_condition("burn",random(10));
COMBAT_D->report_status(victim);
}
message_vision(HIY + "$N手上的" + HIW + "楓" + HIG + "之" + HIM + "舞" + HIY + "回復了原狀纏繞於$N手上。\n" + NOR,me);
me->add("force",-50);
}
else if((k>80)&&(skill_level>80))
{
message_vision(HIY + "\n  $N手上的" + HIW + "楓" + HIG + "之" + HIM + "舞" + HIY + "和$N產生感應,剎那間$N領悟了夜夢天舞的奧秘!!\n" + NOR,me,victim);
message_vision(HIY + "使出了究極奧義" + HIR + " 秋 " + HIW + " 風 " + HIG + " 掃 " + HIC + " 落 " + HIM + " 葉 " + HIY + "$N手上的" + HIW + "楓" + HIG + "之" + HIM + "舞" + HIY + "向著$n急速席捲纏繞而去!!\n\n" + NOR,me,victim);
message_vision(RED + "        ＊         " + YEL + "        ＊         " + RED + "        ＊         " + YEL + "        ＊        \n" + NOR,me,victim);
message_vision(RED + "      ＊＊＊       " + YEL + "      ＊＊＊       " + RED + "      ＊＊＊       " + YEL + "      ＊＊＊      \n" + NOR,me,victim);
message_vision(RED + "  ＊  ＊＊＊  ＊   " + YEL + "  ＊  ＊＊＊  ＊   " + RED + "  ＊  ＊＊＊  ＊   " + YEL + "  ＊  ＊＊＊  ＊  \n" + NOR,me,victim);
message_vision(RED + "＊＊＊ ＊＊ ＊＊＊ " + YEL + "＊＊＊ ＊＊ ＊＊＊ " + RED + "＊＊＊ ＊＊ ＊＊＊ " + YEL + "＊＊＊ ＊＊ ＊＊＊\n" + NOR,me,victim);
message_vision(RED + " ＊＊＊＊＊＊＊＊  " + YEL + " ＊＊＊＊＊＊＊＊  " + RED + " ＊＊＊＊＊＊＊＊  " + YEL + " ＊＊＊＊＊＊＊＊ \n" + NOR,me,victim);
message_vision(RED + "   ＊＊＊＊＊＊    " + YEL + "   ＊＊＊＊＊＊    " + RED + "   ＊＊＊＊＊＊    " + YEL + "   ＊＊＊＊＊＊   \n" + NOR,me,victim);
message_vision(RED + "      ＊＊＊       " + YEL + "      ＊＊＊       " + RED + "      ＊＊＊       " + YEL + "      ＊＊＊      \n\n" + NOR,me,victim);
 for(i=0;i<5;i++)
{
message_vision(HIR + "$n但覺眼前所見盡是無窮無盡的楓葉飛舞,瞬時$n被火紅的楓葉所席捲,全身痛苦不己。\n" + NOR,me,victim);
victim->receive_damage("kee", 100,me);
victim->apply_condition("burn",random(10));
COMBAT_D->report_status(victim);
}
message_vision(HIY + "$N手上的" + HIW + "楓" + HIG + "之" + HIM + "舞" + HIY + "回復了原狀纏繞於$N手上。\n" + NOR,me);
me->add("force",-50);
}
}
}
 if((me->query("get_dan_sp",1))&&(me->query("family/family_name")=="夜夢小築"))
 {      if (limit < 28 )
                return action[random(2)];
        if (limit < 56 )
                return action[random(4)];
        if (limit < 84)
                return action[random(4)+2];
         if (limit < 90)
           return action[random(6)+2];
        else if(limit<95)
           return action[random(6)+3];
        else
          return action[random(6)+4];
        }

else
 {     if (limit < 28 )
                return action[random(2)];
        if (limit < 56 )
                return action[random(4)];
        if (limit < 84)
                return action[random(4)+2];
        else
                return action[random(4)+3];
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
