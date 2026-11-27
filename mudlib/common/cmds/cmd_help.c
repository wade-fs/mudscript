// cmds/cmd_help.c - 共用幫助指令 (help / ? / help_list_json)

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/object.c";

string *query_verbs() { return ({ "help", "?" }); }
string query_category() {
    return select_lang(([ "en": "System", "zh-TW": "系統", "zh-CN": "系统" ]));
}

int do_help_list(object me, string arg) {
    object cmd_d = load_object(COMMAND_D);
    if (!cmd_d) return 0;

    string lang = me->query_lang();
    mapping data = cmd_d->query_categorized_commands(lang);

    if (me->query_role() != "god" && me->query_role() != "wizard") {
        object lang_d = load_object(LANGUAGE_D);
        string admin_cat = lang_d ? lang_d->translate("cat_admin", lang) : "Admin";
        m_delete(data, admin_cat);
    }

    write(sprintf("{\"ui\": \"cmd_list\", \"data\": %s}", json_encode(data)));
    return 1;
}

int main(object me, string verb, string arg) {
    if (verb == "help_list_json") {
        return do_help_list(me, arg);
    }

    object cmd_d = load_object(COMMAND_D);
    mapping cmd_map = cmd_d ? cmd_d->query_cmd_map() : ([]);

    if (!arg || arg == "") {
        write(select_lang(([
            "en":    "=== 📚 Help Center ===\n",
            "zh-TW": "=== 📚 幫助系統中心 ===\n",
            "zh-CN": "=== 📚 帮助系统中心 ===\n"
        ])));
        write(select_lang(([
            "en":    "You can type help <command name> to view specific usage.\n\n",
            "zh-TW": "您可以輸入 help <指令名稱> 來查看具體用法。\n\n",
            "zh-CN": "您可以输入 help <指令名称> 来查看具体用法。\n\n"
        ])));

        if (cmd_d) {
            mapping cats = cmd_d->query_categorized_commands(me->query_lang());
            string *ckeys = sort_array(keys(cats), 1);
            for (int i = 0; i < sizeof(ckeys); i++) {
                string c = ckeys[i];
                if (c == "Admin" || c == "管理") {
                    if (me->query_role() != "god" && me->query_role() != "wizard") continue;
                }
                write("{CYN}" + c + "：{NOR}" + implode(cats[c], ", ") + "\n");
            }
        }

        write(select_lang(([
            "en":    "\nTip: For topic explanations, you can type help move, help look, help item, help social\n",
            "zh-TW": "\n提示：主題說明可輸入 help move, help look, help item, help social\n",
            "zh-CN": "\n提示：主题说明可输入 help move, help look, help item, help social\n"
        ])));
        return 1;
    }

    // 1. 查詢 COMMAND_D 指令說明
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

    // 2. 主題別名導向
    if (arg == "move" || arg == "movement") return main(me, "help", "north");
    if (arg == "item")                      return main(me, "help", "inventory");
    if (arg == "social")                    return main(me, "help", "say");
    if (arg == "system")                    return main(me, "help", "score");

    write(select_lang(([
        "en":    "Cannot find help on '" + arg + "'. Type help to see the list of commands.\n",
        "zh-TW": "找不到關於「" + arg + "」的說明。輸入 help 查看指令清單。\n",
        "zh-CN": "找不到关于「" + arg + "」的说明。输入 help 查看指令清单。\n"
    ])));
    return 1;
}

string help() {
    return select_lang(([
        "en":    "【Help Command】\n  Usage: help <command name> or help <topic>\n  Function: Display detailed usage of commands or system functions.\n",
        "zh-TW": "【幫助指令】\n  用法：help <指令名稱> 或 help <主題>\n  功能：顯示指令的詳細用法或系統功能說明。\n",
        "zh-CN": "【帮助指令】\n  用法：help <指令名称> 或 help <主题>\n  功能：显示指令的详细用法或系统功能说明。\n"
    ]));
}
