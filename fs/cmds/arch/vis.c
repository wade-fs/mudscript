// vis

inherit F_CLEAN_UP;

#include <ansi.h>

int main(object me)
{

	if( me->query("env/invis") )
  {
		me->delete("env/invis");
        message_vision(HIW + "$N突然從空氣中走了出來。\n" + NOR, me);
  } else
        printf("你並沒有穿隱身衣。\n");
  return 1;
}

int help(object me)
{
write(@HELP
指令格式 : vis
 
這個指令會讓巫師得以現形
 
HELP
    );
    return 1;
}
