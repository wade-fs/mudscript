// made by urd blacksword for avater

#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("黑劍",({"black sword","black","sword"}));
        set_weight(5000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","把");
	set("long","這是聖者從美德試鍊場中收伏的惡魔所變成的劍，由於\n這把劍是吸收了惡魔的力量，所以連英王都怕這把劍。\n");
                set("material","crimsonsteel");
                set("value",500000);
        } //end of else
	init_sword(99);

	set("wield_msg","$N從身後取出$n握在手中。\n");
	set("unwield_msg","$N把$n放回身後的劍銷。\n");

        setup();

} // eof create()

int wield()
{
	if ((string)this_player()->query("class") != "avatar")
		return notify_fail("只有聖者團的才可以用我！！\n");
        else {
                ::wield();
        } //end of else


     return 1;

} //EOF
