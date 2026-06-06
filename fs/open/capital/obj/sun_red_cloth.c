inherit EQUIP;
#include <ansi.h>
void create()
{
        seteuid(getuid());
        set_name(HIR"夕霞紅紗"NOR , ({ "sun_red_cloth","cloth" }) );
       	set("long","一件華美的紅色衣裳，上面似乎殘留著夕霞之餘暉。\n");
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 80000);
                set("material", "cloth");
                set("armor_type", "cloth");
		set("armor_prop/armor",22);
		set("armor_prop/force",8);
                set("armor_prop/parry",2);
              }



}
