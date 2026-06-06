#include <armor.h>
#include <ansi.h>
inherit NECK;
object user;
void create()
{
        set_name( HIB + "修羅戰鬥項鏈" + NOR ,({"fiend neck","neck"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", "冥殿修羅專用的防護用具。\n");
                set("unit", "件");
                set("value",10000);
                set("material","gem");
                set("armor_prop/armor",4);
        }
        setup();
}


