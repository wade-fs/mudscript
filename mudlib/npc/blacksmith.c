#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("鐵匠 索林");
    set_short(YEL("粗壯的矮人鐵匠") + " 索林");
    set_long("這是一位典型的矮人，紅色的鬍鬚紮成辮子，手臂肌肉隆起。\n他正滿頭大汗地敲打著一塊通紅的生鐵。\n");
    set_id(({"thorin", "blacksmith", "dwarf", "鐵匠"}));
    set_race("dwarf");
    set_level(25);
    set_stat(STAT_STR, 30);
    set_stat(STAT_CON, 30);
    recalc_stats();
    hp = max_hp;

    // 🚀 新增：重生與走動
    set_respawn(60);      // 60秒重生
    set_wander_chance(5); // 5% 機率走動
    set_move_range(3);    // 最多離家 3 格

    add_response(({ "武器", "weapon" }), ({
        "想要好武器？你找對人了！",
        "我打造的劍可以輕易劈開史萊姆的皮。",
        "看看那邊架子上的短劍，那是我的得意之作。"
    }));
    add_response(({ "防具", "armour" }), ({
        "雖然我更擅長打造武器，但防具我也略知一二。",
        "防禦跟進攻一樣重要，別忘了買件皮甲防身。"
    }));
    add_response("索林", "沒錯，我就是索林。想要委託打造什麼嗎？");
}
