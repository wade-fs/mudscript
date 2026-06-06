#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
seteuid(getuid());
set_name(HIR + "魔劍鬼武" + NOR,({"blood sword","sword"}));
set_weight(10000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("long",
"此劍為血魔一族的配劍，其劍身成血宏，似乎意味著其無比殺意。\n");
set("value",20000);
set("material", "steel");
                set("wield_msg", HIR + "拿著$n,$N臉上泛起濃濃血光。\n" + NOR);
set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");  
set("weapon_prop/sword",10);                                                                              }
init_sword(80);
setup();

}
