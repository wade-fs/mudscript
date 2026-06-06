#include <ansi.h>
inherit EQUIP;
void create()
{
  set_name("星破項鍊" , ({"stargem"}) );
     set_weight(1000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long",
"這是由星破時, 四射的隕石所得到之石, 將此"+HIB + "星破之石" + NOR+"鑲於此項鍊 ,\n"
"聽說星破時會散發眾多不同能量, 而星破之石則吸納星破時所散發的能量\n");
            set("unit", "條");
            set("armor_type", "neck");
            set("value", 10000);

		set("armor_prop/armor",3);
            set("armor_prop/parry",2);
            set("armor_prop/force",2);
set("wear_msg", "$N小心的$n戴在脖子上 ,一股星破之能源源不斷注入$N的身上。\n");
     }
}
