// /cmds/admin/cmd_eval.c
// 執行 LPC 動態語句 (管理員開發測試工具)

inherit "/std/object";

#include "/include/ansi.h"
#include "/include/globals.h"

int main(object me, string verb, string arg) {
    if (!wizardp(me) && me->query_role() != "god" && me->query_role() != "wizard") {
        write("只有管理員可以使用此指令。\n");
        return 1;
    }

    if (!arg || arg == "") {
        write("指令格式：eval <LPC 表達式>\n");
        return 1;
    }

    string uid = me->query("id");
    if (!uid || uid == "") uid = "wizard";
    string file = "/open/eval_" + uid + ".c";
    
    // 若表達式不含 return 且不含分號結尾，自動包裝 return
    string body = arg;
    if (strsrch(body, "return") == -1) {
        body = "return " + body + ";";
    } else if (substr(body, strlen(body) - 1, 1) != ";") {
        body += ";";
    }

    string code = "// dynamic eval\n"
                  "#include \"/include/globals.h\"\n"
                  "#include \"/include/ansi.h\"\n"
                  "inherit \"/std/object.c\";\n\n"
                  "mixed do_eval(object me) {\n"
                  "    " + body + "\n"
                  "}\n";

    object old = find_object(file);
    if (old) destruct(old);
    rm(file);
    write_file(file, code, 1);

    object ob = load_object(file);
    if (!ob) {
        write(HIR "動態語句編譯失敗！\n" NOR);
        return 1;
    }

    mixed res = ob->do_eval(me);
    destruct(ob);
    rm(file);

    write(sprintf(HIW "Result: %O\n" NOR, res));
    return 1;
}
