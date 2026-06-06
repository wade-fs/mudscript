#include <weapon.h>
#include <ansi.h>
inherit UNARMED;

void create()
{
  seteuid(getuid());
  set_name(HIY + "牛神錐" + NOR,({"cow horn","cow","horn"}));
  set_weight(2100);
  if( clonep() )
                set_default_object(__FILE__);
        else {
  set("unit", "把");
  set("long","這是十二星象之中的黃牛君所喜愛的武器 .你仔細地端詳了一下 ,發現這和別的爪子相當不同 .中間的黃色寶珠向四方散發出耀眼的光芒 ,而在旁相連著兩隻對稱的褐黃色牛角 ,上面還帶有些暗紅色的血漬 ,看樣子應該是前人使用這鈍器刺殺敵人時所留下的 .\n");
  set("value",10000);
  set("material","ironsteel");
  set("ski_type","unarmed");
  }
  init_unarmed(30);
  setup();
}
