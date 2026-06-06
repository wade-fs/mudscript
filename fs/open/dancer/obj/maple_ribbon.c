// ribbon.c //cgy

#include <weapon.h>
#include <ansi.h>
inherit UNARMED;
inherit F_AUTOLOAD;
inherit F_SAVE;



void create()
{
	set_name(HIW + "楓" + HIG + "之" + HIM + "舞" + NOR, ({"maple ribbon","ribbon"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "條");
		set("long","這是夜夢小築上任宮主留給月牙兒及水靈兒的彩帶。\n");
		set("value",30000);	
		set("material", "gold");
		set("wield_msg", "$N把$n拿在手上$N似乎要翩翩起舞。\n");
		set("unwield_msg", "$N將手中的$n僅慎的收入懷中。\n");
        }
	init_unarmed(50);
	setup();
}
int wield()
{
 if(!this_player()) return 1;
 if( this_player()->query("class") != "dancer" )
    return notify_fail("只有舞者能用喔。\n");
 set_heart_beat(1);
 ::wield();
 return 1;
}

