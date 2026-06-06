#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        set_name( HIR + "聖火令" + NOR,({"Fire-stick"}) );
     set_weight(20000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","聖火教陣教之寶，一共有六隻，每隻皆透出詭異的暗紅光芒。\n");
            set("unit", "把");             
            set("value",300000);
            set("material","crimsonsteel");
            set("no_give",1);
            set("no_drop",1); 
            set("no_sell",1);
            set("armor_prop/attack", 5);
            set("armor_prop/force", 10);
            set("armor_prop/stick", 10);
            set("armor_prop/move", -10);
        }
        init_stick(120);

        set("wield_msg", "$N感覺到聖火教歷代教主宏大的功\力，源源不斷的湧入$N的雙手\n");
        set("unwield_msg", "$n一經離手，所有的力量漸漸從$N的丹田流失。\n");

        setup();
}                   
