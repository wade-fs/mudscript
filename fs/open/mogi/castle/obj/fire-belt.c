//焚天魔王 eq
inherit EQUIP;
#include <ansi.h>
void create()
{
        set_name(HIY + "祝" + HIR + "融" + HIY + "腰" + HIR + "帶" + NOR, ({ "fire belt" ,"belt" }) );
        set_weight(300);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);   
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","火神祝融慣用的腰帶，多年前被焚天魔王搶奪而來。\n");
                set("unit", "件");
                set("value", 70000);
                set("material","leather");
                set("armor_type", "waist");
                set("armor_prop/armor",7);
                set("armor_prop/dodge",3);
                set("armor_prop/move",3);
				set("need_exp",2000000);
                setup();

        }
}

int query_autoload()
{
 return 1;
}
