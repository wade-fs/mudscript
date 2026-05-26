// /cmds/cmd_lm.c  ── 進入 Light Minecraft 世界 ───────────────
// 觸發詞：lm / minecraft
// 功能：將玩家傳送到 /area/lm/world.c

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object.c";

#define LM_WORLD "/area/lm/world"

int main(object me, string verb, string arg) {
    object world = find_object(LM_WORLD);
    if (!world) world = load_object(LM_WORLD);

    if (!world) {
        write(RED("錯誤：無法載入創界，請聯絡管理員。\n"));
        return 1;
    }

    // 已在創界內
    if (environment(me) == world) {
        write(YEL("你已經在創界之中了！輸入 ") +
              CYAN("mc map") + YEL(" 開啟地圖，") +
              CYAN("mc help") + YEL(" 查看指令。\n"));
        return 1;
    }

    write(
        "\n" + HIW("╔══════════════════════════════╗\n") +
        HIW("║  正在傳送至輕量創界 (LM)...  ║\n") +
        HIW("╚══════════════════════════════╝\n")
    );

    // 🚀 核心優化：紀錄進入前的房間路徑，以便稍後返回
    object current_room = environment(me);
    if (current_room && base_name(current_room) != LM_WORLD) {
        me->set_temp("lm_return_room", base_name(current_room));
    }

    if (me->move(world)) {
        world->look_room(me);
        write(HIG("歡迎來到輕量創界！\n") +
              "輸入 " + CYAN("mc map") + " 開啟圖形地圖，" +
              CYAN("mc help") + " 查看所有指令。\n" +
              "WASD 鍵可直接移動角色。\n\n");
    } else {
        write(RED("傳送失敗，請稍後再試。\n"));
    }

    return 1;
}

string *query_verbs() { return ({ "lm", "minecraft" }); }

string query_category() {
    return select_lang(([ "en": "World", "zh-TW": "創界", "zh-CN": "创界" ]));
}

string help() {
    return "【lm 指令】\n  lm    傳送至輕量創界 (Light Minecraft)。\n" +
           "  進入後使用 mc help 查看更多指令。\n";
}
