// yu-needle
// 七奇針訣--- 手鍼(unarmed), 針鍼(stabber)
// by adam..

#include <ansi.h>
#include <combat.h>
inherit SKILL;

void bleed(object me, object victim, object weapon, int damage);

string *parry_msg=
    ({
   "$n身軀一引，指間$w平平搭在$N的武器上，一招『"HIM" 攔雀尾"NOR" 』將$N的武器曳了開去。",
   "$n將身體靠向$N，一招『"HIC" 沾衣十八跌 "NOR"』，將$N黏在原地，使不開招式!",
   "$n手中$w上下舞動，一招『"HIW" 飛瀑長虹"NOR" 』, 逼得$N不得不守住自身!",
   "$n把手中的$w舞成圓環一招『"HIB" 雲迴圓月 "NOR" 』，將$N的攻勢盡數擋了下來。",
   "$n以靜制動，手中$w平舉胸前，一招『"CYN" 如封似閉"NOR" 』，化解了$N的攻勢!",
    });

//unarmed, stabber_action

mapping *action = ({
([ "action":"$N一招『"HIW" 白蛇吐信"NOR" 』，下身稍曲，步履前跨，雙掌微分，手指尖往$n的胸前『"BLINK+HIC" 鳩尾穴"NOR" 』用力戳了去!",
        "dodge": -10,
        "parry": -20,
        "damage": 30,
        "force":  50,
        "damage_type":  "刺傷",
]),

([ "action":"$N手掌一張，一式『"HIR" 惡虎撲羊"NOR" 』，縱身一跳，由上往下向$n的頭頂『"BLINK+HIY" 百會穴"NOR" 』撲了去!",
        "dodge": -20,
        "parry": -10,
        "damage": 40,
        "force": 130,
        "damage_type": "刺傷",
]),

([ "action":"$N雙手一拉一按一壓，將$n的左手背『"BLINK+MAG" 合谷穴"NOR" 』制住，往外迴轉一圈，用力地將$n拋了開去!",
        "dodge": -30,
        "parry": 20,
        "damage": 50,
        "force": 180,
        "damage_type": "摔傷",
]),
([ "action" : "$N拗膝微蹲，倏地身軀一轉，繞到了$n的背後，中指向$n背後『"BLINK+HIW" 命門穴"NOR"』戳了去!",
        "dodge": -30,
        "parry": -10,
        "damage": 90,
        "force": 240,
        "damage_type": "刺傷",
]),
([ "action" : "$N身行突然地往後退了數步，$n跟進，忽然$N身行立停，手肘一曲，轉退為進，肘尖往$n腹部『"BLINK+HIR" 氣血穴"NOR" 』急頂而去!",
        "dodge": -40,
        "parry": 10,
        "damage": 110,
        "force": 300,
        "damage_type": "刺傷",
]),

([ "action":"$N呼嘯一聲，身法輕靈地往$n背後縱了去，雙手一打一戳，向$n的左邊『"BLINK+HIY" 太陽穴"NOR" 』，後腦『"BLINK+HIG" 風府穴"NOR" 』攻擊!",
        "dodge": 20,
        "parry": -10,
        "damage": 100,
        "force": 280,
        "damage_type": "刺傷",
]),
([ "action" : "$N一招『"HIM" 轉身六合"NOR" 』，身形輕輕左右搖擺，雙手上下翻動，急速地向著$n或拍打，或擒拿，往$n的全身各大要穴招呼!",
        "dodge": 20,
        "parry": 10,
        "damage": 70,
        "force": 220,
        "damage_type": "刺傷",
]),

//weapon_action

([ "action":"$N左手一揮，右手一勾，一招『"HIG" 飛花落葉"NOR"  』，把手中$w舞向$n的雙臂『"BLINK+HIG" 尺澤穴"NOR" 』!",
        "dodge": -20,
        "parry": -10,
        "damage": 60,
        "force":  140,
        "damage_type":  "刺傷",
]),

([ "action":"$N運使$w, 左右開弓, 綿綿不盡, 戳向$n的胸前『"BLINK+HIM" 膻中穴"NOR" 』, 背後『"BLINK+HIR" 腎內穴"NOR" 』",
        "dodge": -30,
        "parry": -10,
        "damage": 260,
        "force": 30,
        "damage_type": "刺傷",
]),

([ "action":"$N身軀一蹲，雙手掐$w，平平往前直刺，一招『"HIC" 海底翻花"NOR" 』蓄勢待發，迎向$n的腳底『"BLINK+HIC" 湧泉穴 "NOR"』",
        "dodge": -35,
        "parry": -20,
        "damage": 120,
        "force": 270,
        "damage_type": "刺傷",
]),
([ "action":"$N身法輕靈，一招『"HIY" 飛步拗鸞"NOR" 』，輕身一躍，$w刺向$n肩胛『"BLINK+HIW" 雲門穴"NOR"』，肩頂『"BLINK+WHT" 肩膠穴"NOR" 』",
        "dodge": 25,
        "parry": -10,
        "damage": 90,
        "force": 240,
        "damage_type": "刺傷",
]),
([ "action":"$N雙臂向外一張，一式『"HIC" 大鵬展翅"NOR" 』，緊跟一招『"HIM" 平沙落雁"NOR" 』，手中$w疾向$n的咽喉『"BLINK+HIB" 天突穴"NOR" 』刺去!\n",
        "dodge": -40,
        "parry": -20,
        "damage": 60,
        "force": 230,
        "damage_type": "刺傷",
]),
([ "action":"$N身形一轉，一式『"HIM" 轉身六合"NOR" 』，將手中$w舞成一股氣流，迴旋在$n四週，倏地一招『"HIY" 回望春月"NOR" 』，將$w刺向$n腦門『"BLINK+WHT" 天柱穴"NOR" 』，『"BLINK+HIC" 啞門穴"NOR" 』",
        "dodge": 20,
        "parry": -20,
        "damage": 50,
        "force": 130,
        "damage_type": "刺傷",
]),
([ "action":"$N大喝一聲『 絕命七針 』，鼓動全身內勁，手中$w舞成七點光點，分別

向$n的『"BLINK+HIR" 百會穴"NOR" 』，『"BLINK+WHT" 印堂穴"NOR" 』，『"BLINK+HIC" 天突穴"NOR" 』，『"BLINK+HIM" 膻中穴"NOR" 』，『"BLINK+HIY" 中脘穴"NOR" 』，

『"BLINK+MAG" 鳩尾穴"NOR" 』，『"BLINK+HIR" 氣海穴"NOR" 』，急急突刺!",
        "dodge": -30,
        "parry": -20,
        "damage": 190,
        "force":350,
        "damage_type":"刺傷",
        "post_action": (: bleed :),
]),
});

