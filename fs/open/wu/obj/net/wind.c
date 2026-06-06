#include <weapon.h>
#include <ansi.h>
inherit STABBER;
object user=this_player();
int be,bb,k,sp,qq;
void create()
{
        seteuid(getuid());
        set_name("狂風",({"wind"}));
        set_weight(7500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        set("unit", "把");
        set("long","這是一件由天上諸神採集風岩石所鍛造而成的武器。\n");
        set("value",20000);
        set("material", "steel");
        }
        init_stabber(80);
        setup();
}
int query_autoload()
{
 return 1;
}
void init()
{
     add_action("do_wield","wield");
     add_action("do_give","give");
     add_action("do_unwield","unwield");
}
int do_wield(string str)
{
     ::wield();
     if( query("equipped") )
     {
        user = this_player();
message_vision(HIW"$N將狂風"HIW"載上,全身湧出風的氣息,$N感覺力量如風湧出\n"NOR,user);
        set_heart_beat(1);
     }
}
/*
int do_drop(string str)
{
   if(str=="wind" || str=="all")
     if( query("equipped") )
     {
message_vision(HIW"$N將狂風"HIW"取下,風的力量從身體中散出!!!\n"NOR,user);
        set_heart_beat(0);
     }
}
*/
 int do_give(string str)
{
  if(str=="wind" || str=="all")
     if( query("equipped") )
     {
message_vision(HIW"$N將狂風"HIW"取下,風的力量從身體中散出!!!\n"NOR,user);
        set_heart_beat(0);
     }
}
int do_unwield(string str)
{
   if(str=="wind" || str=="all")
     if( query("equipped") )
     {
message_vision(HIW"$N將狂風"HIW"取下,風的力量從身體中散出!!!\n"NOR,user);
        set_heart_beat(0);
     }
}
void heart_beat()
{
  object *enemy;
  int i;
be = user->query("bellicosity",1);
  bb = (be/15);
  k = user->query_int(1);
  sp = user->query_spi(1);
  qq = (k+sp)^2 / 30;
  if ( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }
 if( user->is_fighting() && query("equipped") )
  {
    if( be > random(-1) )
    {
     enemy=user->query_enemy();
     i=random(sizeof(enemy));
     if( environment(user) == environment(enemy[i]) )
      if( random(300) > enemy[i]->query_skill("dodge") )
     {
message_vision(HIW"無數的氣旋從狂風"HIW"發出,刁鑽的氣旋侵入$N的全身氣脈\n"NOR,enemy[i]);
       enemy[i]->receive_damage("kee",qq+bb,user);
      COMBAT_D->report_status(enemy[i], 0);
     }else
message_vision(HIW"無數的氣旋從狂風"HIW"發出,$N瞬時看出氣旋的路徑,展開步法躲過攻擊\n"NOR,enemy[i]);
     }
  }
  return;
}
