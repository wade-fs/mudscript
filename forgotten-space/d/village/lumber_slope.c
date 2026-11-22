// d/village/lumber_slope.c
// 黑石鋪・西嶺伐木雜坡與土炭窯（生計燒炭支翼）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石鋪・西嶺伐木雜坡");
    set_long("破落道觀山腳西側一片向陽緩坡，生長著雜亂矮櫟木與耐燒的青岡木。\n"
             "坡坳裡挖著兩口土坯砌成的傳統悶炭窯 (kiln)，窯口正往外滲著細細青煙。\n"
             "鐵匠鋪冬季的木炭與採石場烤火的碎炭大半出於此處，地上整齊碼著剛劈好的乾柴。\n"
             "向北走向【村尾土地廟】，向東爬上石階進入【破落道觀・三清偏殿】。\n");

    set_exits(([
        "north": "/d/village/earth_shrine.c",
        "east":  "/d/village/daoist_temple.c",
    ]));

    set("is_outdoor", 1);
    set_touch("default", YEL "土炭窯外泥壁溫熱乾燥，摸上去沾一手細膩黑炭灰與粗糙櫟樹皮。" NOR);
    set_smell("default", HIR "濃郁醇厚的硬木燻煙味與青岡木樹脂燒焦後的清苦焦香瀰漫坡地。" NOR);
    set_listen("default", WHT "窯腹裡傳來硬木悶燒時細微的「劈啪」爆響與山坡灌木叢裡的風聲。" NOR);

    mapping burn_rule = ([
        "targets": ({ "charcoal", "kiln", "wood", "木炭", "" }),
        "sp_cost": 12,
        "sensory_msg": YEL "你拿長鐵鉤撥開土窯密封泥口，迎著滾燙焦香夾出一筐烏黑錚亮、敲之有金石聲的硬木好炭！" NOR,
        "train_stat": ([ "con": 8, "str": 8 ]),
        "exp_gain": 12,
        "quest_verb": "burn",
        "quest_target": "charcoal"
    ]);
    add_action_rule("burn", burn_rule);
    add_action_rule("燒炭", burn_rule);
}
