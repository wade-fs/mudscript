#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
seteuid(getuid());
set_name("魔劍天殤",({"Sad sword","sword"}));
set_weight(10000);
if( clonep() )
set_default_object(__FILE__);
else {
set("unit", "把");
set("value",20000);
set("material", "steel");
                set("wield_msg", "拿著$n,$N臉上詭異的笑了笑\n");
set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");  
set("weapon_prop/sword",10);                                                                              }
init_sword(99);
setup();

}
