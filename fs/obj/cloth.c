// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>
#include <globals.h> // Added this to include F_NAME

inherit CLOTH;
inherit F_NAME;    // Explicitly inherit F_NAME here

void create()
{
	set_name("布衣", ({ "cloth" }) ); // Revert to direct call
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/armor", 1);
	}
	// 移除 ::setup()，因為這裡的對象繼承結構似乎不直接支援 ::setup() 語法，或者 setup() 不需顯式呼叫
}
int query_autoload() { return 0; }
