#include <weapon.h>
inherit BLADE;

void create()
{
        seteuid(getuid());
        set_name("鴛鴦刀" ,({"mandarin duck blade","blade"}));
        set_weight(6000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "對");
        set("long","刀柄上結著一對金銀絲編成的鴛鴦結，刀鞘上也刻著一對鴛鴦，看域
像是裝飾用的刀。
\n");

	set("value",8000);
        set("material", "steel");
       
        }
	init_blade(50);

	set("ski_type1", "blade");
	set("ski_type2", "gold-blade");
	set("ski_level1", 50);
	set("ski_level2", 40);
        setup();
}
int wield()
{
     if ((string)this_player()->query("gender") !="女性")
           return notify_fail("女孩子用的刀....大男生用不太好吧？\n");
     else {
           ::wield();
            set("wield_msg","$N把刀拿在手中，覺得輕重合適，滿趁手的。\n");
        set("unwield_msg", "$N做了一個很俊俏的姿勢，把刀收回刀鞘之中。\n");
          }
     return 1;
}
