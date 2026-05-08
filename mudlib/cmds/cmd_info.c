// mudlib/cmds/cmd_info.c
// 資訊指令模組：score / status

void cmd_info_setup() {
    add_action("do_score", "score");
    add_action("do_score", "status");
}

int do_score(string arg) {
    write("╔══════════════════════════════╗\n");
    write("║  角色：" + query_name() + "\n");
    write("╠══════════════════════════════╣\n");
    write("║  等級：" + sprintf("%d", query_level()) +
          "    經驗：" + sprintf("%d", query_exp()) + "/" + sprintf("%d", query_exp_to_next()) + "\n");
    write("║  HP：" + sprintf("%d", query_hp()) + "/" + sprintf("%d", query_max_hp()) +
          "    MP：" + sprintf("%d", query_mp()) + "/" + sprintf("%d", query_max_mp()) + "\n");
    write("║  ATK：" + sprintf("%d", query_attack()) +
          "    DEF：" + sprintf("%d", query_defence()) +
          "    金幣：" + sprintf("%d", query_gold()) + "\n");
    write("╚══════════════════════════════╝\n");
    return 1;
}
