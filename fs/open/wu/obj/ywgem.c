#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
    set_name("金鏤星輝", ({"gold neck","neck"}) );
     set_weight(5000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
   set("long",HIW + "這是一件由傳說中玄天玉鑲上星輝石串上金鏤線的項鍊。\n" + NOR);
   set("wear_msg", "$N將$n戴上，身上發出" + HIW + "星輝" + NOR + "般的光芒。\n");
   set("unequip_msg", "$N將$n脫掉，身上的光芒隨之逝去。\n");
   set("armor_prop/armor",10);
   set("armor_prop/dodge",3);
            set("unit", "條");
            set("armor_type", "neck");
            set("value", 30000);
     }
}

