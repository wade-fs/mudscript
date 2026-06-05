#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
seteuid(getuid());
set_name("" + HIR + "日" + HIB + "月" + HIW + "神器" + NOR + "",({"sun_moon_sword","sword"}));
set_weight(7000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("long",
"由朝陽古闕與拜月幽劍兩把礦世神器所合鑄成的劍.....半邊劍身呈深紅色
另半邊則會為陰藍色,完全顯現出這把神器的特性-剛柔並濟-。\n");
set("value",0);
set("material", "crimsonsteel");
set("wield_msg", HIW + "$N將$n" + HIW + "由身後厚重的劍匣中抽出,頓時日月並現於天際,並將其靈氣注入$n\n");
set("unwield_msg", HIW + "$N將手中$n" + HIW + "向後一丟...$n似" + HIW + "乎有靈性一般,自動回歸劍匣內。\n");  
}
   set("no_drop", 1);
   set("no_give", 1);
   set("no_get", 1);
   set("no_auc", 1);
init_sword(110);
setup();
}
int query_autoload()
{
   return 1;
}


