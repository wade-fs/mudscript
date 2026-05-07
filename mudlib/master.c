// mudlib/master.c

string get_root_uid() { return "Root"; }
string get_bb_uid() { return "Backbone"; }

void create() {
    // master 不再需要 enable_commands 了
}

object connect() {
    write("連線成功！正在為您準備專屬身體...\n");
    object user = clone_object("/user.c");
    return user; 
}

void runtime_error(string msg, string file) {
    write("🔥 系統錯誤 [" + file + "]: " + msg + "\n");
}
