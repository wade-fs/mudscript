// 配戴此armor的mob exp:160萬
#include <armor.h>
#include <ansi.h>
inherit CLOTH;


void create()
{
        set_name("妖氣戰袍",({"ghost cloth","cloth"}) );
	set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
一件散發著濃烈妖氣的戰袍。
\n");
        set("unit", "套");
        set("value",10000);
        set("material","crimsonsteel");
	set("armor_prop/armor",20);
	set("armor_prop/unarmed",2);
        set("armor_prop/force",2);
        }
        setup();
}
