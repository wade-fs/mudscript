// made by ccat
// ¤Gª©,§ï¥¿¥H©¹¶·call ¤@­ÓÁô§Î©ÇÃ~ªº¯ÊÂI,¨Ï¥ÎªºÅÜ¼Æ¤]¤j¬°Â²¤Æ.

#include <ansi.h>
#include <armor.h>
inherit FINGER;
object user;
int kar;
void create()
{
     set_name( ""HIY"¤"HIW"C"HIY"¦"HIW"â"HIY"¥"HIW"É"HIY"§"HIW"Ù"NOR"",({"seven_ring"}) );
     set_weight(2500);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","³o¬O¥u¤C¦âªº±m¥É§Ù«ü¡A¨ä¤C¦â¥ú¨~¦³µÛ¤CºØ¯«©_®Ä¯à.\n");
            set("no_sell",1);
     set("no_get",1);
            set("no_auc",1);
            set("no_drop",1);
            set("no_put",1);
            set("no_give",1);
            set("unit", "¥ó");             
            set("material","steal");
            set("armor_type","finger");            
            set("armor_prop/armor",5);
                set("armor_prop/parry",5);
                set("armor_prop/move",5);
                set("armor_prop/dodge",5);
 }         
        setup();
}
void init()
{
     add_action("do_wear","wear");
}

int do_wear(string str)
{

     ::wear();
     if ( query("equipped") )
     {
        user = this_player();     // ¨ú±o¨Ï¥ÎªÌ
        kar = user->query("kar");
        message_vision("$N±N"HIY"¤"HIW"C"HIY"¦"HIW"â"HIY"¥"HIW"É"HIY"§"HIW"Ù"NOR"À¹¤W¡A"HIY"¤"HIW"C"HIY"¦"HIW"â"HIY"¥"HIW"É"HIY"§"HIW"Ù"NOR"Àş®Éµo¥X¤C¦â¥ú¨~¡C\n",user);
        set_heart_beat(1);
     }
}

void heart_beat()
{
  object *enemy,who;
  int i,j;

  if( !objectp(user) ) 
  { set_heart_beat(0);
     return;
  }
  if( user->is_fighting() && query("equipped") )
  {
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
j=random(43);
     if( j == 6)
     {
      message_vision(HIR+"¤@¹D¬õ¦â¥ú¨~¥Ñ¤C±m¥É§Ù¿E®g¦Ó¥X¡A¥ú¨~¥Ñ$NÅé¤º³zÅé¦Ó¹L!!!\n"+NOR,enemy[i]);
      enemy[i]->add("kee",-300);
      enemy[i]->add("eff_kee",-300);
           }
     if( j == 12)
     {
message_vision(YEL+"¤@¹D¾í¦â¥ú¨~¥Ñ¤C±m¥É§Ù¿E®g¦Ó¥X¡A¥ú¨~¥Ñ$NÅé¤º³zÅé¦Ó¥X!!!\n"+NOR,enemy[i]);
      enemy[i]->add("kee",-500);
      enemy[i]->add("eff_kee",-500);
     }
     if( j == 18)
     {
message_vision(HIY+"¤@¹D¶À¦â¥ú¨~¥Ñ¤C±m¥É§ÙºCºC´²¶}¡Aº¥º¥Å¢¸n¦í$N!!!\n"+NOR,user);
  user->delete_busy();
     }
     if( j == 24)
     {
message_vision(HIG+"¤@¹Dºñ¦â¥ú¨~¥Ñ¤C±m¥É§ÙºCºC´²¶}¡Aº¥º¥Å¢¸n¦í$N!!!\n"+NOR,user);
enemy[i]->set_temp("no_power",1);
enemy[i]->apply_condition("no_power",2);
     }
     if( j == 30)
     {
message_vision(HIB+"¤@¹DÂÅ¦â¥ú¨~¥Ñ¤C±m¥É§ÙºCºC´²¶}¡AÀş¶¡$Nµ¹Å¢¸n¦í¤F!!!\n"+NOR,enemy[i]);
      enemy[i]->start_busy(1);
     }
     if( j == 36)
     {
message_vision(HIC+"¤@¹DÀQ¦â¥ú¨~¥Ñ¤C±m¥É§ÙºCºC´²¶}¡AÀş¶¡$Nµ¹Å¢¸n¦í¤F!!!\n"+NOR,enemy[i]);
      enemy[i]->start_busy(2);
     }
     if( j == 42)
     {
message_vision(HIM+"¤@¹Dµµ¦â¥ú¨~¥Ñ¤C±m¥É§ÙºCºC´²¶}¡Aº¥º¥Å¢¸n¦í$N!!!\n"+NOR,user);
     user->receive_curing("kee",300);
     user->receive_heal("kee",300);
     }

  }
  return;
}

