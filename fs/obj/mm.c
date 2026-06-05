// /u/a/acelan/eqs/m_weapon.c UΪZ written by AceLan.............97.11.10
// Modify By AceLan 98.7.13 UΧ󦳬Y...ccc....
// Modify By AceLan 98/11/1 W[}

#include <ansi.h>
#include <weapon.h>

// }ӽF so  inherit
inherit "/std/weapon/m_bow.c";

void create()
{
   object me= this_player();
   string c_unit, wield_part, weapon_type= me->query("weapon/e_type"); // new

   set_name( me->query("weapon/name"),({"special "+me->query("weapon/e_type"), me->query("weapon/e_type"), "m_weapon"}) );
   set_weight(1000);
   if( clonep() )
      set_default_object(__FILE__);
   // UsW...
   if( weapon_type == "whip")
   {
      c_unit= "`";
      wield_part= "⤤";
   }
   else if( weapon_type == "pen")
   {
      c_unit= "";
      wield_part= "⤤";
   }
   else if( weapon_type == "ring")
   {
      c_unit= "u";
      wield_part= "W";
   }
   else if( weapon_type == "armband")
   {
      c_unit= "";
      wield_part= "uW";
   }
   else                                      // ѤU C M P ع 
   {
      c_unit= "";
      wield_part= "⤤";
   }

   set("long","o"+c_unit+me->query("weapon/c_type")+"OH[1;37m"+ me->query("weapon/source1")+"[0mtX[1;37m"+ me->query("weapon/source2")+"[0mű, {{۲C");
   set("unit", "");
   set("value",0);                           // L_...ccc....
   set("material","steal");

   // [jF˳ƪZΨUZT...
   //     u
   if( me->query("weapon/type") == "stabber" || me->query("weapon/type") == "unarmed")
   {
      set("wield_msg", HIW + "u$Njܤ@n, @Dեt$Nh«X, \nbŤL٤Tᰱb$N"+wield_part+"Ʀ@"+c_unit+"WS"+ me->query("weapon/name")+"C\n" + NOR);
      set("unwield_msg", HIW + "M$NݸlF, "+wield_part+"$n@j, \nu$nCCƧ@@\\\\, Sb$NݸC\n" + NOR);
   }
   else // if( c_unit == "" || c_unit == "`")//  C M P ع...l|X{
   {
      set("wield_msg", HIW + "$NN"+ me->query("weapon/name")+"ѭIX, u@DģӸ޲~`JF$NWC\n" + NOR);
      set("unwield_msg", HIW + "$NN⤤$nH⩹ѤW@, u^FIC\n" + NOR);
   }

   set("no_drop", 1);
   set("no_give", 1);
   set("no_get", 1);
   set("no_auc", 1);

   init_bow( me->query("weapon/value"));
   set("skill_type", me->query("weapon/type"));
   setup();
}

int query_autoload()
{
   return 1;
}

void init()
{
// ZO} NN add_action disable 
   if( this_player()->query("weapon/type") == "archery");
   {
      add_action("do_holdwith", "holdwith");
      add_action("do_unhold", "unhold");
      add_action("do_checkbow", "checkbow");
   }
}

