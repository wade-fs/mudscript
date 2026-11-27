// cmds/cmd_help.c - 共用幫助指令

#include "/include/ansi.h"
#include "/include/config.h"

string *query_verbs()   { return ({ "help", "?", "help_list_json" }); }
string query_category() { return "System"; }

int do_help_list(object me) {
    object cmd_d = load_object(COMMAND_D);
    if (!cmd_d) return 0;

    string lang = me->query_lang();
    mapping data = cmd_d->query_categorized_commands(lang);

    if (me->query_role() != "god" && me->query_role() != "wizard") {
        object lang_d = load_object(LANGUAGE_D);
        string admin_cat = lang_d ? lang_d->translate("cat_admin", lang) : "Admin";
        map_delete(data, admin_cat);
    }

    write(sprintf("{\"ui\": \"cmd_list\", \"data\": %s}", json_encode(data)));
    return 1;
}

int main(object me, string verb, string arg) {
    if (verb == "help_list_json") {
        return do_help_list(me);
    }

    object cmd_d = load_object(COMMAND_D);
    mapping cmd_map = cmd_d ? cmd_d->query_cmd_map() : ([]);

    if (!arg || arg == "") {
        write("{HIW}=== 📚 " + select_lang(([
            "en": "Help Center", "zh-TW": "幫助系統中心", "zh-CN": "帮助系统中心"
        ])) + " ==={NOR}\n");
        write(select_lang(([
            "en": "Type help <command> for details.\n\n",
            "zh-TW": "您可以輸入 help <指令名稱> 查看具體用法。\n\n",
            "zh-CN": "您可以输入 help <指令名称> 查看具体用法。\n\n"
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
        return 1;
    }

    string target = trim(arg);
    if (cmd_map[target]) {
        object cmd_ob = load_object(cmd_map[target]);
        if (cmd_ob && function_exists("help", cmd_ob)) {
            string h = cmd_ob->help();
            if (h && h != "") {
                write(h);
                return 1;
            }
        }
        write("指令「" + target + "」已註冊，目前無額外說明。\n");
        return 1;
    }

    write(select_lang(([
        "en":    "Cannot find help for '" + target + "'.\n",
        "zh-TW": "找不到關於「" + target + "」的說明。輸入 help 查看指令清單。\n",
        "zh-CN": "找不到关于「" + target + "」的说明。输入 help 查看指令清单。\n"
    ])));
    return 1;
}

string help() {
    return select_lang(([
        "en":    "【Help】help [command]  Display command list or usage.\n",
        "zh-TW": "【幫助指令】help [指令名稱]  顯示指令清單或特定指令的詳細用法。\n",
        "zh-CN": "【帮助指令】help [指令名称]  显示指令清单或特定指令的详细用法。\n"
    ]));
}
