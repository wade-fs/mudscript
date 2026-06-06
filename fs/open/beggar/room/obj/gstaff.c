
#include <weapon.h>
inherit STAFF;

void create()
{
 set_name(HIG + "青竹棒" + NOR,({"green staff","staff"}));
 set_weight(100);
 init_staff(95);
 if( clonep() )
  set_default_object(__FILE__);
 else
 {
  set("unit","根");
  set("long","這是歷代丐幫幫主的證物，傳聞只要誰能奪得此棍，就能號令丐幫上上下下數十萬人眾。\n");
  set("value",23483);
  set("material","steal");
 }
 set();
}

