#include <armor.h>
#include <ansi.h>
inherit WAIST;
void create()
{
set_name("" + HIR + "" + HIW + "m" + HIG + "" + HIW + "i" + HIR + "" + HIW + "y" + HIG + "" + HIW + "a" + NOR + "",({"rainbow_belt","belt"}));
             set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","WۤCmC , o۵L񪺥~C\n");
              set("unit","");
                set("no_sell",1);
   set("no_get",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
                set("no_put",1);
                set("material","gem");
                set("armor_prop/armor",15);
                set("armor_prop/parry",5);
                set("armor_prop/dodge",5);
                set("armor_prop/move",5);
                set("wear_msg","$N˳ư_$nA$NHۤƥXnXDmi~C\n");
 }
        setup();
}
