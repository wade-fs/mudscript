// 網聚獎品by cgy(22/10/00)

#include <armor.h>
#include <ansi.h>

inherit PANTS;

void create()
{
	set_name( HIC"小雪球玄天冰晶裙"NOR, ({ "acky_skirt", "skirt" }) );
	set_weight(1);
	if( clonep() )
                set_default_object(__FILE__);
        else {
                set( "unit", "件" );
                set( "value", 0 );
                set("long", HIC"這是一件以玄天冰晶製作的裙襬, 似乎賦予最強的保護。\n" );
		set("wear_msg", HIC"$N穿上$n"HIC", 看起來真是可愛極了, 使得敵人都捨不得欺負$N。\n"NOR );
		set("unequip_msg", HIC"$N脫下了$n"HIC", 彷彿看到小雪球不停地哭哭啼啼...\n"NOR );
                set("material", "steel" );
                set("armor_prop/armor", 14 );
	        set("no_auc",1);
        	set("no_sell",1);
        	set("no_give",1);
         	set("no_put",1);
        	set("no_drop",1);
        	set("no_get",1);
                set("armor_prop/parry", 8);
                set("armor_prop/force", 8);
                set("armor_prop/dodge", 8);
        }
                setup();
}
