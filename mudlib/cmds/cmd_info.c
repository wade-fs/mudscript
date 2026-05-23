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
        "money": me->query_money_string(),
        "pk"   : pk_str,
        "atk"  : me->query_attack(),
        "def"  : me->query_defence()
    ]);

    // 2. 建立指令清單 (分類顯示)
    mapping cmds = ([
        select_lang((["en": "Basic", "zh-TW": "基本", "zh-CN": "基本"])) : ({ "look", "inventory", "score", "quit", "help" }),
        select_lang((["en": "Social", "zh-TW": "社交", "zh-CN": "社交"])) : ({ "say", "emote", "nickname", "ask" }),
        select_lang((["en": "Combat", "zh-TW": "戰鬥", "zh-CN": "战斗"])) : ({ "kill", "skills", "flee" }),
        select_lang((["en": "Special", "zh-TW": "特殊", "zh-CN": "特殊"])) : ({ "alias", "suicide" })
    ]);

    // 3. 組合完整的 UI 更新封包
    string score_payload = sprintf("{\"ui\": \"score\", \"data\": %s}", json_encode(data));
    string cmd_payload = sprintf("{\"ui\": \"cmd_list\", \"data\": %s}", json_encode(cmds));
    
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
