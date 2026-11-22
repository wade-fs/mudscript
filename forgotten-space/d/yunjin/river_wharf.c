// d/yunjin/river_wharf.c
// 雲津城・冰河木筏碼頭（Tier 2 北境邊城水上生計與凍木貨運線）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津城・冰河木筏碼頭");
    set_long("萬山廣場西南側沿著尚未完全封凍的雲津冰河修建的一座重木樁碼頭。\n"
             "河面上漂浮著白森森的碎冰排，十幾隻吃水深沉的破冰平底貨船正抓緊最後水期搶卸北境紅杉木與獸皮。\n"
             "穿著破羊皮襖的船工與腳夫喊著沙啞號子扛木上岸，每一步都要提防棧板上結出的薄冰。\n"
             "向東北沿石階上行即是人聲鼎沸的【萬山廣場】。\n");

    set_exits(([
        "northeast": "/d/yunjin/wanshan_square.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", HIW "凍得堅硬如鐵的棧板木緣覆著一層薄霜，抓握帶冰碴的粗麻纖繩刺骨生痛。" NOR);
    set_smell("default", CYN "刺鼻清冽的冰雪寒氣、濕冷紅杉木脂味與岸邊火堆烤魚的淡淡煙火味撲面而來。" NOR);
    set_listen("default", CYN "碎冰相撞的喀啦脆響與平底木船撞擊護岸樁子的沉重悶響此起彼伏。" NOR);

    mapping haul_rule = ([
        "targets": ({ "timber", "wood", "木料", "貨包", "" }),
        "sp_cost": 12,
        "sensory_msg": YEL "你咬牙踩實結霜的木棧板，搭肩協助船工將一根沉重凍紅杉扛上岸邊木架，口鼻噴出長長一團白霧。" NOR,
        "train_stat": ([ "str": 12, "con": 10 ]),
        "exp_gain": 16,
        "quest_verb": "haul",
        "quest_target": "timber"
    ]);
    add_action_rule("haul", haul_rule);
    add_action_rule("扛貨", haul_rule);

    spawn_npc("/clone/npc/folk/yunjin_wharf_master.c");
}
