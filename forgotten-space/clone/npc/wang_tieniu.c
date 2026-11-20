// /clone/npc/wang_tieniu.c
// 王鐵牛・八荒霸戰派狂猛武修 (wang_tieniu) - 問道天台青鋼演武場 (Ch.114)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("王鐵牛");
    set_short(RED "八荒霸戰派猛漢" NOR " 王鐵牛");
    set_long("身高近九尺的巨漢，雙手輪動兩柄重達兩百斤的血紋宣花大斧，平常修為不過八十出頭，\n"
             "今日臨場前卻服下過量「急鎮丸」兼不明烈性催血劑虛衝至近二階九十重（Lv.89），\n"
             "雙目赤紅喘如暴牛，護心鋼甲縫裡隱隱飄出一股腥甜硫磺藥氣！\n");
    set_id(({ "wang_tieniu", "wang tieniu", "tieniu", "王鐵牛", "猛漢" }));

    setup_archetype("K", 89);
    set("class", "wu");
    set("faction", "bahuang");
    set("roles", ({ "challenger", "fighter" }));
    set("home_room", "/d/yunjin/tournament_combat_arena.c");

    set_exp_reward(1950);
    set_gold_reward(380);
    set_drop_list(({ "/clone/item/wang_red_pill_vial.c" }));
    set_respawn(120);
    add_response(({ "急鎮丸", "丸藥", "霸戰派" }),
        "王鐵牛護心甲被震裂後被杜青禾灌下清熱降燥湯救醒，抱頭啞聲懊悔：\n"
        "「長老只說……吞了這瓷瓶裡的紅色強血丹能撐著不吐血奪下『破軍領銜令』……誰知氣血差点炸散五臟！」");
}