//超強攻擊

void bleed(object me, object victim, object weapon, int damage)
{
        if(damage > 40)
         {
          victim->apply_condition("bleeding", random((int)damage / 10 +
          (int)me->query_skill("yu-needle",1)/10));
          message_vision(sprintf("$N『 絕命七針 』刺透了$n身上的任脈大穴, $n的身上血斑點點。\n"),me,victim);
         }
}

mapping query_action(object me, object weapon)
{

        object wea=me->query_temp("weapon");

        if( wea!=0)
            return action[random(7)+7];
        else
          return action[random(7)];
}
                                        

int valid_enable(string usage)
{
        object me=this_player();
        object wea=me->query_temp("weapon");
         {
          if(wea!=0)
          if(wea->query("skill_type")=="stabber")
           {
//這一行表示有拿 needle
            me->map_skill("stabber","yu-needle");
            me->map_skill("parry","yu-needle");
            me->map_skill("unarmed",0);
            return (usage=="stabber")||(usage=="parry");
           }
//此行以下表空手
          me->map_skill("unarmed","yu-needle");
          me->map_skill("stabber",0);
          me->map_skill("parry",0);
          return (usage=="unarmed");
         }
        return (usage=="unarmed");
}

int practice_skill(object me)
{
        if(!me->query_temp("weapon") || !me->query_temp("secondary_weapon") )
          return notify_fail("練七奇炙針訣還是要拿根針吧!....\n");
        if( (int)me->query("gin") < 5 )
          return notify_fail("你的精不夠﹐無法練習。\n");
        if( (int)me->query("kee") < 30 )
          return notify_fail("體力不夠囉! 休息一下再繼續練吧.\n");
        if( (int)me->query("force") < 1 )
          return notify_fail("目前內力不足,休息一會兒再練吧.\n");
        me->receive_damage("gin", 5);
        me->receive_damage("kee", 30);
        me->add("force", -1);
        return 1;
}

//parry_action_randon

int query_parry_msg(string limb)
{
//                return parry_msg[random(sizeof(parry_msg))];
return 1;
}
