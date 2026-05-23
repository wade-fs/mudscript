// /secure/language_d.c
// 語系守護進程 (Language Daemon)
// 集中管理系統性關鍵字與 UI 標籤，具備高共用性

#include "/include/ansi.h"

mapping translations;

void create() {
    translations = ([
        "en": ([
            "welcome": "Welcome back, $name.",
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
            "none": "None"
        ]),
        "zh-TW": ([
            "welcome": "歡迎回來，$name。",
            "what": "什麼？",
            "cmd_not_found": "找不到該指令。",
            "prompt_id": "請輸入您的帳號名稱：",
            "prompt_id_empty": "帳號不能為空，請重新輸入：",
            "prompt_pass": "請輸入密碼：",
            "prompt_pass_wrong": "密碼錯誤，請重新輸入密碼：",
            "prompt_new_pass": "歡迎新玩家 $id！為您的帳號設定密碼：",
            "prompt_new_pass_empty": "密碼不能為空，請重新設定密碼：",
            "login_success": "登入成功！歡迎來到這個世界，$name。",
            "void": "你飄浮在虛空中。",
            "not_found": "你看不到叫「$arg」的東西。",
            "exits": "出口",
            "inventory": "物品",
            "livings": "這裡有",
            "none": "無"
        ]),
        "zh-CN": ([
            "welcome": "欢迎回來，$name。",
            "what": "什么？",
            "cmd_not_found": "找不到该指令。",
            "prompt_id": "请输入您的账号名称：",
            "prompt_id_empty": "账号不能为空，请重新输入：",
            "prompt_pass": "请输入密码：",
            "prompt_pass_wrong": "密码错误，请重新输入密码：",
            "prompt_new_pass": "欢迎新玩家 $id！为您的账号设定密码：",
            "prompt_new_pass_empty": "密码不能为空，请重新设定密码：",
            "login_success": "登录成功！欢迎來到这个世界，$name。",
            "void": "你飘浮在虚空中。",
            "not_found": "你看不到叫「$arg」的东西。",
            "exits": "出口",
            "inventory": "物品",
            "livings": "这里有",
            "none": "无"
        ])
    ]);
}

string translate(string key, string lang) {
    if (!lang || !translations[lang]) {
        if (strsrch(lang, "zh-") == 0) lang = "zh-TW";
        else lang = "en";
    }

    if (translations[lang] && translations[lang][key]) {
        return translations[lang][key];
    }
    
    return key;
}

mapping query_all_translations() { return translations; }
