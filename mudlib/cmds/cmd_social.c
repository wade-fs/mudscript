// mudlib/cmds/cmd_social.c
// 社交指令模組：say / ' / emote / :

void cmd_social_setup() {
    add_action("do_say_cmd", "say");
    add_action("do_say_cmd", "'");
    add_action("do_emote",   "emote");
    add_action("do_emote",   ":");
}

int do_say_cmd(string arg) {
    if (!arg) { write("說什麼？\n"); return 1; }
    write("你說：「" + arg + "」\n");
    say(query_name() + " 說：「" + arg + "」\n");
    return 1;
}

int do_emote(string arg) {
    if (!arg) { write("做什麼動作？\n"); return 1; }
    string msg = query_name() + " " + arg + "\n";
    write(msg);
    say(msg);
    return 1;
}
