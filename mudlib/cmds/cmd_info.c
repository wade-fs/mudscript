// mudlib/cmds/cmd_info.c
// 資訊指令模組：score / status

void cmd_info_setup() {
    add_action("do_score", "score");
    add_action("do_score", "status");
}

int do_score(string arg) {
    string exp_str = sprintf("%d/%d", query_exp(), query_exp_to_next());
    string hp_str  = sprintf("%d/%d", query_hp(), query_max_hp());
    string mp_str  = sprintf("%d/%d", query_mp(), query_max_mp());

    // 上下框線加寬到 34 個 ═
    write("╔══════════════════════════════════╗\n");
    
    // 角色前綴佔 8 格 (2格空白+角色+冒號)，所以補滿 26 格 = 34
    write("║  角色：" + pad_str(query_name(), 26) + "║\n");
    write("╠══════════════════════════════════╣\n");
    
    // 前面有 2 格空白，所以每行補滿 32 格 = 34
    string line1 = sprintf("等級：%-5d 經驗：%s", query_level(), exp_str);
    write("║  " + pad_str(line1, 32) + "║\n");
    
    string line2 = sprintf("HP：%-7s MP：%s", hp_str, mp_str);
    write("║  " + pad_str(line2, 32) + "║\n");
    
    string line3 = sprintf("ATK：%-5d DEF：%-5d 金幣：%d", query_attack(), query_defence(), query_gold());
    write("║  " + pad_str(line3, 32) + "║\n");
    
    write("╚══════════════════════════════════╝\n");
    return 1;
}
