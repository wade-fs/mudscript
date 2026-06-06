#include <ansi.h>
#include <armor.h>
inherit CLOTH;
void create()
{
        set_name(HIW + "寒蠶袍" + NOR, ({ "ice cloth","cloth"}) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","件");
                set("long", "冰蠶寒衣乃棌天山冰蠶所吐絲而編織，其絲強韌，冰冷，需有深厚的內力方可穿著！\n");
                set("material","crimsonsteel");
                set("value",100000);
                  set("armor_prop/armor",20);
                set("armor_prop/dodge",6);
                set("armor_prop/parry",6);
                set("armor_prop/move",5);
                set("armor/type","cloth");
                set("wear_msg", "$N將$n穿在身上，頓時一片寒芒罩住$N！\n");
                set("unwear_msg", "$N將$n脫下纏成一條絲綢繫在腰間。\n");
              }

        setup();
}


