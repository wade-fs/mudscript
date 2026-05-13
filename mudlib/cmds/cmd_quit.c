// mudlib/cmds/cmd_quit.c
// 離開指令守護進程：quit / exit

int main(object me, string verb, string arg) {
    me->save();
    write("存檔完畢，下次見。\n");
    write("再見，" + me->query_name() + "！你化為一道光消逝了...\n");
    say(me->query_name() + " 離開了遊戲。\n");
    
    // 建立一個新的登入物件
    object login_ob = clone_object("/std/login.c");
    if (login_ob) {
        // 將連線轉移回登入物件，而不是直接斷線
        if (exec(login_ob, me)) {
            login_ob->logon();
            destruct(me);
            return 1;
        }
    }

    // 如果轉移失敗，才執行原本的斷線邏輯
    destruct(me);
    return 1;
}

string help() {
    return "【離開指令】\n" +
           "  用法：quit 或 exit\n" +
           "  功能：儲存角色資料並安全地登出遊戲。\n";
}
