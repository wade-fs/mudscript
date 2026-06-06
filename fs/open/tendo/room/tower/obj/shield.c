#include <armor.h>
#include <ansi.h>
inherit SHIELD;
object user;
void create()
{
        set_name( HIB "修羅戰鬥盾" NOR ,({"fiend shield","shield"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
  set("long", "冥殿修羅專用的防護用具。\n");
                set("unit", "個");
                set("value",10000);
                set("material","gem");
                set("armor_prop/armor",10);
                set("armor_prop/parry",3);
        }
        setup();
}

