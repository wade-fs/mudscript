#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIY + "丐祣風之蹴" + NOR,({"fly boots","fly","boots"}));
        set_weight(2000);
        if ( clonep() )
                set_default_object(__FILE__);
        else{
                set("unit","雙");
                set("value",12000);
                set("armor_prop/armor",6);
                set("armor_prop/dodge",6);
                set("armor_prop/move",3);
                set("material","leather");
              set("long","丐幫幫眾所穿的鞋子, 有行動迅捷之效。\n");
                setup();
        }
}
