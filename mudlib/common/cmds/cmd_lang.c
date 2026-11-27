// cmds/cmd_lang.c - 共用語系切換指令

#include "/include/ansi.h"
#include "/include/config.h"

inherit "/std/object.c";

string *query_verbs()   { return ({ "lang" }); }
string query_category() { return "System"; }

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write(_t("current_lang") + " " + me->query_lang() + "\n");
        write(_t("usage_lang") + "\n");
        return 1;
    }

    arg = trim(arg);
    if (arg == "en" || arg == "zh-TW" || arg == "zh-CN") {
        me->set_lang(arg);
        object ld = load_object(LANGUAGE_D);
        string msg = ld ? ld->translate("login_success", arg) : "Language changed.";
        msg = replace_string(msg, "$name", to_string(me->query_name()));
        write(msg + "\n");
        if (function_exists("do_save", me)) {
            me->do_save();
        } else if (function_exists("save", me)) {
            me->save();
        }

        if (is_web_client(me)) {
            object cmd_d = find_object(COMMAND_D);
            if (cmd_d) {
                mapping cmds = cmd_d->query_categorized_commands(arg);
                write(sprintf("{\"ui\": \"cmd_list\", \"data\": %s}", json_encode(cmds)));
            }
            object ui = find_object(UI_BRIDGE_D);
            if (ui && function_exists("push_room_view", ui)) ui->push_room_view(me);
        }
    } else {
        write(_t("unsupported_lang") + "：" + arg + "\n");
    }

    return 1;
}

string help() {
    return select_lang(([
        "en":    "【Command】\n  lang <en|zh-TW|zh-CN>  Switch your preferred interface language.\n",
        "zh-TW": "【語系指令】\n  lang <en|zh-TW|zh-CN>  切換個人偏好的語言介面。\n",
        "zh-CN": "【语系指令】\n  lang <en|zh-TW|zh-CN>  切换个人偏好的语言界面。\n"
    ]));
}
