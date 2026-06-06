#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name("乾坤頭帶", ({ "boris hat", "hat" }) );
        set_weight(4000);
                if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "聖火教教主專用的頭部防護用具。\n");
                set("unit", "條");
                set("value",150000);
                set("material", "fur");
            set("wear_msg","$N一戴上了$n，乾坤卦象湧現，悟性倏地提高了許\多。\n");
                set("armor_type", "head");
                set("armor_prop/armor", 10);
                
        }
        setup();
}                 
