//焚天魔王 armor
#include <armor.h>
#include <ansi.h>
inherit EQUIP;


void create()
{
        set_name(HIR"麒麟火鎧"NOR,({"fire armor","armor"}) );
	set_weight(7000);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
一件由火麒麟麟片加上特異金屬製成，上面燃燒著奔騰的烈火，是萬年的寶物。
\n");
        set("unit", "套");
        set("value",200000);
        set("armor_type","cloth");
        set("material","crimsonsteel");
	set("armor_prop/armor",22);
	set("armor_prop/unarmed",7);
        set("armor_prop/parry",7);
		set("need_exp",3000000);
set("wear_msg", HIY"$N穿上$n"HIY"，呼然一聲烈火已將$N的四周護住\n"NOR);
set("remove_msg", HIY"$N將$n卸了下來"HIY"，四周的火焰也慢慢消失了。\n"NOR);
        }
        setup();
}
int query_autoload()
{
 return 1;
}
