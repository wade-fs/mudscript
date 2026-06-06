inherit EQUIP;
#include <ansi.h>
void create()
{
        seteuid(getuid());
        set_name("百花鳳凰飾" , ({ "flower cape","cape" }) );
       	set("long","金風細雨樓主花憶妍所穿之披風，散發出淡淡的香氣。\n");
        set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 25000);
                set("material", "cloth");
                set("armor_type", "cape");
		set("armor_prop/armor",7);
              }



}
