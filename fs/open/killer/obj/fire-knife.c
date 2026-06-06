#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
inherit SSERVER;
object me=this_player();
void create()
{
        seteuid(getuid());
        set_name(HIR + "烈燄手裏劍" + NOR,({"fire knife","knife"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else 
       {
                set("unit", "把");
                set("long","全身火紅且不時冒出火焰的手裏劍。\n");
                set("value",10000);
                set("material", "blacksteel");
                set("no_sell",1);
                set("no_hands",1);
                set("weapon_prop/armor", 15);
                set("weapon_prop/attack", 30);
                set("weapon_prop/dodge",5);
                set("weapon_prop/parry",5);
                set("weapon_prop/dagger",20);
                set("weapon_prop/throwing",20);
       }
        init_dagger(100);
        set_heart_beat(1);
        setup();  

}

mixed hit_ob(object me)
{
  object user=this_player();
  object *enemy=user->query_enemy();
  object victim=enemy[random(sizeof(enemy))];
  int bb = me->query_skill("dodge");


  if( user->is_fighting() && query("equipped") )
  {
    if( random(100) > 70 && random(bb*3)  > victim->query_skill("dodge")+10)
    {
      message_vision(HIR + "$N順手一揮, 烈燄手裏劍的熱氣已在$n身上劃出一道熾熱的傷口!!!\n" + NOR,user,victim);
      victim->receive_wound("kee",250+me->query_skill("dagger"));
      victim->apply_condition("burn",random(3)+1);
      COMBAT_D->report_status(victim);
     }
  }
}

void heart_beat()
{
object *enemy;
int i;
if(!me) {
 set_heart_beat(0);
 return ;
}
enemy=me->query_enemy();
if(sizeof(enemy) == 0) return;
i=random(sizeof(enemy));
if( me->is_fighting() && query("equipped") )
  {
      if( random(me->query_skill("throwing")) > 155 )
     {
message_vision(HIR + "$N趁著空檔時機, 將" + HIR + "烈燄手裏劍" + HIR + "對準$n擲去,$n無法躲避, 被割出了幾道細長的血痕。\n" + NOR,me,enemy[i]);
enemy[i]->receive_wound("kee",200+me->query_skill("throwing")+me->query("functions/manakee/level"));
enemy[i]->apply_condition("burn",random(3)+1);
COMBAT_D->report_status(enemy[i]);
     }        
     }
  }
 
