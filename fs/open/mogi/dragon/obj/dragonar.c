//報酬 armor
#include <armor.h>
#include <ansi.h>
inherit EQUIP;


void create()
{
          set_name(HIR + "龍鳳護臂" + NOR,({"dragon armbands","armbands"}));
set_weight(5000);
        set("no_sell",1);
        set("no_auc",1);
set("no_get",1);
set("no_give",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","傳說由龍皮和鳳皮做成的護臂
\n");
        set("unit", "套");
        set("value",200000);
set("armor_type","armbands");
        set("material","crimsonsteel");
        set("armor_prop/armor",20);
        set("armor_prop/unarmed",7);
        set("armor_prop/parry",7);
set("wear_msg", HIY + "$N穿上$n，出現了一對龍鳳向$N四周護住雙臂\n" + NOR);
set("remove_msg", HIY + "$N將$n卸了下來，龍鳳也慢慢消失了。\n" + NOR);
        }
        setup();
}
