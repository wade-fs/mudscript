inherit ITEM;

void create()
{
        set_name("新娘捧花", ({ "wedding flower", }) );
        set("unit", "束");
        set("long", "一束包裝華美的新娘捧花，通常是結婚時穿的.\n");
	set_weight(300);
	set("value",300);
	setup();
}
