// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIC + "鱗甲藍鍛衣" + NOR,({"blue cloth","cloth"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",@LONG
這件寶衣是獨孤世家的家寶中最為珍貴的一件﹐
名曰「鱗甲藍鍛衣」﹐整件衣服由藍色的鱗甲作
成﹐閃閃發亮﹐是一件價值連城的寶貝。
LONG);
		set("unit", "件");
		set("material", "cloth");
		set("value",100000);
		set("armor_prop/armor",10);
		set_temp("apply/dodge",10);
	}
	setup();
}
