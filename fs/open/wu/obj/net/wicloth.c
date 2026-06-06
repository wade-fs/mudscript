#include <ansi.h>
#include <armor.h>
inherit CLOTH;
object user;
int kar;
void create()
{
   set_name("狂風戰盔",({"wind armor","armor"}));
   set_weight(20000);
   if( clonep() )
        set_default_object(__FILE__);
   else {
   set("no_sell",1);
   set("no_auc",1);
   set("no_drop",1);
   set("unit","件");
   set("value",150000);
   set("material", "cloth");
   set("long","這是一件由天上諸神使用風岩石所打造的神奇盔甲。\n");
   set("unequip_msg", "$N將$n脫掉，" + HIW + "狂風盔甲" + NOR + "的力量隨之逝去。\n");
   set("armor_prop/armor",22);
   set("armor_prop/stabber",10);
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
message_vision("$N將狂風戰盔穿上，" + HIW + "狂風盔甲" + NOR + "的力量貫注在$N身中。\n",user);
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
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
     dodge = enemy[i]->query_skill("dodge");
     if( random(180) > dodge)
     {
message_vision(HIW+"忽然間狂風急起此時,此時無數的旋風從狂風戰盔" + HIW + "中發出,瞬間將$N捲住無法動彈!!!\n"+NOR,enemy[i]);
      enemy[i]->start_busy(1);
     }else{
message_vision(HIW+"忽然間狂風急起此時,此時無數的旋風從狂風戰盔" + HIW + ",$N瞬間看出風的紋路,避了過去..\n"+NOR,enemy[i]);
  }
    }
  }
  return;
}
