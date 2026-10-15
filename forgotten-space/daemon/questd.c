// daemon/questd.c
// 《遺忘的世界》主線任務推進守護進程 (QUEST_D)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

void create() {
    ::create();
}

// 判定玩家是否滿足 Tier 0 -> Tier 1 出鄉進城門檻
int can_enter_tier1(object who) {
    if (!who) return 0;
    int lv = who->query_level();
    if (lv >= 10 && who->query("quest/pass_village_ceremony")) {
        return 1;
    }
    return 0;
}
