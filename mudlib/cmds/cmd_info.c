// mudlib/cmds/cmd_info.c
// 資訊指令守護進程：score / status

inherit "/std/object";

int main(object me, string verb, string arg) {
    string pk_str = select_lang((["en": "Normal", "zh-TW": "普通", "zh-CN": "普通"]));
    if (me->is_red_name()) {
        pk_str = select_lang((["en": "Red Name", "zh-TW": "紅名", "zh-CN": "红名"]));
    }

    // 1. 建立角色數值資料
    mapping data = ([
        "name" : me->query_name(),
        "level": me->query_level(),
        "hp"   : me->query_hp(),
        "max_hp": me->query_max_hp(),
        "mp"   : me->query_mp(),
        "max_mp": me->query_max_mp(),
        "money": me->query_money_plain(),
        "pk"   : pk_str,
        "atk"  : me->query_attack(),
        "def"  : me->query_defence(),
        "label_hp": _t("label_hp"),
        "label_mp": _t("label_mp"),
        "label_wealth": _t("label_wealth"),
        "label_atk": _t("label_atk")
    ]);

    // 2. 建立指令清單 (分類顯示)
    mapping cmds = ([
        _t("cat_basic")   : ({ "look", "inventory", "score", "map", "time", "quest", "quit", "help" }),
        _t("cat_social")  : ({ "say", "emote", "nickname", "ask", "channel", "chat", "lang" }),
        _t("cat_combat")  : ({ "kill", "skills", "perform", "flee", "practice" }),
        _t("cat_special") : ({ "alias", "follow", "gather", "mix", "party", "ride", "tame", "suicide" })
    ]);

    // 3. 組合完整的 UI 更新封包
    string score_payload = sprintf("{\"ui\": \"score\", \"data\": %s}", json_encode(data));
    string cmd_payload = sprintf("{\"ui\": \"cmd_list\", \"title\": \"%s\", \"data\": %s}", _t("cmd_list"), json_encode(cmds));
    
    write(score_payload);
    write(cmd_payload);
    
    return 1;
}

string help() {
    return select_lang(([
        "en": "【Status Commands】\n  score / status  View detailed character status, including HP, MP, level and attributes.\n",
        "zh-TW": "【狀態指令】\n  score / status  查看角色的詳細狀態資訊，包含 HP、MP、等級與屬性。\n",
        "zh-CN": "【状态指令】\n  score / status  查看角色的详细状态资讯，包含 HP、MP、等级与属性。\n"
    ]));
}
