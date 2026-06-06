#include <ansi.h>
#include <armor.h>
inherit NECK;
void create()
{
        set_name(CYN + "七公傳生鏈" + NOR, ({"oldman gem","gem"}) );
     set_weight(1500);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "條");
            set("value", 7000);
        set("long","洪七公的傳世項鍊。\n");
        set("armor_prop/parry",5);
        set("armor_prop/armor",7);
        set("armor_prop/staff",3);
     }
            setup();
}

