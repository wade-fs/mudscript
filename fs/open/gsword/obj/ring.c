// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("黃銅指戒",({"copper ring","ring"}) );
        set_weight(2500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","一只黃銅指戒.\n");
        set("unit","件");
        set("value", 500);
        set("material","copper");
        set("armor_type","finger");
        set("armor_prop/force", 1);
        set("armor_prop/armor", 3);
	}
        setup();
}
