#include <weapon.h>
#include <ansi.h>
inherit THROWING;
object me;
void create()
{
     set_name("柳葉飛刀",({"ya knief","knief"}));
     set_weight(7);
     if( clonep() )
         set_default_object(__FILE__);
     else {
       set("unit","支");
       set("base_unit","支");
       set("long","將笨重的飛刀改良，使得刀片變薄，攻擊力更高\n");
       set("value",1);
       set("no_sell",1);
       set("material", "silver");
       set("wield_msg","$N拿起$n,感覺起來很不錯。\n");
       set("unwield_msg", "$N將$n放了下來\n");
     }
      init_throwing(30);
      set_amount(1);
      setup();
}

mixed hit_ob( object me,object victim)
{
 int i,a,b,cor;
 object *enemy;

 cor=me->query_skill("throwing",1);
 if(me->is_fighting()&&query("equipped"))
 {
  if(random(me->query_skill("dodge",1)) > 60)
  {
   enemy=me->query_enemy();
   i=random(sizeof(enemy));
   message_vision(HIG + "$N被$n的柳葉飛刀刺中要害，傷口流出大量鮮血\n" + NOR,me,enemy[i]);
   COMBAT_D->report_status(enemy[i],1);
   enemy[i]->add("kee",-random(cor/2));
  } 
 }
}

int wield()
{
 if(this_player()->query_skill_mapped("throwing") != "rain-throwing")
    return notify_fail("這是殺手專用的東西\n");
 if(this_player()->query_skill("throwing") < 30 )
     return notify_fail("小朋友，暗器手法練好一點，再用吧！\n");
 else 
 {
::wield();
  }
  return 1;
}
