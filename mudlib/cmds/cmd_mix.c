// /cmds/cmd_mix.c
// 合成指令：將多種物品混合成新物品

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("用法：mix <物品1>, <物品2>, ...\n");
        return 1;
    }

    // 1. 解析物品清單
    string *parts = explode(arg, ",");
    object *items = ({});

    foreach (string p in parts) {
        string name = trim(p);
        if (name == "") continue;
        
        object ob = present(name, me);
        if (!ob) {
            write("你身上沒有「" + name + "」。\n");
            return 1;
        }
        items += ({ ob });
    }

    if (sizeof(items) < 2) {
        write("你至少需要放入兩樣物品。\n");
        return 1;
    }

    // 2. 判定合成類型 (根據環境)
    object env = environment(me);
    string type = "alchemy"; // 預設為煉金/混合

    if (env->query_has_forge()) {
        type = "forge";
        write("你借用鐵匠鋪的熔爐開始鍛造...\n");
    } else if (env->query_has_lab()) {
        type = "alchemy";
        write("你利用實驗台的設備開始調配...\n");
    } else {
        // 檢查是否有鑲嵌寶石
        int has_gem = 0;
        foreach (object ob in items) {
            if (ob->query_item_type() == "gem" || strsrch(ob->query_name(), "碎石") != -1) {
                has_gem = 1;
                break;
            }
        }
        if (has_gem) {
            type = "socket";
            write("你拿出工具，嘗試進行鑲嵌...\n");
        } else {
            write("你嘗試將這些東西胡亂湊在一起...\n");
        }
    }

    // 3. 呼叫守護進程執行合成
    mixed result = load_object("/secure/crafting_d.c")->do_craft(me, type, items);
    
    if (stringp(result)) {
        write(result + "\n");
    }

    return 1;
}

string help() {
    return "【合成指令】\n" +
           "  mix <物品1>, <物品2>, ...    將指定物品進行合成、鍛造或鑲嵌。\n" +
           "  (提示：在鐵匠鋪或實驗室會有不同的合成效果)\n";
}
