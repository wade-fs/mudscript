// /cmds/cmd_gather.c
// 通用採集指令：支援環境資源採集（草藥、礦石、特殊地物）與實體物資剝取（生物屍體、資源容器）

inherit "/std/object";

#include "/include/ansi.h"
#include "/include/globals.h"

int main(object me, string verb, string arg) {
    object here = environment(me);
    if (!here) return 1;

    // 1. 環境優先委託：若當前房間實現了 do_gather(me, arg)，由環境自行裁量處理
    if (function_exists("do_gather", here)) {
        int res = here->do_gather(me, arg);
        if (res) return res;
    }

    // 2. 常規草藥生態採集：若無參數或參數為草藥相關詞，且場景具備草藥生長能力
    if (!arg || arg == "" || arg == "herb" || arg == "草藥" || arg == "靈草" || arg == "藥草") {
        if (here->query("can_gather_herb")) {
            return load_object("/daemon/world_state_d.c")->gather_herb(me);
        }
    }

    // 3. 目標實體採集 (如屍體、資源節點)
    if (!arg || arg == "") {
        write(select_lang(([
            "en": "What do you want to gather? Usage: gather <target/resource>\n",
            "zh-TW": "你要採集什麼？用法：gather <目標/資源>\n",
            "zh-CN": "你要采集什么？用法：gather <目标/资源>\n"
        ])));
        return 1;
    }

    object target = present(arg, here);
    if (target) {
        // 3.1 實體自定義採集協議
        if (function_exists("do_gather", target)) {
            int r = target->do_gather(me, arg);
            if (r) return r;
        }

        // 3.2 屍體物資剝取 (Corpse Harvesting)
        if (strsrch(object_name(target), "/std/corpse.c") != -1 || target->query("is_corpse")) {
            mapping harvest = target->query_harvest_data();
            if (!harvest || sizeof(harvest) == 0) {
                write(select_lang(([
                    "en": "There is nothing valuable left to gather on this corpse.\n",
                    "zh-TW": "這具屍體上已經沒有什麼有價值的東西可以採集了。\n",
                    "zh-CN": "这具尸体上已经没有什么有价值的东西可以采集了。\n"
                ])));
                return 1;
            }

            write(select_lang(([ "en": "You start gathering from ", "zh-TW": "你開始對 ", "zh-CN": "你开始对 " ])) + target->query_name() + select_lang(([ "en": "...\n", "zh-TW": " 進行採集...\n", "zh-CN": " 进行采集...\n" ])));
            say(me->query_name() + select_lang(([ "en": " starts gathering from ", "zh-TW": " 開始對 ", "zh-CN": " 开始对 " ])) + target->query_name() + select_lang(([ "en": ".\n", "zh-TW": " 進行採集。\n", "zh-CN": " 进行采集。\n" ])));

            if (random(100) < harvest["chance"]) {
                object material = clone_object(harvest["file"]);
                if (material) {
                    write("$HIG$" + select_lang(([ "en": "Gathering successful! You obtained ", "zh-TW": "採集成功！你獲得了 ", "zh-CN": "采集成功！你获得了 " ])) + material->query_short() + select_lang(([ "en": ".\n", "zh-TW": "。\n", "zh-CN": "。\n" ])) + "$NOR$");
                    if (!move_object(material, me)) {
                        write(select_lang(([ "en": "But your backpack is too heavy, so you drop it on the ground.\n", "zh-TW": "但你的背包太重了，只好把它丟在地上。\n", "zh-CN": "但你的背包太重了，只好把它丢在地上。\n" ])));
                        move_object(material, here);
                    }
                    me->save();
                }
            } else {
                write(select_lang(([ "en": "Unfortunately, you found nothing this time.\n", "zh-TW": "很遺憾，這次採集什麼都沒有發現。\n", "zh-CN": "很遗憾，这次采集什么都没有发现。\n" ])));
            }

            target->set_harvest_data(([]));
            target->set_long(select_lang(([ "en": "This is a corpse that has already been gathered from.\n", "zh-TW": "這是一具已經被採集過的屍體。\n", "zh-CN": "这是一具已经被采集过的尸体。\n" ])));
            return 1;
        }

        write(select_lang(([
            "en": "You cannot gather anything from this.\n",
            "zh-TW": "你無法從這個目標上採集任何東西。\n",
            "zh-CN": "你无法从这个目标上采集任何东西。\n"
        ])));
        return 1;
    }

    // 4. 找不到目標實體且環境未提供
    write(select_lang(([
        "en": "There is no '" + arg + "' to gather here.\n",
        "zh-TW": "此處並無可供採集的「" + arg + "」。\n",
        "zh-CN": "此处并无可供采集的「" + arg + "」。\n"
    ])));
    return 1;
}

string help() {
    return select_lang(([
        "en": "【Command】\n  gather [resource/corpse]    Gather materials from environment (herbs, moss, etc.) or creature corpses.\n",
        "zh-TW": "【指令】\n  gather [資源/屍體]    從環境中採集物資 (如草藥、石膽苔等) 或從生物屍體上剝取物資 (如狼皮、黏液等)\n",
        "zh-CN": "【指令】\n  gather [资源/尸体]    从环境中采集物资 (如草药、石胆苔等) 或从生物尸体上剥取物资 (如狼皮、黏液等)\n"
    ]));
}

string *query_verbs() {
    return ({ "gather", "collect" });
}

string query_category() {
    return select_lang(([ "en": "Special", "zh-TW": "特殊", "zh-CN": "特殊" ]));
}
