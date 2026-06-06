// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("精鋼護膝",({"steel legging","legging"}) );
        set_weight(12000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","用精鋼燽成的護膝,上面有精細的雕刻.\n");
        set("unit","件");
        set("value", 750);
        set("material","steel");
        set("armor_type","leggings");
	set("armor_prop/armor", 5);
	}
        setup();
}
