// mudlib/cmds/cmd_help.c
// 幫助指令守護進程：help / ?

int main(object me, string verb, string arg) {
    if (verb == "help_list_json") {
        return do_help_list(me, arg);
    }
    
    object cmd_d = load_object("/secure/command_d.c");
    mapping cmd_map = cmd_d->query_cmd_map();

    if (!arg) {
        write("=== 📚 幫助系統中心 ===\n");
        write("您可以輸入 help <指令名稱> 來查看具體用法。\n\n");
        
        mapping categories = ([
            "🚩 移動" : ({ "north", "south", "east", "west", "up", "down", "go" }),
            "🔍 查看" : ({ "look", "l", "examine", "ex", "score", "status", "inventory", "i" }),
            "📦 物品" : ({ "get", "drop", "wear", "wield", "remove" }),
            "💬 社交" : ({ "say", "'", "emote", ":", "nickname", "nick" }),
            "⚙️ 系統" : ({ "help", "?", "alias", "unalias", "quit", "exit" })
        ]);

        string *cats = keys(categories);
        int i, j;
        for (i = 0; i < sizeof(cats); i++) {
            write(cats[i] + "：\n  ");
            string *cmds = categories[cats[i]];
            write(implode(cmds, ", ") + "\n");
        }
        
        if (me->query_role() == "god" || me->query_role() == "wizard") {
            write("\n🧙 管理指令：\n  promote, demote, grant, revoke\n");
        }
        
        write("\n提示：主題說明可輸入 help move, help look, help item, help social\n");
        return 1;
    }

    // 1. 嘗試查詢 COMMAND_D 看看這是不是一個指令
    if (cmd_map[arg]) {
        object cmd_ob = load_object(cmd_map[arg]);
        if (cmd_ob) {
            string h = cmd_ob->help();
            if (h && h != "") {
                write(h);
                return 1;
            }
        }
    }

    // 2. 如果不是指令，或者是該指令沒寫 help，則嘗試作為主題搜尋
    if (arg == "move" || arg == "movement") { return main(me, "north"); }
    if (arg == "look") { return main(me, "look"); }
    if (arg == "inventory" || arg == "item") { return main(me, "inventory"); }
    if (arg == "social") { return main(me, "say"); }
    if (arg == "system") { return main(me, "score"); }
    if (arg == "alias") { return main(me, "alias"); }

    write("找不到關於「" + arg + "」的說明。輸入 help 查看指令清單。\n");
    return 1;
}

int do_help_list(object me, string arg) {
    mapping data = ([
        "移動" : ({ "north", "south", "east", "west", "up", "down" }),
        "查看" : ({ "look", "score", "inventory", "status" }),
        "社交" : ({ "say", "emote", "nick" }),
        "系統" : ({ "help", "quit", "alias" })
    ]);
    write(sprintf("{\"ui\": \"cmd_list\", \"data\": %s}", json_encode(data)));
    return 1;
}

string help() {
    return "【幫助指令】\n" +
           "  用法：help <指令名稱> 或 help <主題>\n" +
           "  功能：顯示指令的詳細用法或系統功能說明。\n";
}
