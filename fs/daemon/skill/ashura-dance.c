//修羅之舞(Ashura-Dance) Edit by del, ACKY
#include <ansi.h>
inherit SKILL;

mapping *action = ({
        ([      "action":
"$N隨意揚起衣袖，忽快忽慢的踏著舞步，正是" + HIM + "修羅之舞" + NOR + "中的" + HIC + "『魅』" + NOR + "，"
"正當\n$n失神之際，$N雪白的雙掌已經逼近$n的$l。",
                "damage": 220,
                "force" : 220,
                "damage_type": "瘀傷"
        ]),
        ([      "action":
"$N快速揮動手中的衣袖，使出" + HIM + "修羅之舞" + NOR + "中的" + HIG + "『惑』" + NOR + "，身形飄忽，轉眼"
"間已經到了\n$n的周圍，翻身一掌打向$n的$l。",
                "damage": 240,
                "force" : 240,
                "damage_type": "瘀傷"
        ]),
        ([      "action":
"$N使出" + HIM + "修羅之舞" + NOR + "中的" + HIB + "『誘』" + NOR + "，雪白的臉頰突然泛起兩道紅霞，羞怯的"
"望著\n$n的雙眼，正當$n心神蕩漾之際，$N的雙掌已經抵在$n的背後。",
                "damage": 260,
                "force" : 260,
                "damage_type": "內傷"
        ]),

        ([      "action":
"$N緩緩的踏著舞步，隨著節奏踏起" + HIM + "修羅之舞" + NOR + "中的" + HIW + "『柔』" + NOR + "，臉上純真的"
"臉龐讓\n$n戒心全失，突然間節奏一換，$N的雙手如天羅地網般將$n團團包圍。",
                "damage": 280,
                "force" : 280,
                "damage_type": "內傷"
        ]),

        ([      "action":
HIM + "隨著周圍傳來的聲樂，$N開始跳起修羅之舞中的" + HIR + "『艷』" + HIM + "，只見$N將身"
"上的衣衫\n漸漸褪去，露出雪白的肌膚，看得$n內息翻騰無法抑制。" + NOR,
                "damage" : 300,
                "force"  : 300,
                "damage_type" : "七孔流血"
        ]),

});

int valid_enable(string usage)
{
        return (usage=="unarmed") || (usage=="parry");
}

mapping query_action(object me, object weapon)
{
        return action[random(sizeof(action))];
}

