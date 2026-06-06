// 鐵鍊
#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("鐵鍊",({"iron ligature","iron","ligature"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","條");
        set("value",30000);
        set("no_get", 1);         
	set("material","iron");
	set("rigidity",50);
	set("long",
	"這是一條精鋼所鑄得鐵鍊。\n");
	}
	init_whip(110);
	setup();
}
