// /cmds/admin/cmd_edit.c
// 簡易線上文字編輯器

#include "/include/config.h"
#include "/include/ansi.h"

inherit "/std/object";

int main(object me, string verb, string arg) {
    if (me->query_role() != "god" && me->query_role() != "wizard") {
        return 0;
    }

    if (!arg || arg == "") {
        write(select_lang(([
            "en": "Usage: edit <file path>\n",
            "zh-TW": "用法：edit <檔案路徑>\n",
            "zh-CN": "用法：edit <文件路径>\n"
        ])));
        return 1;
    }

    if (arg[0] != '/') arg = "/" + arg;

    string content = read_file(arg);
    string *lines;
    if (!content) {
        write(HIW(select_lang(([
            "en": "Creating new file: ",
            "zh-TW": "建立新檔案：",
            "zh-CN": "建立新文件："
        ]))) + arg + "\n");
        lines = ({});
    } else {
        write(HIW(select_lang(([
            "en": "Editing file: ",
            "zh-TW": "編輯檔案：",
            "zh-CN": "编辑文件："
        ]))) + arg + "\n");
        lines = explode(content, "\n");
    }

    me->set_temp("edit_file", arg);
    me->set_temp("edit_buffer", lines);

    write(select_lang(([
        "en": "Entered edit mode. Type '.h' for help, '.' or '.x' to save and exit, '.q' to quit without saving.\n",
        "zh-TW": "進入編輯模式。輸入 '.h' 查看指令，'.' 或 '.x' 儲存退出，'.q' 不存檔退出。\n",
        "zh-CN": "进入编辑模式。输入 '.h' 查看指令，'.' 或 '.x' 储存退出，'.q' 不存档退出。\n"
    ])));
    write("--------------------------------------------------\n");
    input_to("edit_loop");
    write("* ");
    return 1;
}

