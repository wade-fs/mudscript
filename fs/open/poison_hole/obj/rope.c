// torch

inherit ITEM;

void create()
{
        set_name("繩索", ({ "rope", }) );
        set("unit", "組");
        set("long", "一組可以用來攀爬岩石的繩索，可以用(use rope)來使用他。\n");
       set("value", 100);
	setup();
}
