// d/city/west/dao_gate.c
// 宣道司外門牌樓 (法道世俗門戶)

#include "/include/ansi.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("金石宣道司・外門牌樓");
    set_long("此處高聳著一座以漢白玉巨石雕琢的三間四柱沖天牌樓。\n"
             "牌樓橫額鐫刻「周虛微茫」四個古篆金字，散發著淡淡清冷道意。\n"
             "空氣中的紅塵喧囂濁氣在此驟減，隱約有玄鶴清唳與鐘磬長鳴之音相聞。\n"
             "向東走出牌樓直通中央青石廣場，往西穿過雲階大道進入宣道司正堂。\n");

    set_exits(([
        "east": "/d/city/center/square.c",
        "west": "/d/city/west/dao_hall.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", HIW "漢白玉牌樓石柱觸手生涼，篆刻筆畫凹槽細膩平順、不染絲毫市井塵灰。" NOR);
    set_smell("default", HIC "淡雅清冷的柏木靜香與山野露氣隔絕了中央廣場的喧鬧塵囂。" NOR);
    set_listen("default", HIC "牌樓檐角鐵馬在微風裡清越輕鳴，遠處隱約傳來鐘磬長響與玄鶴清唳。" NOR);

    mapping bow_rule = ([
        "targets": ({ "gate", "arch", "牌樓", "" }),
        "sp_cost": 2,
        "sensory_msg": HIC "你站在『周虛微茫』四字之下整衣微揖，浮躁心氣被這股清冷道意洗去幾分。" NOR,
        "train_stat": ([ "spi": 5 ]),
        "exp_gain": 5
    ]);
    add_action_rule("bow", bow_rule);
    add_action_rule("參拜", bow_rule);

    spawn_npc("/clone/npc/dao_tong.c");
}
