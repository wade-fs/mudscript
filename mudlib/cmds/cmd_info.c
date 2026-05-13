// mudlib/cmds/cmd_info.c
// 資訊指令守護進程：score / status

int main(object me, string verb, string arg) {
    // 1. 建立角色數值資料
    mapping data = ([
        "name" : me->query_name(),
        "level": me->query_level(),
        "hp"   : me->query_hp(),
        "max_hp": me->query_max_hp(),
        "mp"   : me->query_mp(),
        "max_mp": me->query_max_mp(),
        "gold" : me->query_gold(),
        "atk"  : me->query_attack(),
        "def"  : me->query_defence()
    ]);

    // 2. 建立指令清單 (分類顯示)
    mapping cmds = ([
        "基本" : ({ "look", "inventory", "score", "quit", "help" }),
        "社交" : ({ "say", "emote", "nickname", "ask" }),
        "戰鬥" : ({ "kill", "skills", "flee" }),
        "特殊" : ({ "alias", "suicide" })
    ]);

    // 3. 組合完整的 UI 更新封包
    string score_payload = sprintf("{\"ui\": \"score\", \"data\": %s}", json_encode(data));
    string cmd_payload = sprintf("{\"ui\": \"cmd_list\", \"data\": %s}", json_encode(cmds));
    
    write(score_payload);
    write(cmd_payload);
    
    return 1;
}

string help() {
    return "【狀態指令】\n" +
           "  score / status  查看角色的詳細狀態資訊，包含 HP、MP、等級與屬性。\n";
}
