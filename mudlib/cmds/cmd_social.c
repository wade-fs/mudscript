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

string help() {
    return "【社交指令】\n" +
           "  say <訊息>      向房間內所有人說話\n" +
           "  ' <訊息>        同 say 的縮寫\n" +
           "  emote <動作>    做出描述性動作\n" +
           "  : <動作>        同 emote 的縮寫\n";
}
