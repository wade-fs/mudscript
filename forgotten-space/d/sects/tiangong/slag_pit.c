// d/sects/tiangong/slag_pit.c
// 天工門・冷卻爐渣槽（Tier 2 鍛造工坊廢料冷卻場）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("天工門・冷卻爐渣槽");
    set_long("一處開鑿在岩壁凹槽裡的深長水泥石槽，槽底蓄著渾濁發黑、漂滿油花的冷卻水。\n"
             "天工鍛造院每日傾倒出的火紅礦渣與淬火後的廢水盡數排往此處，熱氣騰騰升起刺鼻白煙。\n"
             "牆邊立著長柄鐵耙與漏斗鐵網，偶爾能從冷卻礦渣裡撈出未完全熔化的小塊高純度玄鐵珠。\n"
             "向西穿過耐火磚通道即是【天工鍛造院】。\n");

    set_exits(([
        "west": "/d/sects/tiangong/forge_yard.c",
    ]));

    set("is_outdoor", 0);

    set_touch("default", RED "槽邊濕熱的黑岩壁燙得指節微微刺痛，鐵耙長柄裹著的隔熱草繩還在微微冒煙。" NOR);
    set_smell("default", YEL "滾燙礦渣落水炸起的硫磺濁煙、陳年冷卻油池臭味與鐵腥味直往鼻腔裡鑽。" NOR);
    set_listen("default", RED "「滋啦——！」鐵槽那頭不時傾倒下高溫礦渣，激起成團白霧與咕嘟滾沸的水響。" NOR);

    mapping quench_rule = ([
        "targets": ({ "slag", "iron", "爐渣", "淬火", "" }),
        "sp_cost": 10,
        "sensory_msg": RED "你抄起長柄鐵漏勺在混濁黑水裡翻找冷卻渣塊，忍著刺鼻白霧濾出幾粒泛青光的玄鐵珠。" NOR,
        "train_stat": ([ "con": 10, "str": 6 ]),
        "exp_gain": 12,
        "quest_verb": "quench",
        "quest_target": "slag"
    ]);
    add_action_rule("quench", quench_rule);
    add_action_rule("淬火", quench_rule);
}
