//焚天魔王 armor
#include <armor.h>
#include <ansi.h>
inherit EQUIP;


void create()
{
        set_name(HIR"妖帥面罩"NOR,({"ghost armor","armor"}) );
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
       一件普通的面罩，給炎龍谷中的守衛穿的
\n");
        set("unit", "套");
        set("value",200000);
        set("armor_type","cloth");
        set("material","crimsonsteel");
        set("armor_prop/armor",15);
        }
        setup();
}
