// /cmds/cmd_lm.c
// 前往創世神世界

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object.c";

int main(object me, string verb, string arg) {
    object world = find_object("/area/lm/world");
    if (!world) world = load_object("/area/lm/world");

    if (!world) {
        write(HIR("錯誤：無法載入創世神世界。\n"));
        return 1;
    }

    write(HIW("你閉上雙眼，感覺到四周的維度正在重組...\n"));
    write(HIG("歡迎來到輕量創世神世界！\n"));
    
    if (me->move(world)) {
        world->look_room(me);
    } else {
        write(RED("傳送失敗。\n"));
    }

    return 1;
}

string *query_verbs() { return ({ "lm", "minecraft" }); }
string query_category() { return "Fantasy Space"; }

string help() {
    return "【指令】\n  lm    前往輕量創世神 (Light Minecraft) 實驗區域。\n";
}
