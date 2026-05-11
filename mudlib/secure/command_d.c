// /secure/command_d.c
// 指令守護進程 (Command Daemon)
// 負責管理與分發全域指令，避免每個玩家物件都要載入大量指令模組

mapping cmd_map;

void create() {
    cmd_map = ([
        "look"     : "/cmds/cmd_look.c",
        "l"        : "/cmds/cmd_look.c",
        "examine"  : "/cmds/cmd_look.c",
        "ex"       : "/cmds/cmd_look.c",
        "north"    : "/cmds/cmd_movement.c",
        "south"    : "/cmds/cmd_movement.c",
        "east"     : "/cmds/cmd_movement.c",
        "west"     : "/cmds/cmd_movement.c",
        "up"       : "/cmds/cmd_movement.c",
        "down"     : "/cmds/cmd_movement.c",
        "go"       : "/cmds/cmd_movement.c",
        "get"      : "/cmds/cmd_inventory.c",
        "drop"     : "/cmds/cmd_inventory.c",
        "wear"     : "/cmds/cmd_inventory.c",
        "wield"    : "/cmds/cmd_inventory.c",
        "remove"   : "/cmds/cmd_inventory.c",
        "inventory": "/cmds/cmd_inventory.c",
        "i"        : "/cmds/cmd_inventory.c",
        "help"     : "/cmds/cmd_help.c",
        "alias"    : "/cmds/cmd_alias.c",
        "unalias"  : "/cmds/cmd_unalias.c",
        "info"     : "/cmds/cmd_info.c",
        "score"    : "/cmds/cmd_info.c",
        "status"   : "/cmds/cmd_info.c",
        "quit"     : "/cmds/cmd_quit.c",
        "exit"     : "/cmds/cmd_quit.c",
        "say"      : "/cmds/cmd_social.c",
        "'"        : "/cmds/cmd_social.c",
        "emote"    : "/cmds/cmd_social.c",
        ":"        : "/cmds/cmd_social.c",
        "social"   : "/cmds/cmd_social.c",
        "nickname" : "/cmds/cmd_nickname.c",
        "nick"     : "/cmds/cmd_nickname.c",
        "promote"  : "/cmds/admin/cmd_promote.c",
        "demote"   : "/cmds/admin/cmd_demote.c",
        "grant"    : "/cmds/admin/cmd_grant.c",
        "revoke"   : "/cmds/admin/cmd_revoke.c"
    ]);
}

int execute(object me, string verb, string arg) {
    // write("DEBUG: COMMAND_D 正在執行 " + verb + " (" + arg + ")\n");
    string cmd_file = cmd_map[verb];
    
    if (!cmd_file) {
        return 0; 
    }

    object cmd_ob = load_object(cmd_file);
    if (!cmd_ob) {
        write("系統錯誤：找不到指令實作檔案 " + cmd_file + "\n");
        return 1;
    }

    return cmd_ob->main(me, arg);
}

mapping query_cmd_map() {
    return cmd_map;
}
