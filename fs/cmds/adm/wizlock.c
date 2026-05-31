// wizlock.c

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }
int main(object me, string arg)
{
  int lvl;

  if( me!=this_player(1) ) return 0;
  if( wiz_level(me) <= wiz_level("(arch)") )
    return notify_fail("你的巫師等級太低﹐沒有使用這個指令的權力。\n");
  if( !arg || arg=="" ) {
    write ("wiz lock level at : "+read_file("/include/lock.h")+"\n");
    return 1;
  }

  if( sscanf(arg, "%d", lvl)!=1 ) lvl = wiz_level(arg);
  if (lvl > wiz_level (me)) lvl = wiz_level (me);
  if (write_file("/include/lock.h",sprintf("%d",lvl), 1)) {
    write ("ok, lock to wiz_level "+ lvl + "\n");
    return 1;
  } else
    return notify_fail("上線權限設定失敗。\n");
}

int help (object me)
{
        write(@HELP
指令格式: wizlock <巫師等級>
 
限制某個等級以下的使用者進入遊戲。
其中巫師等級分別為：
	0 : player
	1 : immortal
	2 : apprentice
	3 : wizard
	4 : arch
	5 : admin
	6 : guest
	7 : manager
若要取消限制, 則輸入 0.
 
HELP
);
        return 1;
}
 
