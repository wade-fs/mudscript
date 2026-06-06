// make by Onion
#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("紫絳衫", ({ "purple cloth", "cloth" }) );
	set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "彩雲般的絳紫暈染整件衣衫, 層層疊疊的紫帶垂飾的煞是好看。\n");
		set("unit", "件");
		set("value", 2000);
		set("material", "cloth");
		set("gender_only", "女性");
		set("armor_prop/armor", 6);
	}
	setup();
}

