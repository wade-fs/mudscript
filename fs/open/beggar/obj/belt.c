// Qc by anmy (98/3/3)
#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
    set_name(CYN"紫襟帶"NOR, ({"belt"}) );
    set_weight(1000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "付");
            set("material", "leather");
            set("value", 20000);
            set("long","乞丐用的繫腰帶。\n");
        set("armor_prop/dodge",4);
                set("armor_prop/staff",3);
            set("armor_prop/armor",2);
 }
            setup();
}
