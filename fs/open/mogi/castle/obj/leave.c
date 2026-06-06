// 解謎用item

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name("三葉仙蘭之葉", ({ "three_leaf" }));
	set_weight(5);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "片");
		set("long",
"傳說中的三葉仙蘭之葉，據說有辟毒之效。\n");
		set("value", 1000000);
		set("material", "paper");
	}
        setup();
}
 
