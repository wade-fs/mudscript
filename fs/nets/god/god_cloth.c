// Qc by Anmy 98/7/6
#include <armor.h>
#include <ansi.h>
inherit CLOTH;
object user;
void create()
{
        set_name(""HIR"»"HIW"ñ"HIR"°"HIW"Ä"HIR"¦"HIW"Ð"HIR"¦"HIW"ç"NOR"",({"bird_cloth","cloth"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "¥ó");
                set("no_put",1);
                set("no_give",1);
                set("no_sell",1);
                set("no_auc",1);
   set("no_get",1);
                set("no_drop",1);
                set("material","gem");
                set("armor_prop/armor",20);
                set("armor_prop/parry",10);
                set("armor_prop/dodge",5);
                set("armor_prop/move",5);
                
        }
        setup();
}

int init()
{
    add_action("do_wear","wear");
}
int do_wear(string str)
{
::wear();
 if( query("equipped") )
 {
   user = this_player();
   message_vision("$N±N"HIR"»"HIW"ñ"HIR"°"HIW"Ä"HIR"¦"HIW"Ð"HIR"¦"HIW"ç"NOR"©¹¨­¤W¤@¬ï¡A"HIR"»"HIW"ñ"HIR"°"HIW"Ä"HIR"¦"HIW"Ð"HIR"¦"HIW"ç"NOR"Àþ®ÉÄÆ¥X¹Î¹Î¶³Ãú±N$NÅ¢¸n¡C\n",user);
   set_heart_beat(1);
 }
}

void heart_beat()
{
	if( !user ) return;
 if( user->is_fighting() && query("equipped"))
{
 if( random(100) > 80)
   {
     user->receive_curing("kee",300);
     user->receive_heal("kee",300);
message_vision(HIW"¦Ð¦ç©Ò´²¥Xªº¶³ÃúºCºCªº±N$Nªº¶Ë¤fÂ¡¦X¤F.\n"NOR,user);
     }
       }
return;
   }
