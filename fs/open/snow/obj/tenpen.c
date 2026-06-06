// sword.c : an example weapon

#include <weapon.h>
#include <ansi.h>

	inherit STABBER;

void create()
{
	set_name(HIW "天誅筆" NOR,({"ten pen","pen"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","支");
		set("value",10000);
		set("material", "steel");
		set("long",@LONG
這把是獨孤世家的家寶之一﹐名曰「天誅」
相傳此筆不須任何油墨即可寫字﹐且寫出來的字
呈金黃色﹐此外﹐又可用來作為攻擊武器﹐但是
一般的人若不知道方法﹐是無法發揮出真正的效
果的。
LONG);
		set("wield_msg",@LONG
$N從懷間抽出一支$n﹐閃閃發光﹐照得四周都變成金黃顏色﹗
LONG);
	}
	init_stabber(50,SECONDARY);
	setup();
}