void edit_loop(object me, string input) {
    string *lines = me->query_temp("edit_buffer");
    string file = me->query_temp("edit_file");

    if (!input) {
        input_to("edit_loop");
        write("* ");
        return;
    }

    if (input == "." || input == ".x") {
        string content = implode(lines, "\n");
        if (sizeof(lines) > 0 && content[strlen(content)-1] != '\n') {
            content += "\n";
        }
        if (write_file(file, content, 1)) {
            write(HIG(select_lang(([
                "en": "File saved.\n",
                "zh-TW": "檔案已儲存。\n",
                "zh-CN": "文件已储存。\n"
            ]))));
        } else {
            write(HIR(select_lang(([
                "en": "Save failed!\n",
                "zh-TW": "儲存失敗！\n",
                "zh-CN": "储存失败！\n"
            ]))));
        }
        me->delete_temp("edit_buffer");
        me->delete_temp("edit_file");
        return;
    }

    if (input == ".q") {
        write(YEL(select_lang(([
            "en": "Edit cancelled.\n",
            "zh-TW": "取消編輯。\n",
            "zh-CN": "取消编辑。\n"
        ]))));
        me->delete_temp("edit_buffer");
        me->delete_temp("edit_file");
        return;
    }

    if (input == ".h") {
        write(select_lang(([
            "en": "Editor Commands:\n" +
                  "  .l        List all content\n" +
                  "  .d <n>    Delete line n\n" +
                  "  .i <n> <text> Insert text before line n\n" +
                  "  .s        Save without exiting\n" +
                  "  .x or .   Save and exit\n" +
                  "  .q        Exit without saving\n" +
                  "  <text>    Append a new line at the end\n",
            "zh-TW": "編輯器指令：\n" +
                  "  .l        列出所有內容\n" +
                  "  .d <n>    刪除第 n 行\n" +
                  "  .i <n> <文字> 在第 n 行前插入文字\n" +
                  "  .s        儲存但不退出\n" +
                  "  .x 或 .   儲存並退出\n" +
                  "  .q        不儲存直接退出\n" +
                  "  <文字>    在最後方新增一行\n",
            "zh-CN": "编辑器指令：\n" +
                  "  .l        列出所有内容\n" +
                  "  .d <n>    删除第 n 行\n" +
                  "  .i <n> <文字> 在第 n 行前插入文字\n" +
                  "  .s        储存但不退出\n" +
                  "  .x 或 .   储存并退出\n" +
                  "  .q        不储存直接退出\n" +
                  "  <文字>    在最后方新增一行\n"
        ])));
        input_to("edit_loop");
        write("* ");
        return;
    }

    if (input == ".l") {
        for (int i = 0; i < sizeof(lines); i++) {
            write(sprintf(HIY("%4d") + ": %s\n", i + 1, lines[i]));
        }
        input_to("edit_loop");
        write("* ");
        return;
    }

    if (substr(input, 0, 3) == ".d ") {
        int n = to_int(substr(input, 3, strlen(input)-3));
        if (n < 1 || n > sizeof(lines)) {
            write(RED(select_lang(([
                "en": "Invalid line number.\n",
                "zh-TW": "無效的行號。\n",
                "zh-CN": "无效的行号。\n"
            ]))));
        } else {
            write(YEL(select_lang(([
                "en": "Deleted line " + n + ".\n",
                "zh-TW": "已刪除第 " + n + " 行。\n",
                "zh-CN": "已删除第 " + n + " 行。\n"
            ]))));
            if (n == 1) lines = lines[1..];
            else if (n == sizeof(lines)) lines = lines[0..sizeof(lines)-2];
            else lines = lines[0..n-2] + lines[n..];
            me->set_temp("edit_buffer", lines);
        }
        input_to("edit_loop");
        write("* ");
        return;
    }

    if (substr(input, 0, 3) == ".i ") {
        string rest = substr(input, 3, strlen(input)-3);
        int sp = strsrch(rest, " ");
        if (sp < 0) {
            write(RED(select_lang(([
                "en": "Usage: .i <n> <text>\n",
                "zh-TW": "用法：.i <n> <文字>\n",
                "zh-CN": "用法：.i <n> <文字>\n"
            ]))));
        } else {
            int n = to_int(substr(rest, 0, sp));
            string text = substr(rest, sp + 1, strlen(rest) - sp - 1);
            if (n < 1) n = 1;
            if (n > sizeof(lines) + 1) n = sizeof(lines) + 1;
            
            if (n == 1) lines = ({ text }) + lines;
            else if (n > sizeof(lines)) lines += ({ text });
            else lines = lines[0..n-2] + ({ text }) + lines[n-1..];
            
            me->set_temp("edit_buffer", lines);
            write(HIG(select_lang(([
                "en": "Inserted text at line " + n + ".\n",
                "zh-TW": "已於第 " + n + " 行插入文字。\n",
                "zh-CN": "已于第 " + n + " 行插入文字。\n"
            ]))));
        }
        input_to("edit_loop");
        write("* ");
        return;
    }

    if (input == ".s") {
        string content = implode(lines, "\n");
        if (sizeof(lines) > 0 && content[strlen(content)-1] != '\n') {
            content += "\n";
        }
        if (write_file(file, content, 1)) {
            write(HIG(select_lang(([
                "en": "File saved.\n",
                "zh-TW": "檔案已儲存。\n",
                "zh-CN": "文件已储存。\n"
            ]))));
        } else {
            write(HIR(select_lang(([
                "en": "Save failed!\n",
                "zh-TW": "儲存失敗！\n",
                "zh-CN": "储存失败！\n"
            ]))));
        }
        input_to("edit_loop");
        write("* ");
        return;
    }

    // 預設為新增一行
    lines += ({ input });
    me->set_temp("edit_buffer", lines);
    input_to("edit_loop");
    write("* ");
}

string *query_verbs() { return ({ "edit" }); }
string query_category() { return "Admin"; }

string help() {
    return select_lang(([
        "en": "【Admin Command】\n  edit <path>    Open a simple online text editor.\n",
        "zh-TW": "【管理指令】\n  edit <路徑>    開啟簡易線上文字編輯器。\n",
        "zh-CN": "【管理指令】\n  edit <路径>    开启簡易线上文字编辑器。\n"
    ]));
}
