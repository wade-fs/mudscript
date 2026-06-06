//太后跟皇后的eq
inherit EQUIP;
#include <ansi.h>
void create()
{
          set_name(HIR"王母"HIM"腰帶"NOR, ({ "girl belt" ,"belt" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long","王母娘娘賜給太后及皇后的腰帶。\n");
                set("unit", "件");
                set("value", 70000);
                set("material","leather");
                set("armor_type", "waist");
                set("armor_prop/armor",7);
                set("armor_prop/dodge",3);
                set("armor_prop/move",3);
                setup();

        }
}

