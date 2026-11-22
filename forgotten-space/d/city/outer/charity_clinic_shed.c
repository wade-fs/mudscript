// d/city/outer/charity_clinic_shed.c
// 金石南關外・施藥義棚（Tier 1 無籍流民免費醫療與草藥熬製日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("南關外・施藥義棚");
    set_long("緊靠流民矮巷西頭支起的一座三面透風的油布草棚，棚柱上掛著幾把曬乾的\n"
             "野菊花、甘草與苦參。兩口破邊大砂鍋終年燉著給無錢就醫流民喝的清熱解毒粗湯 (medicine)，\n"
             "幾條舊木門板臨時拼成病榻，上頭躺著摔傷腿腳的拉車苦力與染寒咳嗽的老人。\n"
             "向東走回喧鬧卻冷濕的【流民賃居矮巷】。\n");

    set_exits(([
        "east": "/d/city/outer/tenement_alley.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", YEL "木門板病榻鋪著乾稻草，粗陶藥碗邊沿微缺卻洗刷得乾乾淨淨。" NOR);
    set_smell("default", HIG "淡淡甘草、金銀花與艾葉燒煙的清苦藥味，勉強壓住流民棚區的酸腐霉氣。" NOR);
    set_listen("default", WHT "砂鍋蓋噗噗冒氣的輕響、傷患低沉的呻吟與周伯溫聲細語的叮囑。" NOR);

    mapping brew_rule = ([
        "targets": ({ "medicine", "herb", "湯藥", "煎藥", "" }),
        "sp_cost": 6,
        "sensory_msg": HIG "你幫忙拉風箱顧火候，舀出一碗溫熱的甘草清熱粗湯自己也趁熱喝了半口，體內疲乏頓減。" NOR,
        "train_stat": ([ "per": 8, "sen": 6 ]),
        "exp_gain": 10
    ]);
    add_action_rule("brew", brew_rule);
    add_action_rule("煎藥", brew_rule);

    spawn_npc("/clone/npc/folk/charity_herbalist.c");
}
