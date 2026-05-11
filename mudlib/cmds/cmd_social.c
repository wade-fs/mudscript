// mudlib/cmds/cmd_social.c
// 社交指令守護進程：say / ' / emote / :

int main(object me, string arg) {
    string verb = query_verb();
    
    if (verb == "say" || verb == "'") {
        return do_say_cmd(me, arg);
    }
    
    if (verb == "emote" || verb == ":") {
        return do_emote(me, arg);
    }
    
    return 0;
}

int do_say_cmd(object me, string arg) {
    if (!arg || arg == "") { write("說什麼？\n"); return 1; }
    write("你說：「" + arg + "」\n");
    say(me->query_name() + " 說：「" + arg + "」\n");
    return 1;
}

int do_emote(object me, string arg) {
    if (!arg || arg == "") { write("做什麼動作？\n"); return 1; }
    string msg = me->query_name() + " " + arg + "\n";
    write(msg);
    say(msg);
    return 1;
}
