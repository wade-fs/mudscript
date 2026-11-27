// cmds/cmd_score.c - 通用角色狀態指令

#include "/include/ansi.h"

string *query_verbs()   { return ({ "score", "sc" }); }
string query_category() { return "General"; }

int main(object me, string verb, string arg) {
    object sd = find_object("/daemon/schema_d.c");
    if (!sd) sd = load_object("/daemon/schema_d.c");

    int lv = me->query_level();
    string realm = sd ? sd->query_realm_for_level("", lv) : ("Lv." + lv);
    string money_str = sd ? sd->format_money(me->query_money()) : (me->query_money() + " 元");
    int sp_val = function_exists("query_sp", me) ? me->query_sp() : 0;
    int max_sp_val = function_exists("query_max_sp", me) ? me->query_max_sp() : 0;

    write("{HIW}───────── 角色狀態 ─────────{NOR}\n");
    write("名稱    ：" + to_string(me->query_short()) + "\n");
    write("境界    ：" + realm + " (Lv." + lv + ")\n");
    write("種族    ：" + (me->query_race() ? to_string(me->query_race()) : "未知") + "\n");
    write("氣血    ：" + me->query_hp() + " / " + me->query_max_hp() + "\n");
    write("神識    ：" + me->query_mp() + " / " + me->query_max_mp() + "\n");
    write("精力    ：" + sp_val + " / " + max_sp_val + "\n");
    write("攻擊    ：" + me->query_attack() + "\n");
    write("防禦    ：" + me->query_defence() + "\n");
    write("財富    ：" + money_str + "\n");
    write("{HIW}────────────────────────────{NOR}\n");

    object ui = find_object("/daemon/ui_bridge_d.c");
    if (!ui) ui = load_object("/daemon/ui_bridge_d.c");
    if (ui) ui->push_char_view(me);

    return 1;
}
