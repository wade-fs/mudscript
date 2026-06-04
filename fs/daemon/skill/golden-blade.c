//金風細雨樓skill 之 金訣刀法
//這是金風細雨樓一般護衛的skill
//增加敘述的顏色 作為金刀門三刀流的輔助skill by blazakira 2011/9/17

#include <combat.h>
#include <ansi.h>
inherit SKILL;

mapping *action = ({
  (["action"      : MAG + "$N" + MAG + "指劃刀尖，瞬間金光刺目，一式『" + HIG + "金尖飛閃" + MAG + "』直指向天劃出月弧彎皓，橫掃$n" + MAG + "$l。" + NOR,
    "damage"      : 90,
    "force"       : 90,
    "damage_type" : "砍傷"
  ]),
  (["action"      : MAG + "$N" + MAG + "使出了一式『" + HIR + "金鱗紅夏" + MAG + "』，刀刃一側向前突進橫掃，瞬間回刀欺身下轉，連砍$n" + MAG + "下盤。" + NOR,
    "damage"      : 90,
    "force"       : 90,
    "damage_type" : "割折"
  ]),
  (["action"      : MAG + "$N" + MAG + "側刀成臂飛天回身狂旋，刀光纏環，一式『" + HIC + "金羽游空" + MAG + "』繞轉連環刀氣，$n" + MAG + "大意突入，反遭刀氣撕裂捲殺。" + NOR,
    "damage"      : 90,
    "force"       : 90,
    "damage_type" : "割傷"
  ]),
  (["action"      : MAG + "$N" + MAG + "飛身閃避，$n" + MAG + "立即高躍追來，$N" + MAG + "瞬間迴轉使出一式『" + HIY + "金翼雙返" + MAG + "』，以刀鞘化解$n" + MAG + "的力求道，刀尖直指$n" + MAG + "腦門。" + NOR,
    "damage"      : 90,
    "force"       : 90,
    "damage_type" : "割折"
  ]),
  (["action"      : MAG + "$N" + MAG + "力聚雙手氣傳刀鋒，縱落長弧使出一式『" + HIB + "金弓雁落" + MAG + "』，刀氣若彎弓直向$n" + MAG + "追去。" + NOR,
    "damage"      : 90,
    "force"       : 90,
    "damage_type" : "砍傷"
  ]),
});

int valid_enable(string usage)
{
  return usage=="blade" || usage=="parry" || usage == "secondary_blade" || usage == "third_blade";
}

mapping query_action(object me, object weapon)
{
  return action[random(sizeof(action))];
}
