// mudlib/cmds/cmd_social.c
// 社交指令守護進程：say / ' / emote / :

int main(object me, string verb, string arg) {
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
    
    // 玩家自己看到這行
    write("你說：「" + arg + "」\n");

    // 房間內其他人（包含 NPC）看到這行，且會觸發 NPC 的 catch_tell
    // 在底層 efun 中已修正，say() 現在會自動排除 this_player()，所以不會重複看到
    say(me->query_name() + " 說：「" + arg + "」\n");

    return 1;
}

int do_emote(object me, string arg) {
    if (!arg || arg == "") { write("做什麼動作？\n"); return 1; }
    
    string msg = me->query_name() + " " + arg + "\n";
    write("你 " + arg + "\n");
    
    // say 會自動排除 initiator
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
