#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
set_name("" + HIY + "" + HIW + "" + HIY + "" + HIW + "" + HIY + "" + HIW + "@" + HIY + "" + HIW + "" + NOR + "",({"light_gloves","gloves"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                 set("long",
                 "~ݰ_M@_ , OAWL\n"
                 "N|oXLPۤ񪺫¤O C\n");
                set("unit","");
                set("no_sell",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
   set("no_get",1);
                set("no_put",1);
                set("material","leather");
                set("armor_prop/armor",15);
                set("armor_prop/parry",10);
                set("armor_prop/force",5);
set("wear_msg","|P~ME$NA$nwbAWΦ@DO@C\n");
 }
        setup();
}
