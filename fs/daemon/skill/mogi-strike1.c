// 血溶掌 by roger
// 這是魔界mob 的專用skill之一
#include <ansi.h>
#include <combat.h>
inherit SKILL;

void blood(object me, object victim, object  weapon, int damage);

string *parry_msg= ({
   "$n雙手往上一翻, 雙腳蹲了個馬步, 使出一招「妖魔聚鼎」, 將妖氣凝聚於全身上下, 硬生生的把$N的招式接了下來!\n",
   "$n伸出右手拇指, 食指, 中指, 使出一招「群妖攔路」, 三指由中宮飛快的探向$N的咽喉, 破解了$N的攻勢。\n",
});

mapping *action = ({
([ "action" : HIR"$N伸手虛拍一掌，使出"HIM"『"HIR"血溶掌"HIM"』"HIR"中的"HIM"『"HIR"泣血攻心"HIM"』"HIR"$n立時臉色一變，胸中氣血翻騰，口中鮮血狂吐!!\n"NOR,
        "dodge":   -30,
        "parry":   -20,
        "damage":   220,
        "force":    270,
        "post_action":  (:blood:),
        "damage_type" : "氣血失調"
        
]),

([ "action" :HIR"$N雙掌猛推，一招"HIM"『"HIR"血溶掌"HIM"』"HIR"中的"HIM"『"HIR"漫天血影"HIM"』"HIR"使出來只見$N的雙掌噴出稠血濃霧，$n被籠罩其中只覺功\力快速流失\n"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   210,
        "force":    270,
        "damage_type" : "血霧之毒"
]),

([ "action" : HIR"$N大喝一聲，一掌"HIM"『"HIR"血氣逼人"HIM"』"HIR"掌風中挾著濃濃血霧氣勢駭人地往$n的胸口狂轟而去\n"NOR,
        "dodge":   -30,
        "parry":    20,
        "damage":   230,
        "force":    270,
        "damage_type" : "瘀傷"
]),

([ "action" : HIR"$N使出"HIM"『"HIR"血溶掌"HIM"』"HIR"中的"HIM"『"HIR"煞血一指"HIM"』"HIR"，指力千斤直往$n的胸口直刺而去，只見一條筆直的血箭由$n的胸口射出...\n"NOR,
        "dodge":    -30,
        "parry":    -20,
        "damage":   220,
        "force":    270,
        "damage_type" : "刺傷"
]),

([ "action" :HIR"$N內息一轉，使出"HIM"『"HIR"血溶掌"HIM"』"HIR"中的陰狠招數"HIM"『"HIR"純陰血氣"HIM"』"HIR"四周忽然氣溫急降，鬼哭神號聲音此起彼落，使的$n不禁嚇得面如土色!!傳說中此招者不但周身血脈被封，更日日被惡魂纏身不的安寧!!\n"NOR,
        "dodge":   -20,
        "parry":   -10,
        "damage":   190,
        "force":    250,
        "damage_type" : "心智受損"
]),

([ "action" :HIR"$N往$n的$l一抓，使出了"HIM"『"HIR"血溶掌"HIM"』"HIR"中人人聞之色變的"HIM"『"HIR"凝血神抓"HIM"』，"HIR"中此招者將於幾天內氣血滯行而死!!\n"NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   200,
        "force":    250,
        "damage_type" : "抓傷"
]),

});

void blood(object me, object victim, object  weapon, int damage)
{

 victim->apply_condition("ff_poison",2);
}
int valid_enable(string usage)
{
        return (usage=="unarmed")||(usage=="parry");
}


mapping query_action(object me, object weapon)
{
    return action[random(sizeof(action))];
}

string query_parry_msg(string limb)
{
    return parry_msg[random(sizeof(parry_msg))];
}
