// /cmds/cmd_ride.c
// 騎乘指令

#include "/include/ansi.h"

int main(object me, string verb, string arg) {
    object pet = me->query_pet();

    if (verb == "ride" || verb == "騎乘") {
        if (!pet) {
            write("你目前沒有寵物，無法騎乘。\n");
            return 1;
        }

        if (environment(pet) != environment(me)) {
            write("你的寵物不在這裡。\n");
            return 1;
        }

        if (me->query_riding()) {
            write("你已經在騎乘中了。\n");
            return 1;
        }

        // 簡單判定：只要是寵物都能騎 (未來可以加 is_mount 標記)
        me->set_riding(1);
        write(HIG("你翻身騎上了 " + pet->query_name() + "。\n"));
        say(me->query_name() + " 翻身騎上了 " + pet->query_name() + "。\n");
        return 1;
    }

    if (verb == "unride" || verb == "下來" || verb == "dismount") {
        if (!me->query_riding()) {
            write("你目前並沒有在騎乘狀態。\n");
            return 1;
        }

        me->set_riding(0);
        write(HIW("你從座騎上下來了。\n"));
        say(me->query_name() + " 從座騎上下來了。\n");
        return 1;
    }

    return 0;
}

string help() {
    return "【指令】\n" +
           "  ride      騎上你的寵物\n" +
           "  unride    從座騎上下來\n";
}
