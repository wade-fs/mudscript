#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name(HIB + "修羅戰鬥盔" + NOR, ({ "fiend hat", "hat" }) );
        set_weight(4000);
                if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "冥殿修羅專用的頭部防護用具。\n");
                set("unit", "條");
                set("value",10000);
                set("material", "fur");
            set("wear_msg",HIC + "$N一戴上了$n，冥殿之氣湧現，殺氣倏地提高了許\多。\n" + NOR);
                set("armor_type", "head");
                set("armor_prop/armor", 10);

        }
        setup();
}


