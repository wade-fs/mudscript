// torch
#include <weapon.h>

inherit STABBER;

void create()
{
        set_name("木頭", ({ "torch", }) );
	set_weight(1000);
          set("unit", "根");
          set("long", "一根可以當材燒的木頭，也許\你可以用來照明，"+
		      "平時也可以拿來打人。\n");
	  // light_up 大於 0 表示可以燃燒的心跳數
          set("light_up", 200);
	  set("burned", "快燒光的");
	  set("value", 10);
	  set("material", "wood");
	  set("wield_msg", "$N「唰」地一聲抽出一根$n握在手中。\n");
	  set("unwield_msg", "$N將手中的$n隨手一放。\n");
	init_stabber(5);
	setup();
}
