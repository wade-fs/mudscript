#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老闆 巴克");
    set_short(MAG("大腹便便的酒館老闆") + " 巴克");
    set_long("巴克是個典型的酒館老闆，有著圓滾滾的肚子和親切的笑容。\n他對每個客人都打招呼，似乎知道新手村所有的秘密。\n");
    set_id(({"buck", "bartender", "owner", "老闆"}));
    set_race("human");
    set_level(10);
    set_stat(STAT_STR, 15);
    set_stat(STAT_INT, 20);
    recalc_stats();
    hp = max_hp;

    // 🚀 重生與走動
    set_respawn(60);
    set_wander_chance(2); // 偶爾走出吧台透透氣
    set_move_range(1);    // 但不會離開酒館太遠

    add_response(({ "酒", "beer", "ale", "麥酒" }), ({
        "想要來一杯嗎？只要 5 個金幣。",
        "我的麥酒可是從遠方的矮人公會運來的。",
        "工作累了就該喝杯好酒！"
    }));
    add_response(({ "秘密", "secret", "情報" }), ({
        "如果你想知道點什麼，得先買杯酒再說。",
        "聽說最近東邊的森林不太平靜...",
        "別告訴別人是我說的，但北邊的山洞裡據說藏著寶藏。"
    }));
}
