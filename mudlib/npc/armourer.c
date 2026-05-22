#include "/include/config.h"
#include "/include/ansi.h"
inherit "/std/npc.c";

void create() {
    ::create();
    set_name("老闆 凱文");
    set_short(HIB("精明的防具店老闆") + " 凱文");
    set_long("凱文是個精明的生意人，總是帶著一副職業性的微笑。\n他對防具的構造瞭如指掌，能根據你的體型推薦最適合的裝備。\n");
    set_id(({"kevin", "armourer", "owner", "老闆"}));
    set_race("human");
    set_level(12);
    set_stat(STAT_INT, 18);
    set_stat(STAT_DEX, 15);
    recalc_stats();
    hp = max_hp;

    // 🚀 重生與走動
    set_respawn(60);
    set_wander_chance(2);
    set_move_range(1);

    add_response(({ "防具", "armour", "shield" }), ({
        "如果你想活得久一點，就得穿好一點的甲。",
        "我的皮甲都是用上等的魔獸皮製作的。",
        "盾牌在關鍵時刻能救你一命。"
    }));
}
