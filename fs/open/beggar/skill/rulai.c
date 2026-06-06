// 如來神掌  by weiwei and smooth
#include <combat.h>
inherit SKILL;

void ru10(object me, object victim, object weapon, int damage);
void conti(object me, object victim, object weapon, int damage);

mapping *action = ({
([ "action" : "$N吐氣揚眉,身形一頓,一道金光自右掌中浮出,正是一招 『佛光初現』。",
                "dodge"      :   -30,
                "parry"      :   -20,
                "damage"     :    50,
                "force"      :    50,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N閉目合眉,雙掌合什,倏然欺身而上,一招  『金頂佛燈』,$n已籠罩$n周身七十二大穴。",
                "dodge"      :    -30,
                "parry"      :    -20,
                "damage"     :     60,
                "force"      :     60,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N大喝一聲,氣衝丹田,一招 『佛動山河』順勢而出,只見掌影飄飄,當真有開山劈石之勢。",
                "dodge"      :   -30,
                "parry"      :   -20,
                "damage"     :    70,
                "force"      :    70,
                "damage_type":   "瘀傷",
             ]),
([ "action" : "$N氣凝丹田,納氣迴身,掌緣微微上揚, 『佛問迦羅』凌厲的掌氣已使$n擋無可擋,避無可避。",
                "dodge"      :   -50,
                "parry"      :   -30,
                "damage"     :    80,
                "force"      :    80,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N心中一動,揮掌擰身,突地向$n右肩『肩井』穴拍下,只見$n一個鷂子翻身,高高躍起,$N身隨意動,掌影順勢上揚,一招 『迎佛西天』 ,便向$n衝去。",
                "dodge"      :   -50,
                "parry"      :   -20,
                "damage"     :    90,
                "force"      :    90,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N身形似箭,足不著地,掌緣隱隱有佛光圍繞,霎時一招失傳已久的[佛光普照] ,自掌中發出,驚雷般的向$n直射而去。",
                "dodge"      :   -60,
                "parry"      :   -20,
                "damage"     :    100,
                "force"      :    100,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N雙膝盤合,兩掌沉地,身形冉冉向上浮起。 『天佛降世』挾著飛砂走石,雷霆萬鈞之勢撲面迎向$n。",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    110,
                "force"      :    110,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N左手離火,右手玄冰,臉色忽青忽紅,赫然便是如來秘技之 『萬佛朝宗』 ,煞時間天地變色,佛影飄然,只見$n低下斗大的汗珠,如墜煉獄,如墮冰窟。",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    120,
                "force"      :    120,
                "damage_type":   "瘀傷",
           ]),
([ "action" : "$N心如止水,拈葉微笑。低誦一聲 『 佛 法 無 邊 』,只見$N佛光聚頂,祥瑞之氣環身。便
在此時,$n膽顫驚叫『如來..如來再現』,霎時$N雙眼精光暴射,喝道:『八式齊發,毀天滅地』,渾身佛影幢幢,真氣自掌中激射而出。",
                "dodge"      :    -50,
                "parry"      :    -20,
                "damage"     :    130,
                "force"      :    130,
                "damage_type":   "瘀傷",
                "post_action": (: conti :),
           ]),
  });

void conti(object me, object victim, object weapon, int damage)
{
        int i;
        int level=(int)(me->query_skill("rulai",1)/10);
        if (level > 6)
        {
  if( me->query_temp("rulai") == 0 && me->query("class")=="bonze" )
          {
              me->set_temp("rulai",1);
              message_vision(sprintf("\n$N一手指天，一手指地，大喝一聲 『 上天下地，唯我獨尊！ 』\n"),me);
              for(i=1;i<=10;i++)
        COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
              me->delete_temp("rulai");
             me->start_busy(1);
          }
        } 
}
mapping query_action(object me,object weapon)
{
int skill_level, limit;
        skill_level = (int)(me->query_skill("rulai", 1));
        limit= (int)(skill_level/10);
        if (limit < 4 )
                return action[random(4)];
        if (limit < 7 )
                return action[random(limit)];
        else
                    return action[random(4)+5];
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
        if( me->query_temp("weapon") || me->query_temp("secondary_weapon") )
          return notify_fail("練如來神掌還是要空手吧....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("你的精不夠﹐無法練習。\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("目前內力不足,休息一會兒再練吧.\n");
        if( me->query("max_force") < 3000 )
          return notify_fail("你的內力不夠高,強加練習將會走火入魔。\n");
         if( me->query_skill("literate",1) < me->query_skill("rulai",1) )
          return notify_fail("你的知識不足以體會如來神掌的高深。\n");
        me->receive_damage("gin", 5);
        me->add("force", -1);
        return 1;
}


