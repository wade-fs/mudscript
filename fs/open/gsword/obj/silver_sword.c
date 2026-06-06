// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
        set_name(HIW"銀鱗古劍"NOR,({"silver sword","sword"}));
        set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "把");
         set("long","一把古意盎然的劍，劍身上有著類似龍鱗的鱗片。\n");

                set("value",40000);
		set("material", "steel");
                set("ski_level",80);
                set("ski_type","sword");
         set("wield_msg", "$N拿著$n, 似乎感受到了仙龍的氣勢。 \n");
	}
            init_sword(110);

	setup();
}
int wield() //fix by frequency
{
 if(!this_player()) return 1;
            if( this_player()->query_skill("sword",1) < 100 )
            return notify_fail("你的劍技不足，無法駕馭此劍。\n");
  ::wield();
 return 1;
}
