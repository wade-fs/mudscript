// bellup.c
//87.8.18更改回設定在永久SET上
//避免使用者離線又回來後
//TEMP值已經消失，而造成負值的情形
    
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_GUILDCMDS;

int main(object me, string arg)
{    
        int bell=me->query("bellicosity");
	int buf;

    buf=(int)(bell/200+1);
// 原因跟我在 bak.c 所說得一樣不然只要賭的高
// 能爆無限 dodge So 設限不然太扯了 By Swy
// 因為戰鬥系統改了 attack 跟傷害力有關
// dodge and defense 跟抵銷力有關
// 所以一定要設限
    if(buf > 100) buf = 100;
        if(me->query("bellicosity")<200)
                return notify_fail("你身上的殺氣不夠。\n");
        if(me->query("force")<buf)
                return notify_fail("你的內力不夠。\n");
        if(me->query("bellup")==1)
                return notify_fail("你現在正在放出殺氣。\n");
        if(me->query("class")!="killer")
                return notify_fail("這樣指令只有殺手才能用。\n");
        me->apply_condition("bell",(int)(bell/500)+5);
        me->add_temp("apply/damage",buf);
        me->add_temp("apply/attack",buf);
        me->add_temp("apply/dodge",buf*2);
        me->set("bellup",1);
        me->add("force",-buf);

	me->set_temp("bellup_buf",buf);
        message_vision(
        HIG "$N大暍一聲﹐放出身上的殺氣﹐眼神由溫和轉變成恐怖。\n" NOR,me);
        return 1;
}

int help(object me)
{
    write(@HELP

指令格式﹕bellup

說明﹕這個指令讓你可以將體內的殺氣放出。

HELP
);
     return 1;
}

