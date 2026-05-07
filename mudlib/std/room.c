// mudlib/std/room.c
string short_desc;
string long_desc;

void create() {
    short_desc = "未命名的空房間";
    long_desc = "這裡什麼都沒有，只有無盡的虛空。\n";
}

void set_short(string str) { short_desc = str; }
void set_long(string str) { long_desc = str; }

string query_short() { return short_desc; }
string query_long() { return long_desc; }

void look_room() {
    write("【" + short_desc + "】\n");
    write(long_desc);
}
