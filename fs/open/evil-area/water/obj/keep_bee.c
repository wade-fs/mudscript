inherit ITEM;

void create()
{
	set_name("驅觢木",({"chu-wood","wood"}));
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else
	{
		set("value",100);
		set("unit","根");
		set("long","邪靈界用來驅除鼓蜂的木頭，木頭本身會散發出一種令鼓蜂討厭的氣味。\n");
	}
	setup();
}
