// /cmds/cmd_bank.c
// 銀行/ATM 指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    object bank_d = load_object("/secure/bank_d.c");
    
    if (!arg || arg == "") {
        bank_d->update_interest(me);
        write(HIW("\n=== 冒險者銀行 ===\n"));
        write("  身上現金：" + me->query_money_string() + "\n");
        write("  銀行存款：" + me->query_bank_balance() + " 銅幣\n");
        write("  上次計息：" + ctime(me->query_last_bank_time()) + "\n");
        write(HIW("==================\n"));
        write("用法：bank deposit <數量> / bank withdraw <數量>\n");
        return 1;
    }

    string cmd;
    int amount;
    int sp = strsrch(arg, " ");
    
    if (sp == -1) {
        write("用法：bank deposit <數量> / bank withdraw <數量>\n");
        return 1;
    }

    cmd = substr(arg, 0, sp);
    amount = to_int(substr(arg, sp + 1, strlen(arg) - sp - 1));

    if (amount <= 0) {
        write("請輸入正確的金額。\n");
        return 1;
    }

    if (cmd == "deposit" || cmd == "存") {
        bank_d->deposit(me, amount);
    } else if (cmd == "withdraw" || cmd == "提") {
        bank_d->withdraw(me, amount);
    } else {
        write("未知指令。\n");
    }

    return 1;
}

string help() {
    return "【經濟指令】\n" +
           "  bank                 查看銀行存款與餘額。\n" +
           "  bank deposit <量>    將身上的錢存入銀行 (單位：銅幣)。\n" +
           "  bank withdraw <量>   從銀行提領現金 (單位：銅幣)。\n";
}
