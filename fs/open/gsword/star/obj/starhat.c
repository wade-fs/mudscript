#include <ansi.h>
inherit EQUIP;

void create()
{
 set_name("星護之盔",({"starhat","starhat"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","由星之石所鑄 , 具有不錯的防護力 .\n");
        set("unit","件");
        set("value",2000);
        set("material","cloth");
        set("armor_type","head");
        set("armor_prop/armor",11);
        set("armor_prop/parry", 2);

        }
        setup();
}
