#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
       set_name( HIG"人皮面具"NOR, ({"mask"}) );

        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","張");
                set("value",10);
                set("material","leather");
                set("armor_prop/armor", 1);
                set("armor_prop/id", ({"masker"}) );
                set("armor_prop/name", ({"無名刀俠"}) );
                set("armor_prop/short", ({"無名刀俠(Masker)"}) );
                set("armor_prop/long", ({
                    "一個眉頭深鎖的男子,俊俏的臉龐中帶著一絲的憂鬱，而滿頭黑髮
                    中一撮突兀的白髮遮住了半邊的臉龐，更令人有著莫測高深的神祕
                    感覺...\n"
                }) );
        }
        setup();
}
