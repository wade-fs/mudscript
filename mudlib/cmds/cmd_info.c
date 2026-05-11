// mudlib/cmds/cmd_info.c
// 資訊指令模組：score / status

void cmd_info_setup() {
    add_action("do_score", "score");
    add_action("do_score", "status");
}

int do_score(string arg) {
    // 建立一個資料對應 (Mapping)
    mapping data = ([
        "name" : query_name(),
        "level": query_level(),
        "hp"   : query_hp(),
        "max_hp": query_max_hp(),
        "mp"   : query_mp(),
        "max_mp": query_max_mp(),
        "gold" : query_gold(),
        "atk"  : query_attack(),
        "def"  : query_defence()
    ]);

    // 將資料包裝成通用格式
    // 假設您有一個 json_encode 的 efun (或直接用寫死的字串)
    string payload = sprintf("{\"ui\": \"score\", \"data\": %s}", json_encode(data));
    
    write(payload); 
    return 1;
}
