
// sun_armband.c
#include <armor.h>
#include <ansi.h>
inherit EQUIP;
object user;
void create()
{

set_name("" + HIB + "" + HIW + "" + HIB + "" + HIW + "" + HIB + "" + HIW + "u" + HIB + "" + HIW + "" + NOR + "",({"God_Armband","armband"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","W萛, AuB鄏訢hF");
        set("unit","");
                set("no_put",1);
                set("no_give",1);
                set("no_sell",1);
                set("no_auc",1);
                set("no_drop",1);
   set("no_get",1);
        set("material","crimsonsteel");
        set("armor_type","armbands");
        set("armor_prop/armor", 8);
        set("armor_pror/parry",10);
        set("armor_prop/force", 10);
        set("armor_prop/dodge", 10);
        }
        setup();
}

int init()
{
    add_action("do_wear","wear");
    add_action("do_remove","remove");
}
int do_wear(string str)
{
::wear();
 if( query("equipped") )
 {
   user = this_player();
  if(user->query_temp("god_armband",1))
  return notify_fail("AwgN" + HIB + "" + HIW + "" + HIB + "" + HIW + "" + HIB + "" + HIW + "u" + HIB + "" + HIW + "" + NOR + "佼あbuWFT\n");
   message_vision("$NN" + HIB + "" + HIW + "" + HIB + "" + HIW + "" + HIB + "" + HIW + "u" + HIB + "" + HIW + "" + NOR + "u@aC\n",user);
   user->add("force_factor",5);
   user->add_temp("god_armband",1);
   set_heart_beat(1);
 }
}

int do_remove(string str)
{
::wear();
 if( query("equipped") )
 {
   user = this_player();
   message_vision("$NN" + HIB + "" + HIW + "" + HIB + "" + HIW + "" + HIB + "" + HIW + "u" + HIB + "" + HIW + "" + NOR + "UC\n",user);
   user->set("force_factor",10);
   user->delete_temp("god_armband",1);
   set_heart_beat(1);
 }
}

