// mudlib/cmds/cmd_info.c
// 資訊指令守護進程：score / status

int main(object me, string arg) {
    // 建立一個資料對應 (Mapping)
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

    // 將資料包裝成通用格式
    string payload = sprintf("{\"ui\": \"score\", \"data\": %s}", json_encode(data));
    
    write(payload); 
    return 1;
}

string help() {
    return "【狀態指令】\n" +
           "  score / status  查看角色的詳細狀態資訊，包含 HP、MP、等級與屬性。\n";
}
