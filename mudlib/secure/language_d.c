// /secure/language_d.c
// 語系守護進程 (Language Daemon)

#include "/include/ansi.h"

mapping translations;

void create() {
    translations = ([
        "en": ([
            "welcome": "Welcome to MudScript Test Server!",
            "what": "What?",
            "cmd_not_found": "Command not found.",
            "prompt_id": "Please enter your account name (will register if new):",
            "prompt_pass": "Password:",
            "login_success": "Login successful! Welcome back, $name.",
            "north": "north", "south": "south", "east": "east", "west": "west",
            "up": "up", "down": "down",
            "exits": "Exits",
            "inventory": "Inventory",
            "score": "Score",
            "skills": "Skills",
            "quest": "Quests"
        ]),
        "zh-TW": ([
            "welcome": "歡迎來到 MudScript 測試伺服器！",
            "what": "什麼？",
            "cmd_not_found": "找不到該指令。",
            "prompt_id": "請輸入您的帳號名稱 (若無帳號將自動註冊)：",
            "prompt_pass": "請輸入密碼：",
            "login_success": "登入成功！歡迎回來，$name。",
            "north": "北", "south": "南", "east": "東", "west": "西",
            "up": "上", "down": "下",
            "exits": "出口",
            "inventory": "背包",
            "score": "狀態",
            "skills": "技能",
            "quest": "任務"
        ]),
        "zh-CN": ([
            "welcome": "欢迎來到 MudScript 测试服务器！",
            "what": "什么？",
            "cmd_not_found": "找不到该指令。",
            "prompt_id": "请输入您的账号名称 (若无账号将自動注册)：",
            "prompt_pass": "请输入密码：",
            "login_success": "登录成功！欢迎回來，$name。",
            "north": "北", "south": "南", "east": "东", "west": "西",
            "up": "上", "down": "下",
            "exits": "出口",
            "inventory": "背包",
            "score": "状态",
            "skills": "技能",
            "quest": "任务"
        ])
    ]);
}

string translate(string key, string lang) {
    if (!lang || !translations[lang]) {
        // 嘗試匹配前綴，例如 "zh-HK" -> "zh-TW"
        if (strsrch(lang, "zh-") == 0) lang = "zh-TW";
        else lang = "en";
    }

    if (translations[lang] && translations[lang][key]) {
        return translations[lang][key];
    }
    
    // 如果找不到 key，回傳 key 本身
    return key;
}

mapping query_all_translations() { return translations; }
