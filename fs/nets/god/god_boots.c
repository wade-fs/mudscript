#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
set_name("" + HIW + "" + HIC + "l" + HIW + "" + HIM + "" + HIW + "" + HIB + "" + HIW + "" + HIY + "u" + NOR + "",({"Sun_shoes","shoes"}));
     set_weight(2400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","埳u皉lW荈O , W , At蚺jW\n");
               set("unit","");
                set("no_sell",1);
   set("no_get",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
                set("no_put",1);
               set("material","leather");
                set("armor_prop/armor",15);
                set("armor_prop/move",10);
                set("armor_prop/dodge",10);
set("wear_msg","$NW$nA$nM荈秅F@ . \n");
 }
        setup();
}
