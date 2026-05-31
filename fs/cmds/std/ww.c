#include <ansi.h>
#include <carry.h>

varargs int main( object ob, string arg, int mode )
{
  object  *inv;
  int i, count;

  inv = all_inventory(ob);

 count = 0;
  for (i=0;i<sizeof(inv);i++) {
      if (inv[i]->query("equipped") && inv[i]->query_temp("secured")) {
        count++;
        // if (count >= 3) break;
      }
      if (inv[i]->query_autoload()) {
        write (inv[i]->short() + " 已被設定成自動載入\n");
      }
  }
  return 1;
}

int help (object me)
{
  write(@HELP
指令格式 : ww
指令說明 : 列出身上所有自動載入的物品。
HELP
);
        return 1;
}
