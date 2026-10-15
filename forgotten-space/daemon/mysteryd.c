// daemon/mysteryd.c
// 《遺忘的世界》史前奇遇與歷史拼圖守護進程 (MYSTERY_D)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/object.c";

void create() {
    ::create();
}

// 判定玩家是否破除大清洗認知盲區
int check_amnesia_breakthrough(object who, int required_fate) {
    if (!who) return 0;
    int player_fate = who->query(STAT_FATE);
    return (player_fate >= required_fate);
}
