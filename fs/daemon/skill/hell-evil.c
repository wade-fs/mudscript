// 地獄血劫手 by roger
// 這是魔界mob 的專用skill之一
#include <ansi.h>
#include <combat.h>
inherit SKILL;
string bleed();

string *parry_msg= ({
   "$N雙手往上一翻, 雙腳蹲了個馬步, 使出一招「  妖魔聚鼎  」, 將妖氣凝聚於全身上下, 硬生生的把$n的招式接了下來!\n",
   "$N伸出右手拇指, 食指, 中指, 使出一招「  群妖攔路  」, 三指由中宮飛快的探向$n的咽喉, 破解了$n的攻勢。\n",
});

mapping *action = ({
([ "action" : "$N身子半伏, 倏的躍了起來, 從空中使出一招「  魑魅魍魎  」, 右爪迅速的從$n頭頂上抓了下來!\n" + NOR,
        "dodge":   -30,
        "parry":   -20,
        "damage":   180,
        "force":    250,
        "damage_type" : "臉部抓傷",
]),

([ "action" : "$N雙爪向內一抱, 身子後拱, 一式「魔性狂發」, 縱身向$n躍了過去, 雙爪外分, 朝$n的脖子擊了下去!\n" + NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   180,
        "force":    250,
        "damage_type" : "脖子扭傷",
]),

([ "action" : "$N加快起腳步, 使出一招「妖遁魔現」, 繞著$n急速旋轉著, 忽然間似有千萬隻手爪向$n襲擊而來, 分擊$N身上各個不同要害。\n" + NOR,
        "dodge":   -30,
        "parry":    20,
        "damage":   190,
        "force":    250,
        "damage_type" : HIR + "傷口潰爛" + NOR,
]),

([ "action" : "$N一招「群魔亂舞」使出, 只見殘光亂影, $N的影子充斥著$n的眼簾之中, 渾不知$N會從何處發動攻擊, 忽然$N一躍身, 已繞到$n身後, 向$n腦後擊了下去。\n" + NOR,
        "dodge":    -10,
        "parry":    10,
        "damage":   200,
        "force":    250,
        "damage_type" : HIR + "頭破血流" + NOR,
]),

([ "action" : "$N左爪內彎, 右爪上提, 腳底遊走著, 正是一式「  妖助魔勢氣更燄  」, 左爪擊向$n的天靈蓋\上, 跟著又向右邊略移半步, 提起右爪攻向$n的左肩。\n" + NOR,
        "dodge":   -20,
        "parry":   -10,
        "damage":   190,
        "force":    250,
        "damage_type" : "破體之傷",
]),

([ "action" : "$N爪成刀掌, 一招「  煉獄妖斬手  」使將出來, 橫劈直砍的攻向$n的面, 手, 胸, 腹, 足等各個部位, 左腳爪則是一式「  帝魔橫掃腿  」橫掃$n的下盤。\n" + NOR,
        "dodge":   -30,
        "parry":   -10,
        "damage":   200,
        "force":    250,
        "damage_type" : "詭異刀傷",
]),

([ "action" : "$N揮舞著雙爪, 一招「  天魔盜明珠  」竄了出來, 雙爪直逼$n中宮下盤二處, $n顯得難以應付, $N右爪攻勢忽的一轉, 改為直取$n雙目, 逼的$n步步後退。\n" + NOR,
        "dodge":   -35,
        "parry":   -20,
        "damage":   180,
        "force":    240,
        "damage_type" : HIR + "暫時失明" + NOR,
]),

([ "action" : HIB + "$N忽然停止一切攻擊, 只是靜靜的凝視著$n, 這正是一招「  魔影幻攻心  」, $n漸漸的感到口乾舌燥, 心裡面有如千萬條蟲蟻咬鍥著, 麻癢難當。\n" + NOR,
        "dodge":   -40,
        "parry":   -20,
        "damage":   190,
        "force":    250,
        "damage_type" : HIW + "無影之傷" + NOR,
]),

([ "action" : HIW + "$N提氣大喝一聲! 使出一招「  惡妖探路	」急攻$n胸前, 接著又是一招「  小鬼拜閻王  」直取$n右肩臂膀, 此二式來勢洶"+"湧, 令人防不勝防, 忽的$N招式一變, 右爪使「  無影魔幻掌  」左爪主「  七煞火燄掌  」, 掌風飄移不定, 分別攻向$n的"+"頭頂及背部,
 下盤則是踩著「  魔十二宮禁步  」, 不斷的向$n踢去, 瞬間五式變化, , 眼見$n以難以躲避了。\n" + NOR,
        "dodge":   -15,
        "parry":   -10,
        "damage":   180,
        "force":    250,
        "damage_type" : HIR + "大量失血" + NOR,
]),
});

// can enable

int valid_enable(string usage)
{
        return (usage=="unarmed")||(usage=="parry");
}

// action message

mapping query_action(object me, object weapon)
{
        object *enemy, vim;
        int i, j, gin, kee, sen;

           enemy = me->query_enemy();
        if(random(10) > 8 && sizeof(enemy)) {
           j = random(sizeof(enemy));
           vim = enemy[j];
           message_vision("$N的身上發出一股魔風，瞬時間$n的狀態已經大不如前了\n",me,vim);
           gin = vim->query("eff_gin");
           kee = vim->query("eff_kee");
           sen = vim->query("eff_sen");

           vim->receive_damage("gin", gin/15);
           vim->receive_damage("kee", kee/15);
           vim->receive_damage("sen", sen/15);
           me->add("force", (int) -me->query("force")/20);
           COMBAT_D->report_status(vim, 1);
        }
       return action[random(sizeof(action))];
}


string query_parry_msg(string limb)
{
        return parry_msg[random(sizeof(parry_msg))];
}
