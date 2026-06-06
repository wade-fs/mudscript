//pen.c : 鋼筆

#include <weapon.h>

inherit STABBER;

void create()
{
        set_name("鋼筆",({"steel pen","pen"}));
        set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "枝");
                set("long","此筆造形奇特, 據說為洋人所愛用。\n");
                set("value",750);
		set("material", "steel");
                set("wield_msg", "$N從胸前口袋裡掏出一枝$n, 很文明的樣子。\n");
                set("unwield_msg", "$N用一副文明人的姿態將$n收進胸前口袋中。\n");
	}
        init_stabber(30);
	setup();
}
int wield()
{
        if((string)this_player()->query("family/family_name") != "儒門")
           return notify_fail("鋼筆只有儒門弟子能用\n");
        else{
              ::wield();
            }
        return 1;
}
