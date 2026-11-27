// cmds/cmd_inventory.c - 通用 inventory 指令
#include "/include/ansi.h"
string *query_verbs()   { return ({ "inventory", "i" }); }
string query_category() { return "General"; }
int main(object me, string verb, string arg) {
    object sd = find_object("/daemon/schema_d.c");
    if (!sd) sd = load_object("/daemon/schema_d.c");
    string money_str = sd ? sd->format_money(me->query_money()) : (me->query_money() + " 元");

    write("{HIW}── 你的隨身物品 ──{NOR}\n");
    object *inv = all_inventory(me);
    if (!inv || sizeof(inv) == 0) {
        write("（空無一物）\n");
    } else {
        for (int i = 0; i < sizeof(inv); i++) {
            write("  " + to_string(inv[i]->query_short()) + "\n");
        }
    }
    write("財富：" + money_str + "\n");
    return 1;
}
