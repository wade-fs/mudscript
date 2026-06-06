//book.c

#include <ansi.h>
inherit ITEM;

void create()
{
   set_name(HIW + "六脈神劍經" + NOR,({"six book","book"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long",
"這本書乃是記載大理段式奇功\『六脈神劍』的寶經。\n");
		set("value",800);
		set("material", "paper");
}
        setup();
}
