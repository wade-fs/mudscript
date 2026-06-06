// /secure/system_d.c
// 系統核心守護進程，處理全域設定（如 mudlib_id）

#include <globals.h>

inherit F_CLEAN_UP;

string mudlib_name;
string mudlib_id;

void create() {
    if (!restore_object("/data/system")) {
        // 如果沒有存檔，回退到預設值
        mudlib_name = "Wade's MudScript";
        mudlib_id = "wade.mud";
    }
}

string query_mudlib_name() {
    return mudlib_name;
}

string query_mudlib_id() {
    return mudlib_id;
}

void set_mudlib_name(string name, string id) {
    mudlib_name = name;
    mudlib_id = id;
    save_object("/data/system");
}
