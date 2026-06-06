// kame_suit.c

inherit EQUIP;

void create()
{
	set_name("狼頭盔",({"wolf hat","hat"}));
	set_weight(500);
        if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","由狼皮所製 , 具有不錯的防護力 .\n");
        set("unit","件");
	set("value",1000);
	set("material","cloth");
	set("armor_type","head");
	set("armor_prop/armor",5);
	}
        setup();
}
