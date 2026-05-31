// made by ccat
#include <ansi.h>
#include <weapon.h>
inherit STABBER;
void create()
{
set_name(HIR"¤Ñ´L"HIW"¯}Å]®°"NOR,({"god_evil_fan","fan"}));     
     set_weight(15000);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","³o¬O¤@§â©_§®ªº¦Ð®°, ¯àÀH¤ß©Ò±ýªºÅÜ´«.\n"
                  +"( change <type>, ex: change sword )\n"
                  +"( type : unarmed sword blade whip dagger stabber )\n");
set("wield_msg", "¥u¨£¤Ñ¤W­°¤U¤@¹D«æ¹p¡A¦b§Aªº¤â¤W¥X²{¤F¤@§â±ÙÅ]ªº§Q¾¹.\n");
set("unwield_msg", "$N±N$nÀH¦a¤@´¡¡A$n°¨¤W´N®ø¥¢¦bªÅ®ð¤¤¤F\n");                    
            set("unit", "¥ó");             
            set("value",2000);
            set("material","steal");
           }         
        init_stabber(100);
        setup();
}
void init()
{
    add_action("do_change","change");
}
int do_change(string str)
{
   switch(str)
   {
     case "unarmed":
           set("skill_type", "unarmed");
set_name(""HIM"À"HIW"s"HIM"®"HIW"ð"HIM"«"HIW"ü"HIM"À"HIW"ô"NOR"",({"figring"}));
write(""HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¶}©l¤Û¤Æ.\n"HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¤Æ¦¨¤F¤@Âù"HIM"À"HIW"s"HIM"®"HIW"ð"HIM"«"HIW"ü"HIM"À"HIW"ô"NOR".\n");
           break;
     case "sword":
           set("skill_type", "sword");
           set_name( ""HIM"¨"HIW"â"HIM"·"HIW"¥"HIM"¼"HIW"C"NOR"",({"sun_fire_sword"}));
write(""HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¶}©l¤Û¤Æ.\n"HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¤Æ¦¨¤F"HIM"¨"HIW"â"HIM"·"HIW"¥"HIM"¼"HIW"C"NOR".\n");
           break;
     case "blade":
           set("skill_type", "blade");
           set_name( ""HIM"À"HIW"s"HIM"§"HIW"u"HIM"¤"HIW"M"NOR"",({"iceblade"}));
write(""HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¶}©l¤Û¤Æ.\n"HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¤Æ¦¨¤F"HIM"À"HIW"s"HIM"§"HIW"u"HIM"¤"HIW"M"NOR".\n");
           break;
     case "dagger":
           set("skill_type", "dagger");
           set_name( ""HIM"Ä"HIW"^"HIM"À"HIW"s"HIM"¤"HIW"P"NOR"",({"god dagger","dagger","god"}));
write(""HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¶}©l¤Û¤Æ.\n"HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¤Æ¦¨¤F"HIM"Ä"HIW"^"HIM"À"HIW"s"HIM"¤"HIW"P"NOR".\n");
           break;
     case "whip":
           set("skill_type", "whip");
           set_name( ""HIM"À"HIW"s"HIM"Å"HIW"ì"HIM"Ã"HIW"@"NOR"",({"god whip","whip","god"}));
write(""HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¶}©l¤Û¤Æ.\n"HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¤Æ¦¨¤F"HIM"À"HIW"s"HIM"Å"HIW"ì"HIM"Ã"HIW"@"NOR".\n");
           break;
     case "stabber":
     case "fan":
           set("skill_type", "stabber");
           set_name(""HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"",({"god fan","fan","god"}) );
write(""HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"¶}©l¤Û¤Æ.\n"HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"ÅÜ¦^­ì¨Óªº®°¤l.\n");
           break;
     default:      
write(""HIM"¤"HIW"E"HIM"¤"HIW"Ñ"HIM"¦"HIW"Ð"HIM"®"HIW"°"NOR"µLªk¤Û¤Æ.\n");
   }
     return 1;
}
