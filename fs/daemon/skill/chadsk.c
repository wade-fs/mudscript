// 如來神掌  by weiwei and smooth
#include <combat.h>
#include <ansi.h>

inherit SKILL;
inherit SSERVER;
void ru10(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);
void hurt(object me,object victim, object weapon, int damage);

mapping *action = ({
//1
([ "action" : "$N吐氣揚眉,身形一頓,一道金光自右掌中浮出,正是一招『"HIY"佛"NOR"光初現』。",
                "dodge"      :   -30,
                "parry"      :   -20,
                "damage"     :    500,
                "force"      :    50,
                "damage_type":   "瘀傷",
                "post_action": (: call_other,__FILE__,"hurt" :),
           ]),
//2           
([ "action" : "$N閉目合眉,雙掌合什,倏然欺身而上,一招『金頂"HIY"佛"NOR"燈』,$n已籠罩$n周身七十二大穴。",
                "dodge"      :    -30,
                "parry"      :    -20,
                "damage"     :     600,
                "force"      :     60,
                "damage_type":   "瘀傷",
                "post_action": (:  call_other,__FILE__,"hurt" :),
           ]),
//3           
([ "action" : "$N大喝一聲,氣衝丹田,一招『"HIY"佛"NOR"動山河』順勢而出,只見掌影飄飄,當真有開山劈石之勢。",
                "dodge"      :   -30,
                "parry"      :   -20,
                "damage"     :    700,
                "force"      :    70,
                "damage_type":   "瘀傷",
                "post_action": (:  call_other,__FILE__,"hurt" :),
             ]),
//4             
([ "action" : "$N氣凝丹田,納氣迴身,掌緣微微上揚,『"HIY"佛"NOR"問迦羅』凌厲的掌氣已使$n擋無可擋,避無可避。",
                "dodge"      :   -50,
                "parry"      :   -30,
                "damage"     :    800,
                "force"      :    80,
                "damage_type":   "瘀傷",
                "post_action": (:  call_other,__FILE__,"hurt" :),
             ]),
//5             
([ "action" : "$N心中一動,揮掌擰身,突地向$n右肩『肩井』穴拍下,只見$n一個鷂子翻身,高高躍起,$N身隨意動,掌影順勢上揚,一招『迎"HIY"佛"NOR"西天』 ,便向$n衝去。",
                "dodge"      :   -50,
                "parry"      :   -20,
                "damage"     :    900,
                "force"      :    90,
                "damage_type":   "瘀傷",
                "post_action": (:  call_other,__FILE__,"hurt" :),
             ]),
//6             
([ "action" : "$N身形似箭,足不著地,掌緣隱隱有"HIY"佛"NOR"光圍繞,霎時一招失傳已久的『"HIY"佛"NOR"光普照』,自掌中發出,驚雷般的向$n直射而去。",
                "dodge"      :   -60,
                "parry"      :   -20,
                "damage"     :    1000,
                "force"      :    100,
                "damage_type":   "瘀傷",
                "post_action": (:  call_other,__FILE__,"hurt" :),
             ]),
//7             
([ "action" : "$N雙膝盤合,兩掌沉地,身形冉冉向上浮起。『天"HIY"佛"NOR"降世』挾著飛砂走石,雷霆萬鈞之勢撲面迎向$n。",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    1100,
                "force"      :    110,
                "damage_type":   "瘀傷",
                "post_action": (:  call_other,__FILE__,"hurt" :),
             ]),
//8             
([ "action" : "$N左手離火,右手玄冰,臉色忽青忽紅,赫然便是如來秘技之『萬"HIY"佛"NOR"朝宗』,煞時間天地變色,"HIY"佛"NOR"影飄然,只見$n低下斗大的汗珠,如墜煉獄,如墮冰窟。",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    1200,
                "force"      :    120,
                "damage_type":   "瘀傷",
                "post_action": (:  call_other,__FILE__,"hurt" :),
             ]),
//9             
([ "action" : "$N心\如\止水,拈葉微笑。低誦一聲『 "HIY"佛"NOR" 法 無 邊 』,只見$N"HIY"佛"NOR"光聚頂,祥瑞之氣環身。便在此時,$n膽顫驚叫『如來..如來再現』,霎時$N雙眼精光暴射,喝道:『八式齊發,毀天滅地』,渾身"HIY"佛"NOR"影幢幢,真氣自掌中激射而出。",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    1300,
                "force"      :    130,
                "damage_type":   "瘀傷",
               // "post_action": (: conti :),
             ]),
  });

void hurt(object me,object victim,object weapon,int damage)
{
	int i;
	int sklevel; 
	damage= random(90000);
	sklevel = (int)(me->query_skill("seventy-two",1)/10);
	if(sklevel > 1)
		{
			if(random (10)> 3)
				{
					for(i=1;i<=20;i++)
					{
            message_vision(HIW"$N緩緩的蹲下，左手展掌於前，右手展掌於後，看你蓄勢待發的樣子，難不成這就是傳說中的\n
"HIY"大豪院流"HIW"奧義－\n
                      "HIM"『"HIG"真空"WHT"殲"HIC"風"HIR"衝"HIM"』"HIW"

只見$N掌前出現一道"HIG"真空"HIW"龍捲風，霸凌無情的向$n捲襲而去！\n"NOR,me,victim);
						victim->receive_wound("kee",damage,me);
						COMBAT_D->report_status(victim);     
					}
				}
		}
}

void conti(object me, object victim, object weapon, int damage)
{
        int i;
        int level=(int)(me->query_skill("seventy-two",1)/10);
        if (level > 6)
        {
  if( me->query_temp("rulai") == 0 && me->query("class")=="bonze" )
          {
              me->set_temp("rulai",1);
              message_vision(sprintf("\n$N一手指天，一手指地，大喝一聲"HIB"『"HIR"上"HIC"天"HIR"下"HIG"地"HIW"，唯"HIY"我"HIW"獨尊！"HIB"』"NOR"\n"),me);
              for(i=1;i<=10;i++)
              COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
              me->delete_temp("rulai");
          }
        } 
}
mapping query_action(object me,object weapon)
{
int skill_level, limit;
object victim;
        victim = offensive_target(me);
        
        skill_level = (int)(me->query_skill("rulai", 1));
        limit= (int)(skill_level/10);
        // 殺氣少攻擊變多 1/3 的出現機會
        if(me->query("bellicosity") < 50 && random(100) < 30 && limit > 7 )
        {
            me->set_temp("rulais",1);
            message_vision(HIC"\n\n$N臉露慈笑，一陣祥和之氣從$N的身上顯現出來，但手中的掌力卻越摧越強！\n"NOR,me,victim);
            COMBAT_D->do_attack(me,victim , weapon, TYPE_QUICK);
            me->delete_temp("rulais",1);
        }
        if (limit < 4 )
                return action[random(4)];
        if (limit < 7 )
                return action[random(limit)];
        else
                return action[random(5)+4];
}

int valid_enable(string usage) 
{
       return (usage=="unarmed")||(usage=="parry");
}
int valid_learn(object me)
{
     return 1;
}
int practice_skill(object me)
{
        return 1;
}


