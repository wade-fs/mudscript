// coding by ken 
// fix by borstquc
// Chan重新QC 08/27/98 之前威力強了點.改弱..
//fix by airke
//add 紫龍之氣  by whatup
#include <combat.h>
#include <ansi.h>
inherit SKILL;
inherit SSERVER;
void hurt(object me, object victim, object weapon, int damage);

string pit();

string *parry_msg = ({
        "而$n不慌不忙，虛招一遞，一式"HIW"『"HIB"畫龍點睛"HIW"』"NOR"直取$N雙眼，$N一驚之下趕緊撤招回架!\n",
	"$n遇招拆招"HIW"『"HIY"斗轉星移"HIW"』"NOR"使的得心應手﹐已將$N的攻勢卸的毫無威力可言。\n",
        "$n手中拂塵一揚，以四兩撥千金手法撥開了$N的攻擊\n",
        "$n借力打力，勁力一發，將$N的去勢卸得偏了準頭\n",
	"但$n見狀，反以一招"HIW"『"MAG"蟠龍鎖關"HIW"』"NOR"對準$w來勢緊緊鎖住，拂塵往後一揚$N的$w被扯的險些脫手而出!!\n",
        });

string query_parry_msg(string limb)
{
      
        return parry_msg[random(sizeof(parry_msg))] ;
      
}

mapping *action = ({
        ([      "action":               "$N使出一招「龍尾刺」，手中$w如針般刺向$n的$l",
                "dodge":                -10,
                "damage":               20,
                "damage_type":  "刺傷",
                
        ]),
        
        ([      "action":               "一招「峰迴路轉」﹐$N手中$w如一條銀蛇般纏向$n的$l",
                "dodge":                -20,
                 "damage":               25,
                "damage_type": "刺傷",
                   
        ]),

        ([      "action":               "$N手上$w靈動而出，一招「龍尾甩」﹐手中$w疾劈$n的$l",
                "dodge":                -20,
                "damage":                35,
                "damage_type":  "割傷",
                
        ]),

        ([      "action":               "$N手中$w向中宮直進﹐一式「旭日東升」對準$n的$l刺出",
                "parry":                -20,
                "dodge":                -10,
                "damage":                40,
                "damage_type":  "刺傷",
                
        ]),

        ([      "action":               "$N縱身一躍手中$w內勁澎湃，「"HIY"巨龍蓋\頂"NOR"」對準$n上路直直壓下",
                "dodge":                -30,
                "force":                60,
                "damage":               50,
                "damage_type":  "割傷",
                
        ]),

        ([      "action":               "$N兩手往前一送$w螺旋甩出，一招「"HIG"毒龍鑽"NOR"」直刺$n的$l",
                "parry":                -10,
                "dodge":                -20,
                "force":                 40,
                "damage":                60,
                "damage_type":  "刺傷",
                
        ]),

        ([      "action":               "$N手中$w向外一分，使一招「"HIR"雙龍噬"NOR"」，反手對準$n$l擊去",
                "parry":                -25,
                "dodge":                -20,
                "force":                 40,
                "damage":                 70,
                "damage_type":  "刺傷",                
        ]),

        ([      "action":               "$N奮力使出一式「"HIM"御風而行"NOR"」，身形陡然滑出數尺，$w飄然而出，柔中帶剛直指$n的$l",
                "dodge":                -10,
		"force":		40,
                     "damage":                75,
                "damage_type":  "割傷",
               
        ]),
        
        ([      "action":               "$N腳踏七星步身形一快，一招「"HIW"金虹斷空"NOR"」$w隔空劃出一道弧光閃電般斬向$n",
                "parry":                -20,
                "dodge":                -25,
                "damage":	         80,
                "damage_type":  "割傷",
        
        ]),

        ([      "action":               "$N一招「"HIC"天道擊"NOR"」，手中$w疾風暴雨地點向$n$l",
                "parry":                -20,
                "force":                 60,
                "damage":                75,
                "damage_type":  "刺傷",
                
        ]),

        ([      "action":               "$N清嘯一聲，內力疾吐一式「"HIB"雷厲風行"NOR"」，$w以迅雷之勢向$n拂去",
                "dodge":                -30,
                "force":                 60,
                "damage":                80,
                "damage_type":  "瘀傷",
        ]),

        ([      "action":               "$N手中$w舞開，「"MAG"盤龍錯"NOR"」一閃而出，有如盤龍出谷威不可赫，一瞬間將$n$l纏得咯咯作響",
                "dodge":               -25,
		"force":                40,
                "damage":                80,
                "damage_type":  "瘀傷",
                
        ]),
        ([      "action":               "$N的"HIW"天 "HIB"罡\ "HIW"戰 "HIB"氣"NOR"聚滿全身，眉心之間光芒聚現，天地之間光柱貫穿其中，全身三百六十五之穴脈靈氣溢出，
$N引動體內"HIM"紫龍之氣"NOR"，一聲龍吟，巨大龍頭忽現一聲狂吼光炮從口而出，衝向$n貫體而過！！\n",
                "dodge":               -25,
		"force":                40,
                "damage":                80,
                "damage_type":  "瘀傷",
                "post_action":                (: hurt :),               
        ]),

});



int valid_learn(object me)
{
        object ob;

        if( !(ob = me->query_temp("weapon"))
        ||      (string)ob->query("skill_type") != "whip" )
                write("你必須先裝備武器才能練鞭法。\n");

        return 1;
}

int valid_enable(string usage)
{
        return usage=="whip" || usage=="parry";
}

mapping query_action(object me, object weapon)
{
     int whipski=me->query_skill("whip");   
     if( whipski < 40 )
         return action[random(4)];
     if( whipski < 60 )
         return action[random(7)];
     if( whipski < 80 )
         return action[random(7)+4];
     if( !me->query("marks/god-kee") )
      return action[random(8)+4];
     else
      return action[random(5)+8];
}

int practice_skill(object me)
{
        me->receive_damage("kee", 10);
        me->add("force", -15);
        write("你按著所學練了一遍紫龍鞭法。\n");
        return 1;
}

string skill_improved(string me)
{
         tell_object(this_player(),"你的鞭法苦練有成，變得比以前更加靈活。\n");
}
string perform_action_file(string action)
{
        return CLASS_D("taoist") + "/gwhip/" + action;
}
void hurt(object me, object victim, object weapon, int damage)
{
  object targets;
  int sp = 0;
  if(me->query("mana") < 100) return ;
  if(me->query("force") < 100) return ;
  me->add("mana",-20);
  sp = me->query_skill("spells") + random(me->query_skill("spells") );
  sp = sp * 4;
  message_vision(HIM"
<~>
    \\ \\,_____
          ___`\\
          \\('>\\`-__
            ~      ~~~--__            **              ***
                  ______  (@\\   *******  ****    *******    ******
                 /******~~~~\\|**********************************
         \\       `--____******************************************
        / ~~~--_____    ~~~/ ***************************************
                    `~~~~~         ******************************
                                         ****    **************
                                            ***       ***********
                                                           ********
 \n\n"NOR,me);
 targets = me->query_enemy();
 foreach(object target in targets){
  if(random(100) > 20) {
    message_vision(MAG"一陣紫龍之氣從$N的體內對穿而出。\n"NOR,target);
    target->receive_wound("sen", sp , me);
    COMBAT_D->report_status(target, 1);
  }
 }
}

