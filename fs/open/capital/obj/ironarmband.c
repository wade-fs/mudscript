
inherit EQUIP;
							
void create()
{
        set_name("鐵臂環",({"iron armband","armband"}) );
	set_weight(5000);
	set("gender_only", "男性");
	      	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","。\n");
	set("unit", "隻");
	set("value",500);
	set("material","iron");
	set("armor_type", "armbands");
        set("armor_prop/armor",2 );
	}
        setup();
}
