// ribbon.c //cgy

#include <weapon.h>
#include <ansi.h>
inherit UNARMED;
inherit F_AUTOLOAD;
inherit F_SAVE;



void create()
{
	set_name(HIC + "七" + HIM + "彩" + HIG + "緞" + HIW + "帶" + NOR, ({"rainbow ribbon","ribbon"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("no_drop",1);
		set("unit", "條");
		set("long","一條七彩的緞帶舞者的信物。\n");
	/*	set("value",1000);	*/
		set("material", "gold");
		set("wield_msg", "$N把$n拿在手上$N似乎要翩翩起舞。\n");
		set("unwield_msg", "$N將手中的$n僅慎的收入懷中。\n");
                        set ("no_get", 1);
                        set ("no_drop", 1);
                   }
	init_unarmed(30);
	setup();
}
int query_autoload()
{
   return 1;
}

