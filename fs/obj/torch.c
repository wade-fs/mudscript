// torch

inherit ITEM;

void create()
{
        set_name("木頭", ({ "torch", }) );
        set("unit", "根");
        set("long", "一根可以當材燒的木頭。\n");
	set("burned","快燒光的");
	// light_up 大於 0 表示可以燃燒的心跳數
      set("light_up",1000);
       set("value", 100);
	setup();
}
