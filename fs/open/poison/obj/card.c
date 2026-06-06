inherit ITEM;

void create()
{
        set_name("拜帖", ({ "card" }) );
 if( clonep() )
                set_default_object(__FILE__);
 else {
        set("unit", "張");
        set("long", "這是一張冥蠱魔教的拜帖。\n");
	set("value", 0);
}
        setup();
}
