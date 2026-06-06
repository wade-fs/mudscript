#include <ansi.h>
#include <armor.h>
inherit WRISTS;
void create()
{
     set_name(HIB"真武腕罩"NOR , ({"fight wrists","wrists","fight"}) );
     set_weight(2000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "串");
            set("value", 6000);
            set("long","從武者淪落到丐幫的護腕。\n");
         set("armor_prop/armor",5);
         set("armor_prop/force",4);
         set("armor_prop/staff",1);
     }
            setup();
}
