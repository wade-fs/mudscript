// version.c
#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
  string id = me->query("id");
  string file ;
  if(wizardp(me) && arg)
    id = arg;
  file = sprintf("/log/death/%s/%s",id[0..0],id);
  tail(file);
	return 1;
}
int help(object me)
{
  write(@HELP
指令格式 : log
 
使用這個指令會看到你最近的一些系統記錄。
 
HELP
    );
    return 1;
}
 
