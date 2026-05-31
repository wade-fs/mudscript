// finger.c
#include <ansi.h>
 
#define INFO "/data/info/"
inherit F_CLEAN_UP;
 
void create()
{
        seteuid(getuid());
}
 
int main(object me,string arg)
{
string msg;
 
  if (arg) arg = lower_case(arg);
 
  if (wizardp (me)) {
    if( !arg )
      me->start_more( FINGER_D->finger_all() );
    else {
      msg = FINGER_D->finger_user(arg);
      me->start_more(msg);
    }
  }
  else {
        if( !arg ) {
                if( (int)me->query("sen") < 30 )
                        return notify_fail("你的精神無法集中。\n");
                me->receive_damage("sen",30);
                write( FINGER_D->finger_all() );
        } else {
                if( (int)me->query("sen") < 15 )
                        return notify_fail("你的精神無法集中。\n");
                me->receive_damage("sen",15);
                write( FINGER_D->finger_user(arg) );
        }
  }
        return 1;
}
 
int help(object me)
{
  write(@HELP
指令格式 : finger [使用者姓名]
指令說明 :
           這個指令，如果沒有指定使用者姓明，會顯示出所有
         正在線上玩家的連線資料。反之，則可顯示有關某個玩
         家的連線，權限等資料。
其他參考 :
           who
HELP
    );
    return 1;
}
