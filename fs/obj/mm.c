// /u/a/acelan/eqs/m_weapon.c ¸U¥ÎªZ¾¹ written by AceLan.............97.11.10
// Modify By AceLan 98.7.13 Åý¸U¥Î§ó¦³¬ÝÀY...ccc....
// Modify By AceLan 98/11/1 ¼W¥[¤}ªº³¡¤À

#include <ansi.h>
#include <weapon.h>

// ¤}¤Ó½ÆÂø¤F so ª½±µ inherit
inherit "/std/weapon/m_bow.c";

void create()
{
   object me= this_player();
   string c_unit, wield_part, weapon_type= me->query("weapon/e_type"); // new

   set_name( me->query("weapon/name"),({"special "+me->query("weapon/e_type"), me->query("weapon/e_type"), "m_weapon"}) );
   set_weight(1000);
   if( clonep() )
      set_default_object(__FILE__);
   // ¤U¬°·s¼W³¡¥÷...
   if( weapon_type == "whip")
   {
      c_unit= "¬`";
      wield_part= "¤â¤¤";
   }
   else if( weapon_type == "pen")
   {
      c_unit= "°¦";
      wield_part= "¤â¤¤";
   }
   else if( weapon_type == "ring")
   {
      c_unit= "¥u";
      wield_part= "«ü¤W";
   }
   else if( weapon_type == "armband")
   {
      c_unit= "­Ó";
      wield_part= "Áu¤W";
   }
   else                                      // ³Ñ¤Uªº¬° ¼C ¤M ¤P­º ©Ø¹Ð ®°
   {
      c_unit= "§â";
      wield_part= "¤â¤¤";
   }

   set("long","³o"+c_unit+me->query("weapon/c_type")+"¬O¥H[1;37m"+ me->query("weapon/source1")+"[0m°t¦X[1;37m"+ me->query("weapon/source2")+"[0m©ÒÅ±¦¨ªº, ¥¦¥¿°{Ã{µÛ²§¥ú¡C");
   set("unit", "§â");
   set("value",0);                           // µL»ù¤§Ä_...ccc....
   set("material","steal");

   // ¥[±j¤F¸Ë³ÆªZ¾¹¤Î¨ø¤UªZ¾¹ªº°T®§...
   // «ü ®° µ§ «üÀô ÁuÀô
   if( me->query("weapon/type") == "stabber" || me->query("weapon/type") == "unarmed")
   {
      set("wield_msg", HIW"¥u¨£$N¤j³Ü¤@Án, ¤@¹D¥Õ¥ú¨³³t¥Ñ$NÃh¤¤Â«¥X, \n¦bªÅ¤¤½L®Ù¤T°é«á°±¦b$Nªº"+wield_part+"¤Æ¦¨¤@"+c_unit+"¿W¯Sªº"+ me->query("weapon/name")+"¡C\n"NOR);
      set("unwield_msg", HIW"¬ðµM¶¡$Nªº¯Ý¸¡¤§¶¡§l¨¬¤F®ð, ´Â"+wield_part+"ªº$n»´»´¤@§j, \n¥u¨£$nºCºCªº¤Æ§@¤@\Á\\»´\·Ï, Áô¨S¦b$Nªº¯Ý¸¡¤§¶¡¡C\n"NOR);
   }
   else // if( c_unit == "§â" || c_unit == "¬`")// «ü ¼C ¤M ¤P­º ©Ø¹Ð...®°¤l¤£·|¥X²{
   {
      set("wield_msg", HIW"$N»´»´ªº±N"+ me->query("weapon/name")+"¥Ñ­I«á©â¥X, ¥u¨£¤@¹DÄ£²´¦Ó¸Þ²§ªº¥ú¨~ª`¤J¤F$N¨­¤W¡C\n"NOR);
      set("unwield_msg", HIW"$N±N¤â¤¤ªº$nÀH¤â©¹¤Ñ¤W¤@¥á, ¥u¨£¥¦¥©§®ªº¸¨¦^¤F­I«á¡C\n"NOR);
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
ÿ
void init()
{
// ªZ¾¹¤£¬O¤}ªº¸Ü ´N±N add_action disable ±¼
   if( this_player()->query("weapon/type") == "archery");
   {
      add_action("do_holdwith", "holdwith");
      add_action("do_unhold", "unhold");
      add_action("do_checkbow", "checkbow");
   }
}
ÿ
