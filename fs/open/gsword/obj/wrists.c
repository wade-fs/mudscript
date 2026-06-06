// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("木製手環",({"wood wrists","wrists"}) );
        set_weight(4500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","木製的手工木環,可以提供些許\的保護.\n");
        set("unit","件");
        set("value", 250);
        set("material","wood");
        set("armor_type","wrists");
	set("armor_prop/armor", 2);
	}
        setup();
}
