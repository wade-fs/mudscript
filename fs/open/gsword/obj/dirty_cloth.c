// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("骯髒襯衫",({"dirty cloth","cloth"}) );
        set_weight(4500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","一件很髒的工作襯衫,上面沾滿了汗與灰.\n");
        set("unit","件");
        set("value",150);
	set("material","cloth");
        set("armor_type","cloth");
	set("armor_prop/armor", 2);
	}
        setup();
}
