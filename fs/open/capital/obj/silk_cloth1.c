
inherit EQUIP;
													
void create()
{
	set_name("紅絲綢緞長袍", ({ "red silkcloth", "cloth" }) );
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("armor_type", "cloth");
		set("value", 500);
		set("armor_prop/armor", 1);
	}
}
									
