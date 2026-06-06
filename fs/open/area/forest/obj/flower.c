inherit ITEM;

void create()
{
	set_name("玻璃花",({"glass flower","flower"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("long","一個清澈透明的淡藍色水晶球，大小約一個手掌大。\n");
		set("value",1000);
		set("unit","株");
	}
	setup();
}
