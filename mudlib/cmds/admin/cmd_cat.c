// /cmds/admin/cmd_cat.c
// 檢視檔案內容指令：cat <路徑>

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (me->query_role() != "god" && me->query_role() != "wizard") {
        return 0;
    }

    if (!arg || arg == "") {
        write(select_lang(([
            "en": "Usage: cat <file path>\n",
            "zh-TW": "用法：cat <檔案路徑>\n",
            "zh-CN": "用法：cat <文件路径>\n"
        ])));
        return 1;
    }

    if (arg[0] != '/') arg = "/" + arg;

    string content = read_file(arg);
    if (!content) {
        write(RED(select_lang(([
            "en": "Error: Cannot read file ",
            "zh-TW": "錯誤：無法讀取檔案 ",
            "zh-CN": "错误：无法读取文件 "
        ]))) + arg + "\n");
        return 1;
    }

    write(HIW(select_lang(([
        "en": "File Content: ",
        "zh-TW": "檔案內容：",
        "zh-CN": "文件内容："
    ]))) + arg + "\n");
    write("--------------------------------------------------\n");
    write(content);
    if (strlen(content) > 0 && content[strlen(content)-1] != '\n') write("\n");
    write("--------------------------------------------------\n");

    return 1;
}

string *query_verbs() { return ({ "cat" }); }
string query_category() { return "Admin"; }

string help() {
    return select_lang(([
        "en": "【Admin Command】\n  cat <path>    Display the contents of the specified file.\n",
        "zh-TW": "【管理指令】\n  cat <路徑>    在終端機顯示指定的檔案內容。\n",
        "zh-CN": "【管理指令】\n  cat <路径>    在终端机显示指定的文件内容。\n"
    ]));
}
