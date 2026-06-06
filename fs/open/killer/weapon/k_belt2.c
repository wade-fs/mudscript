#include <ansi.h>
inherit EQUIP;
void create()
{
    set_name(HIY"忍者腰帶"NOR, ({"belt"}) );
     set_weight(100);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("long", "由天蠶絲所製成之腰帶，但卻極其堅軔。\n");
            set("unit", "付");
            set("armor_type", "waist");
            set("material", "leather");
            set("value", 5000);
            set("armor_prop/dodge",3);
            set("armor_prop/armor",4);
     }
}
