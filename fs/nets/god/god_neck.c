#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
set_name(""HIY"¯"HIW"«"HIB"À"HIW"s"HIY"¤"HIW"§"HIB"²"HIW"´"NOR"",({"dragon_eye","eye"}));
      set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
       set("long","¥Ñ¯«ÀsªºÅì¤ù , ©Ò¤Û¤Æ¥X¨ÓªºÅ@²Å\n");
          set("unit","¥ó");
                set("no_sell",1);
                set("no_give", 1);
                set("no_auc",1);
                set("no_drop",1);
   set("no_get",1);
                set("no_put",1);
        set("material","crimsonsteel");
                set("armor_prop/armor",15);
                set("armor_prop/parry",5);
                set("armor_prop/force",7);
set("wear_msg","$NÀ¹°_$n¡A¥|©P°¨¤W«G°_¥ú¨~¡A¯«Às¤§²´¶}©lµo´§®Ä¥Î . \n");
 }
        setup();
}
