// bleed_whip.c
#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name(HIR "血龍鞭" NOR,({"bleed whip","whip"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","條");
                set("value",30000);
		set("material","iron");
       set("no_poison",1);
		set("rigidity",50);
		set("no_hands",1);
                set("weapon_prop/attack",30);
                set("weapon_prop/dodge",5);
                set("weapon_prop/parry",5);
                set("weapon_prop/whip",10);
		set("long",
	"這條鞭子上面充滿血色﹐握柄上有一隻龍頭。\n");
	}
	init_whip(80);
	setup();
}
mixed hit_ob(object me)
{
object user=this_player();
object *enemy=user->query_enemy();
object victim=enemy[random(sizeof(enemy))];
int be = user->query("bellicosity");
int po = user->query("poison");
if(po > 500) po=500;         
if (this_player()->query("class") != "poisoner")  return 0;
if( user->is_fighting() && query("equipped") )
  {
     if( random(be) > 1000 && random(100) > 70 && user->query("marks/evil-poison")==1) // 發動機率本身包含命中機率 所以有發動就會命中
     {
      message_vision(HIR"$N手中血龍鞭在$n身上帶出一條血痕, $n只覺傷口發麻, 似乎鞭上有毒!!!\n"NOR,user,victim);
      victim->receive_wound("kee",po);
      victim->apply_condition("fire_poison",random(3)+1);
      if(victim->query_temp("poison/fire_poison"))
        victim->set_temp("poison/fire_poison",victim->query_temp("poison/fire_poison") - ({ me }) - ({ 0 }) + ({ me }) );
      else
        victim->set_temp("poison/fire_poison",({ me }));

      COMBAT_D->report_status(victim);
     }
  }
  return;
}
