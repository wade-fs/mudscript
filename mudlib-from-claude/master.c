// mudlib/master.c
#include "/include/config.h"

string get_root_uid() { return "Root"; }
string get_bb_uid()   { return "Backbone"; }

void create() {}

object connect() {
    write("連線成功！正在為您準備專屬身體...\n");
    object user = clone_object("/user.c");
    return user;
}

void runtime_error(string msg, string file) {
    write("🔥 系統錯誤 [" + file + "]: " + msg + "\n");
}
