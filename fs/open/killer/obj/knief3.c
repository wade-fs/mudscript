#include <weapon.h>
#include <ansi.h>
inherit THROWING;
object me;
void create()
{
     set_name("鐵菱子",({"iron"}));
     set_weight(15);
     if( clonep() )
         set_default_object(__FILE__);
     else {
       set("unit","個");
       set("base_unit","個");
       set("long","利用腕力將沈重的鐵擊出，針對敵人的要害加以傷害。\n");
       set("value",1);
       set("no_sell",1);
       set("material", "steel");
       set("wield_msg","$N拿起$n,感覺起來很不錯。\n");
       set("unwield_msg", "$N將$n放了下來\n");
     }
      init_throwing(40);
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
   message_vision(HIY"$N被$n的鐵菱子砸中穴道，身形為之一滯\n"NOR,me,enemy[i]);
   enemy[i]->start_busy(1);
  } 
 }
}

int wield()
{
 if(this_player()->query_skill_mapped("throwing") != "rain-throwing")
    return notify_fail("這是殺手專用的東西\n");
 if(this_player()->query_skill("throwing") < 40 )
     return notify_fail("小朋友，暗器手法練好一點，再用吧！\n");
 else 
 {
::wield();
  }
  return 1;
}
