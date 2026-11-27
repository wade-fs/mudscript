// cmds/cmd_lang.c - 共用語系切換指令

#include "/include/ansi.h"
#include "/include/config.h"

string *query_verbs()   { return ({ "lang" }); }
string query_category() { return "System"; }

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write(_t("current_lang") + "：" + me->query_lang() + "\n");
        write(_t("available_langs") + "：en (English), zh-TW (繁體中文), zh-CN (简体中文)\n");
        write(_t("lang_usage") + "：lang <語系ID>\n");
        return 1;
    }

    arg = trim(arg);
    if (arg == "en" || arg == "zh-TW" || arg == "zh-CN") {
        me->set_lang(arg);
        object ld = load_object(LANGUAGE_D);
        string msg = ld ? ld->translate("login_success", arg) : "Language changed.";
        msg = replace_string(msg, "$name", to_string(me->query_name()));
        write(msg + "\n");
        me->do_save();

        object cmd_d = find_object(COMMAND_D);
        if (cmd_d) {
            mapping cmds = cmd_d->query_categorized_commands(arg);
            write(sprintf("{\"ui\": \"cmd_list\", \"data\": %s}", json_encode(cmds)));
        }
        object ui = find_object(UI_BRIDGE_D);
        if (ui) ui->push_room_view(me);
    } else {
        write(_t("unsupported_lang") + "：" + arg + "\n");
    }

    return 1;
}

string help() {
    return select_lang(([
        "en":    "【Command】lang <en|zh-TW|zh-CN>  Switch interface language.\n",
        "zh-TW": "【語系指令】lang <en|zh-TW|zh-CN>  切換個人介面語系。\n",
        "zh-CN": "【语系指令】lang <en|zh-TW|zh-CN>  切换个人界面语系。\n"
    ]));
}
