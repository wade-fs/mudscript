#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name(HIB"修羅戰鬥服"NOR,({"fiend cloth","cloth"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","件");
        set("value", 10000);
        set("armor_type","cloth");
        set("wear_msg",HIC"$N穿上了$n之後,全身散發出雄渾的鬥氣!!\n"NOR);
        set("remove_msg",HIC"$N將$n脫下之後,雄渾的鬥氣慢慢地消散了!!\n"NOR);
        set("armor_prop/armor", 15);
        set("armor_prop/dodge", 5);
        set("armor_prop/unarmed", 10);
        set("armor_prop/force", 2);
        set("long","
冥殿修羅專用的戰鬥服，以神獸金.木.水.火.土麒麟之鱗皮精煉混織而成。
刀槍不入,水火不侵。\n");
        }
         setup();
}


