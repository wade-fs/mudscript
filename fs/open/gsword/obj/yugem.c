#include <ansi.h>
inherit EQUIP;
void create()
{
    set_name("紅玉墜子" , ({"gem"}) );
     set_weight(500);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", 
		"一條由難得一見的"+HIR"紅寶石"NOR+"鑲於其上的項鍊 ,\n"
		"聽說紅寶石有收納能量的功效\n");
            set("unit", "條");
            set("armor_type", "neck");
            set("value", 10000);
            set("armor_prop/force",3);
            set("armor_prop/armor",4);
            set("wear_msg", "$N把$n戴在脖子上 ,呼然一股力量注入$N的身上。\n");
     }
}

