#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("藥劑師 艾拉");
    set_short(GRN("優雅的精靈藥劑師") + " 艾拉");
    set_long("這位精靈女性有著一頭金色的長髮，舉手投足間充滿了優雅。\n她正在細心地調配一種散發著微光的藥劑。\n");
    set_id(({"aela", "herbalist", "elf", "藥劑師"}));
    set_race("elf");
    set_level(20);
    set_stat(STAT_INT, 25);
    set_stat(STAT_WIS, 25);
    recalc_stats();
    hp = max_hp;

    // 🚀 新增：重生與走動
    set_respawn(60);      // 60秒重生
    set_wander_chance(3); // 3% 機率走動
    set_move_range(2);    // 最多離家 2 格

    add_response(({ "藥水", "potion", "藥劑" }), ({
        "如果你需要治療，我的藥水是全村最好的。",
        "調配藥劑需要極大的耐心與專注。",
        "雖然味道可能不太好，但效果絕對有保證。"
    }));
    add_response(({ "藥草", "herb" }), ({
        "我這裡有一些常見的藥草，如果你能幫我採些新鮮的野花回來就太好了。",
        "藥草的力量源自大自然的恩賜。"
    }));
}
