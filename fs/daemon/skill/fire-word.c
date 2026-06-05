inherit SKILL;

#include <ansi.h>

string *dodge_msg = ({

"
        " + HIW + "$n口唸〔" + HIR + "火神防字訣" + HIW + "〕,以" + HIG + "《" + HIY + "柳" + HIG + "》" + HIW + "字為主
                底盤猶如柳樹盤根,隨風搖曳" + NOR + "

只見$N的攻勢有如吹來的強風一般,$n彷彿柳樹隨風飄蕩,絲毫不受影響。\n",
"
        " + HIW + "$n口唸〔" + HIR + "火神防字訣" + HIW + "〕,以" + HIG + "《" + HIC + "風" + HIG + "》" + HIW + "字為主
                身行如風,飄逸四處,動靜自如" + NOR + "

$N來勢洶洶的攻勢,只穿過了$n的殘影,並無擊中$n。\n",
"
        " + HIW + "$n口唸〔" + HIR + "火神防字訣" + HIW + "〕,以" + HIG + "《" + NOR+GRN + "林" + HIG + "》" + HIW + "字為主
                腳踏幻影七星,幻化千身,$N猶如身處幻林之中" + NOR + "

$N慌張的亂了步伐,整個攻勢就此瓦解。\n",
"
        " + HIW + "$n口唸〔" + HIR + "火神防字訣" + HIW + "〕,以" + HIG + "《" + HIR + "火" + HIG + "》" + HIW + "字為主
                突然身體冒出熊熊烈火,眼暴紅光,口吐焰火" + NOR + "

$n將全身烈火聚集在雙臂上,以本身的內力與火勁將$N的攻勢給擊退了。\n",
"
        " + HIW + "$n口唸〔" + HIR + "火神防字訣" + HIW + "〕,以" + HIG + "《" + NOR+YEL + "山" + HIG + "》" + HIW + "字為主
                聚氣丹田,腳跨雙星,不動如山" + NOR + "

$N的攻擊彷彿擊中一座山一般,無法動搖到$n分毫。\n",
});


int valid_enable(string usage){
        return ( usage=="dodge" || usage=="move" || usage=="parry");
}

int practice_skill(object me){
        return notify_fail(HIR + "火神防字訣" + NOR + "無法自我練習增進。\n");
}

string query_dodge_msg(string limb){
        return dodge_msg[random(sizeof(dodge_msg))];
}
