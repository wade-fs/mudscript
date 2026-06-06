// /cmds/std/map.c
// 地圖指令 - 移植自 fsmud

#include <globals.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg) {
    int range = 2; // 預設 5x5
    if (arg && arg != "") {
        range = to_int(arg);
        if (range < 1) range = 1;
        if (range > 5) range = 5; // 限制最大範圍避免洗頻
    }

    // 🚀 優先檢查是否在 LM 世界中
    object env = environment(me);
    if (env && env->query_is_lm_world()) {
        env->broadcast_map(me);
        return 1;
    }

    // 🚀 備援：嘗試載入 map_d
    object map_d = load_object("/secure/map_d");
    if (map_d) {
        write(map_d->draw_map(me, range));
    } else {
        write("目前此處無法顯示地圖。\n");
    }
    return 1;
}

string help() {
    return "【指令】\n" +
           "  map [範圍]    顯示目前位置周邊的小地圖。\n" +
           "  (提示：範圍可設定 1~5，預設為 2，即 5x5 的視野)\n";
}
