// kame_suit.c

inherit EQUIP;

void create()
{
        set_name("寒玉護臂",({"yu armband","armband"}) );
        set_weight(12000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","用西域上等寒玉製成的護臂,上面有美麗的花紋\n");
        set("unit","副");
        set("value", 200000);
        set("material","steel");
        set("armor_type","armbands");
	set("armor_prop/armor", 7);
	}
        setup();
}
