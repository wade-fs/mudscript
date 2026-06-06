#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("烤龍腿", ({ "dragon leg","leg" }) );
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "香噴噴的烤龍腿, 香料的味道很不錯.\n");
                set("unit", "條");
                set("value", 100);
                set("食物", ([
                        "剩" : 5,       
                        "供應": 70,
                ]) );
        }
        setup();
}
