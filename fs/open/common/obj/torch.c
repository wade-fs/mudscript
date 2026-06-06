// torch

inherit ITEM;

void create()
{
        set_name("木頭", ({ "torch", }) );
        set("unit", "根");
        set("long", "一根可以當材燒的木頭，也許你可以用來照明。\n");
	// light_up 大於 0 表示可以燃燒的心跳數
	set ("light_up", 200);
	set("value", 10);
        setup();
}
