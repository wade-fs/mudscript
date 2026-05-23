// /cmds/cmd_lang.c
// 語系切換指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    if (!arg || arg == "") {
        write("當前語系：" + me->query_lang() + "\n");
        write("可用語系：en (English), zh-TW (繁體中文), zh-CN (简体中文)\n");
        write("用法：lang <語系ID>\n");
        return 1;
    }

    arg = trim(arg);
    if (arg == "en" || arg == "zh-TW" || arg == "zh-CN") {
        me->set_lang(arg);
        write(load_object("/secure/language_d.c")->translate("login_success", arg) + "\n");
        me->save();
    } else {
        write("不支援的語系： " + arg + "\n");
    }

    return 1;
}

string help() {
    return "【指令】\n" +
           "  lang <語系>    切換個人偏好的語言介面。\n";
}
