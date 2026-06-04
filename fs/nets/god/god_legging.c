#include <armor.h>
#include <ansi.h>
inherit LEGGINGS;
void create()
{
set_name( "" + HIC + "" + HIM + "B" + HIC + "" + HIM + "" + HIC + "" + HIM + "@" + HIC + "" + HIM + "" + NOR + "",({"rain_god_legging","legging"}));
set_weight(3500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","o@OѴxޤѮ𪺫BߥyӦ\n");
                set("unit", "");
                set("no_sell",1);
                set("no_give", 1);
                set("no_auc",1);
   set("no_get",1);
                set("no_drop",1);
                set("no_put",1);
set("material","iron");
                 set("armor_prop/armor",15);
                set("armor_prop/parry",7);
                set("armor_prop/move",5);
                set("armor_prop/dodge",5);
set("wear_msg","$NW$nAPıۤv֦FIBO .\n");
 }
        setup();
}
