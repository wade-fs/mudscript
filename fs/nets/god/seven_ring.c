// made by ccat
// G,鴷澦call @峏~I,洏峈僂々]j簡.

#include <ansi.h>
#include <armor.h>
inherit FINGER;
object user;
int kar;
void create()
{
     set_name( "" + HIY + "" + HIW + "C" + HIY + "" + HIW + "" + HIY + "" + HIW + "" + HIY + "" + HIW + "" + NOR + "",({"seven_ring"}) );
     set_weight(2500);
     if( clonep() ) 
               set_default_object(__FILE__);
     else {
            set("long","oOuC滫榦玊棓AC~菑C堹_蠕.\n");
            set("no_sell",1);
     set("no_get",1);
            set("no_auc",1);
            set("no_drop",1);
            set("no_put",1);
            set("no_give",1);
            set("unit", "");             
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
        user = this_player();     // o洏峈
        kar = user->query("kar");
        message_vision("$NN" + HIY + "" + HIW + "C" + HIY + "" + HIW + "" + HIY + "" + HIW + "" + HIY + "" + HIW + "" + NOR + "WA" + HIY + "" + HIW + "C" + HIY + "" + HIW + "" + HIY + "" + HIW + "" + HIY + "" + HIW + "" + NOR + "伂oXC~C\n",user);
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
      message_vision(HIR+"@D~悀Cm玊楰Eg茈XA~$N擗漠蚢L!!!\n"+NOR,enemy[i]);
      enemy[i]->add("kee",-300);
      enemy[i]->add("eff_kee",-300);
           }
     if( j == 12)
     {
message_vision(YEL+"@D~悀Cm玊楰Eg茈XA~$N擗漠茈X!!!\n"+NOR,enemy[i]);
      enemy[i]->add("kee",-500);
      enemy[i]->add("eff_kee",-500);
     }
     if( j == 18)
     {
message_vision(HIY+"@D~悀Cm玊棳CC}A籠n$N!!!\n"+NOR,user);
  user->delete_busy();
     }
     if( j == 24)
     {
message_vision(HIG+"@D~悀Cm玊棳CC}A籠n$N!!!\n"+NOR,user);
enemy[i]->set_temp("no_power",1);
enemy[i]->apply_condition("no_power",2);
     }
     if( j == 30)
     {
message_vision(HIB+"@D臟~悀Cm玊棳CC}A$N籠nF!!!\n"+NOR,enemy[i]);
      enemy[i]->start_busy(1);
     }
     if( j == 36)
     {
message_vision(HIC+"@DQ~悀Cm玊棳CC}A$N籠nF!!!\n"+NOR,enemy[i]);
      enemy[i]->start_busy(2);
     }
     if( j == 42)
     {
message_vision(HIM+"@D~悀Cm玊棳CC}A籠n$N!!!\n"+NOR,user);
     user->receive_curing("kee",300);
     user->receive_heal("kee",300);
     }

  }
  return;
}

