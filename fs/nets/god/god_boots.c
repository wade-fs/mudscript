#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
set_name(""HIW"°"HIC"l"HIW"¤"HIM"é"HIW"¾"HIB"Ô"HIW"¹"HIY"u"NOR"",({"Sun_shoes","shoes"}));
     set_weight(2400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","¦¹¾Ô¹u¾Ö¦³¯à°l¤W¤Ó¶§ªº¯à¤O , ¬ï¤W¥¦«á , ¯àÅý§Aªº³t«×¤j¼W\n");
               set("unit","¥ó");
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
set("wear_msg","$N¬ï¤W$n¡A$n©M¤Ó¶§²£¥Í¤F¦@»ï . \n");
 }
        setup();
}
