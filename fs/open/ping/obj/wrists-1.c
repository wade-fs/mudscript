inherit EQUIP;
void create()
{
        set_name("玉製手環",({"jade wrists","wrists"}) );
        set_weight(7000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","一件柔黃軟玉製的手環.\n");
        set("unit","件");
        set("value",1000);
	set("material","jade");
        set("armor_type","wrists");
	set("armor_prop/armor", 1);
	set("armor_prop/dodge", 5);
	}
        setup();
}
