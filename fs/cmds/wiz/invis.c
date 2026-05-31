// invis

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me, string arg)
{

	if( me->query("env/invis")=="YES" )
        printf("你已經穿上隱身衣了\n");
    else
    {
		me->set("env/invis","YES");
        message_vision(HIW + "$N拿出一件神奇斗篷往身上一套，就消失蹤影了！\n" + NOR, me);
    }
    return 1;
}

int help(object me)
{
write(@HELP
指令格式 : invis
 
這個指令會讓巫師得以隱形
 
HELP
    );
    return 1;
}
