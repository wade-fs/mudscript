// for lovemay by ACKY
// 長期提供 bug

#include <ansi.h>
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name( HIM + "誘" + HIR + "惑" + HIY + "魅" + HIC + "影" + NOR , ({"sex cloth", "cloth" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set( "unit", "件" );
		set( "value", 0 );
		set( "material", "cloth" );
		set( "long",
			"這是一件愛玫專屬的衣服，傳說能色誘每一個人，使人神魂顛倒。\n" );
		set( "wear_msg",
			"$N突然擺\出撩人的姿態，穿起一件$n，全身散發出迷人的香味，使週遭的人都想入非非。\n" );
		set( "unequip_msg",
			"$N瞬間把$n脫了下來，一時之間$N的美色不再，四周的人也恢復了神態。\n" );
		set( "armor_prop/armor", 1 );
	}
	setup();
}

int query_autoload()
{
	return 1;
}
