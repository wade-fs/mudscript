// mudlib/cmds/cmd_help.c
// 幫助指令守護進程：help / ?

int main(object me, string arg) {
    string verb = query_verb();
    
    if (verb == "help_list_json") {
        return do_help_list(me, arg);
    }
    
    return do_help(me, arg);
}

int do_help_list(object me, string arg) {
    mapping data = ([
        "移動" : ({ "north", "south", "east", "west", "up", "down" }),
        "查看" : ({ "look", "score", "inventory", "status" }),
        "社交" : ({ "say", "emote", "nick" }),
        "系統" : ({ "help", "quit", "alias" })
    ]);
    // 輸出協定：{"ui": "cmd_list", "data": ...}
    write(sprintf("{\"ui\": \"cmd_list\", \"data\": %s}", json_encode(data)));
    return 1;
}

int help_movement() {
    write("【移動指令】\n");
    write("  north / south / east / west  往四個方向移動\n");
    write("  up / down                    往上 / 往下移動\n");
    write("  go <方向>                    明確移動，例如：go north\n");
    return 1;
}

int help_look() {
    write("【查看指令】\n");
    write("  look (l)              查看目前房間\n");
    write("  look <目標>           查看房間或背包中的物品\n");
    write("  examine (ex) <目標>   同 look，更仔細地檢視\n");
    return 1;
}

int help_inventory() {
    write("【物品指令】\n");
    write("  inventory (i)   查看背包內容\n");
    write("  get <物品>      撿起物品\n");
    write("  drop <物品>     丟下物品\n");
    write("  wear <防具>     穿上防具\n");
    write("  wield <武器>    裝備武器\n");
    write("  remove <裝備>   卸下裝備\n");
    return 1;
}

int help_social() {
    write("【社交指令】\n");
    write("  say <訊息>      向房間內所有人說話\n");
    write("  ' <訊息>        同 say 的縮寫\n");
    write("  emote <動作>    做出描述性動作\n");
    write("  : <動作>        同 emote 的縮寫\n");
    return 1;
}

int help_system() {
    write("【系統指令】\n");
    write("  score / status  查看角色狀態\n");
    write("  quit / exit     存檔並離開遊戲\n");
    write("  help / ?        顯示本說明\n");
    write("  alias           管理個人指令別名\n");
    return 1;
}

int help_alias() {
    write("【alias 別名指令】\n");
    write("  alias                  列出所有別名\n");
    write("  alias <名稱> <指令>    設定別名，例如：alias n north\n");
    write("  alias <名稱>           查看指定別名\n");
    write("  unalias <名稱>         刪除別名\n");
    return 1;
}

int do_help(object me, string arg) {
    if (!arg || arg == "") {
        write("輸入 help <主題> 查看說明。主題：move look inventory social system alias\n");
        return 1;
    }

    if (arg == "move")      { return help_movement(); }
    if (arg == "movement")  { return help_movement(); }
    if (arg == "look")      { return help_look(); }
    if (arg == "examine")   { return help_look(); }
    if (arg == "inventory") { return help_inventory(); }
    if (arg == "item")      { return help_inventory(); }
    if (arg == "social")    { return help_social(); }
    if (arg == "say")       { return help_social(); }
    if (arg == "system")    { return help_system(); }
    if (arg == "quit")      { return help_system(); }
    if (arg == "alias")     { return help_alias(); }

    write("找不到關於「" + arg + "」的說明。輸入 help 查看所有主題。\n");
    return 1;
}
