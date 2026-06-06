#include <ansi.h>
#include <armor.h>
inherit EQUIP;
object user;
int kar;
void create()
{
set_name("紫芸仙鍊",({"purple neck","neck"}));
   set_weight(5000);
   if ( clonep() )
       set_default_object(__FILE__);
   else {
   set("long","這是一件由天上諸神採集先天靈氣所煉造而成的仙鍊。\n");
   set("unequip_msg", "$N將$n脫掉,$N身上的$n所散發的靈氣隨之逝去。\n");
   set("armor_prop/armor",7);
   set("armor_prop/dodge",3);
   set("unit", "條");
   set("armor_type", "neck");
   set("value", 30000);
   set("no_sell",1);
   set("no_auc",1);
   set("no_drop",1);
     }
   setup();
}
int query_autoload()
{
 return 1;
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
message_vision("$N將紫芸仙鍊穿上，紫芸仙鍊的仙氣貫注在$N身中。\n",user);
   kar=user->query_kar();
   set_heart_beat(1);
 }
}
void heart_beat()
{
  object *enemy,who;
  int i,dodge;
  if( !objectp(user) )
  { set_heart_beat(0);
     return;
  }
  if( user->is_fighting() && query("equipped") )
  {
    if( random(kar+70) > 70)  // 運氣高,機率高
    {
     user->receive_curing("kee",30);
     user->receive_heal("kee",30);
message_vision(HIY"紫芸仙鍊"HIY"散出淡淡的仙氣,$N在仙氣沐浴下,$N所受的創傷恢復了.\n"NOR,user);
      }
  }
  return;
}
