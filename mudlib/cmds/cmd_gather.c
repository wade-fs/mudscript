// /cmds/cmd_gather.c
// 採集指令：從屍體上獲取物資

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg) {
        write("你要從什麼東西上面採集？用法：gather <對象>\n");
        return 1;
    }

    object here = environment(me);
    object target = present(arg, here);

    if (!target) {
        write("這裡沒有「" + arg + "」。\n");
        return 1;
    }

    // 檢查是否為屍體
    if (strsrch(object_name(target), "/std/corpse.c") == -1) {
        write("你只能從屍體上採集物資。\n");
        return 1;
    }

    mapping harvest = target->query_harvest_data();
    if (!harvest || sizeof(harvest) == 0) {
        write("這具屍體上已經沒有什麼有價值的東西可以採集了。\n");
        return 1;
    }

    write("你開始對 " + target->query_name() + " 進行採集...\n");
    say(me->query_name() + " 開始對 " + target->query_name() + " 進行採集。\n");

    // 進行採集判定
    if (random(100) < harvest["chance"]) {
        object material = clone_object(harvest["file"]);
        if (material) {
            write(HIG("採集成功！你獲得了 " + material->query_short() + "。\n"));
            if (!move_object(material, me)) {
                write("但你的背包太重了，只好把它丟在地上。\n");
                move_object(material, here);
            }
            me->save();
        }
    } else {
        write("很遺憾，這次採集什麼都沒有發現。\n");
    }

    // 採集完後清空資料，避免重複採集
    target->set_harvest_data(([]));
    target->set_long("這是一具已經被採集過的屍體。\n");

    return 1;
}

string help() {
    return "【指令】\n" +
           "  gather <屍體>    從生物屍體上採集物資 (如狼皮、黏液等)\n";
}
