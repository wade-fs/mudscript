// /secure/language_d.c
// 共用語系守護進程 (Language Daemon)

#include "/include/ansi.h"

inherit "/std/object.c";

mapping translations;

void create() {
    ::create();
    translations = ([
        "en": ([
            "welcome": "Welcome to $world.",
            "what": "What?",
            "cmd_not_found": "Command not found.",
            "prompt_id": "Please enter your account name:",
            "prompt_id_empty": "ID cannot be empty, please re-enter:",
            "prompt_pass": "Password:",
            "prompt_pass_wrong": "Wrong password, please re-enter:",
            "prompt_new_pass": "Welcome new player $id! Set your password:",
            "prompt_new_pass_empty": "Password cannot be empty, set again:",
            "login_success": "Login successful! Welcome, $name.",
            "void": "You are floating in the void.",
            "not_found": "You don't see any '$arg' here.",
            "exits": "Exits",
            "inventory": "Items",
            "livings": "Here are",
            "none": "None",
            "inv_empty": "Your inventory is empty.",
            "inv_header": "You are carrying the following items:",
            "get_what": "Get what?",
            "no_container": "There is no container called '$id' here.",
            "is_closed": "is closed.",
            "here": "here",
            "no_item_here": "You don't see any '$id' in $loc.",
            "get_living_err": "You cannot pick up living things.",
            "too_heavy_err": "is too heavy or fixed in place.",
            "inv_full_err": "Your inventory is full.",
            "get_success": "You picked up $item from $from.",
            "say_get": "$name picked up $item.",
            "get_fail": "You failed to take that item.",
            "drop_what": "Drop what?",
            "no_item_inv": "You don't have any '$id' in your inventory.",
            "no_drop_err": "seems stuck to your hands, you cannot drop it!",
            "drop_success": "You dropped $item.",
            "say_drop": "$name dropped $item.",
            "drop_fail": "You cannot drop that item right now.",
            "ground": "the ground",
            "go_where": "Go where? (e.g. go north)",
            "no_exit_err": "There is no exit in that direction.",
            "dest_missing_err": "The destination does not exist.",
            "say_leave": "$name left towards $dir.",
            "say_arrive": "$name arrived from $dir.",
            "move_fail_err": "You cannot go $dir.",
            "wear_what": "Wear what?",
            "not_armour_err": "is not armour.",
            "lv_req_err": "Your level is too low to equip $item (requires level $lv).",
            "wear_fail": "Failed to wear",
            "wear_success": "You put on $item.",
            "wield_what": "Wield what?",
            "not_weapon_err": "is not a weapon.",
            "wield_fail": "Failed to wield",
            "wield_success": "You wielded $item.",
            "remove_what": "Remove what?",
            "remove_success": "You removed $item.",
            "no_equip_inv": "You are not equipped with anything called '$id'.",
            "current_lang": "Current language",
            "available_langs": "Available languages",
            "lang_usage": "Usage",
            "unsupported_lang": "Unsupported language",
            "label_actions": "Actions",
            "label_commands": "Commands",
            "cat_admin": "Admin",
            "cat_movement": "Movement",
            "cat_system": "System",
            "cat_communication": "Communication",
            "cat_view": "View",
            "cat_item": "Items",
            "cat_quest": "Quests",
            "quest_accept": "Quest accepted: $quest",
            "quest_desc": "  Objective: $desc",
            "quest_complete": "Quest completed: $quest!",
            "quest_already_accepted": "You have already accepted this quest."
        ]),
        "zh-TW": ([
            "welcome": "歡迎來到《$world》。",
            "what": "什麼？",
            "cmd_not_found": "找不到這個指令。",
            "prompt_id": "請輸入您的帳號名稱：",
            "prompt_id_empty": "帳號不能為空，請重新輸入：",
            "prompt_pass": "請輸入密碼：",
            "prompt_pass_wrong": "密碼錯誤，請重新輸入：",
            "prompt_new_pass": "歡迎新旅人 $id！請設定您的密碼：",
            "prompt_new_pass_empty": "密碼不能為空，請重新設定：",
            "login_success": "登入成功！歡迎回來，$name。",
            "void": "你正漂浮在一片虛空之中。",
            "not_found": "這裡看不到任何叫作「$arg」的東西。",
            "exits": "明顯的出口",
            "inventory": "地上的物品",
            "livings": "這裡有",
            "none": "無",
            "inv_empty": "你身上什麼都沒有帶。",
            "inv_header": "你身上帶著下列物品：",
            "get_what": "你想撿起什麼？",
            "no_container": "這裡找不到叫作「$id」的容器。",
            "is_closed": "是關著的。",
            "here": "這裡",
            "no_item_here": "你在$loc找不到「$id」。",
            "get_living_err": "你沒辦法把活生生的對象撿起來。",
            "too_heavy_err": "太重或固定在原地，無法拿取。",
            "inv_full_err": "你身上的行囊已經滿了。",
            "get_success": "你從$from撿起了 $item。",
            "say_get": "$name 撿起了 $item。",
            "get_fail": "你沒能拿起來。",
            "drop_what": "你想丟下什麼？",
            "no_item_inv": "你身上沒有「$id」。",
            "no_drop_err": "似乎與你緊緊相連，無法丟棄！",
            "drop_success": "你放下了 $item。",
            "say_drop": "$name 放下了 $item。",
            "drop_fail": "你現在無法放下這個物品。",
            "ground": "地上",
            "go_where": "你想往哪裡走？（例如：go north）",
            "no_exit_err": "那個方向沒有路。",
            "dest_missing_err": "前方道路似乎尚未開通。",
            "say_leave": "$name 往 $dir 離開了。",
            "say_arrive": "$name 從 $dir 走了過來。",
            "move_fail_err": "你無法往 $dir 移動。",
            "wear_what": "你想穿戴什麼？",
            "not_armour_err": "不是防具。",
            "lv_req_err": "你的等級不足，無法裝備 $item（需要等級 $lv）。",
            "wear_fail": "無法穿戴",
            "wear_success": "你穿上了 $item。",
            "wield_what": "你想裝備哪件武器？",
            "not_weapon_err": "不是武器。",
            "wield_fail": "無法裝備",
            "wield_success": "你握起了 $item。",
            "remove_what": "你想卸下什麼裝備？",
            "remove_success": "你卸下了 $item。",
            "no_equip_inv": "你身上沒有裝備「$id」。",
            "current_lang": "目前語系",
            "available_langs": "可用語系",
            "lang_usage": "用法",
            "unsupported_lang": "不支援的語系",
            "label_actions": "社交動作",
            "label_commands": "常用指令",
            "cat_admin": "管理",
            "cat_movement": "移動",
            "cat_system": "系統",
            "cat_communication": "通訊",
            "cat_view": "觀察",
            "cat_item": "物品",
            "cat_quest": "任務",
            "quest_accept": "已承接任務：$quest",
            "quest_desc": "  目標：$desc",
            "quest_complete": "任務完成：$quest！",
            "quest_already_accepted": "你已經承接過這個任務了。"
        ]),
        "zh-CN": ([
            "welcome": "欢迎来到《$world》。",
            "what": "什么？",
            "cmd_not_found": "找不到这个指令。",
            "prompt_id": "请输入您的账号名称：",
            "prompt_id_empty": "账号不能为空，请重新输入：",
            "prompt_pass": "请输入密码：",
            "prompt_pass_wrong": "密码错误，请重新输入：",
            "prompt_new_pass": "欢迎新旅人 $id！请设定您的密码：",
            "prompt_new_pass_empty": "密码不能为空，请重新设定：",
            "login_success": "登录成功！欢迎回来，$name。",
            "void": "你正漂浮在一片虚空之中。",
            "not_found": "这里看不到任何叫作「$arg」的东西。",
            "exits": "明显的出口",
            "inventory": "地上的物品",
            "livings": "这里有",
            "none": "无",
            "inv_empty": "你身上什么都没有带。",
            "inv_header": "你身上带着下列物品：",
            "ground": "地上",
            "go_where": "你想往哪里走？",
            "no_exit_err": "那个方向没有路。",
            "dest_missing_err": "前方道路尚未开通。",
            "say_leave": "$name 往 $dir 离开了。",
            "say_arrive": "$name 从 $dir 走了过来。",
            "move_fail_err": "你无法往 $dir 移动。",
            "current_lang": "当前语系",
            "available_langs": "可用语系",
            "lang_usage": "用法",
            "unsupported_lang": "不支持的语系",
            "label_actions": "社交动作",
            "label_commands": "常用指令",
            "cat_admin": "管理",
            "cat_movement": "移动",
            "cat_system": "系统",
            "cat_communication": "通讯",
            "cat_view": "观察",
            "cat_item": "物品",
            "cat_quest": "任务",
            "quest_accept": "已承接任务：$quest",
            "quest_desc": "  目标：$desc",
            "quest_complete": "任务完成：$quest！",
            "quest_already_accepted": "你已经承接过这个任务了。"
        ])
    ]);
}

string translate(string key, string lang) {
    if (!lang || lang == "" || lang == "0") lang = "en";
    if (!translations[lang]) lang = "en";
    if (translations[lang] && translations[lang][key]) return translations[lang][key];
    if (translations["en"] && translations["en"][key]) return translations["en"][key];
    return key;
}

void broadcast_event(object room, string key, mapping vars) {
    if (!room) return;
    object *inv = all_inventory(room);
    if (!inv) return;

    foreach (object ob in inv) {
        if (!ob || !userp(ob)) continue;
        if (mapp(vars) && vars["$name"] == ob) continue;

        string lang = ob->query_lang();
        string msg = translate(key, lang);
        if (mapp(vars)) {
            foreach (string k, mixed v in vars) {
                string val = objectp(v) ? to_string(v->query_name()) : to_string(v);
                msg = replace_string(msg, k, val);
            }
        }
        tell_object(ob, msg + "\n");
    }
}
