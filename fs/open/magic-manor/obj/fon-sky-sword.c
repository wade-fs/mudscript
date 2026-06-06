#include <weapon.h>
#include <ansi.h>

inherit SWORD;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
	set_name("楓映天蓮劍",({"fon-sky-sword","sword"}) );
	set_weight(10000);
	if( clonep() ) 
	set_default_object(__FILE__);
	else {
	set("long","凌方真所使用的武器，為一神秘鑄將精心鑄造的「八色靈器」之一，劍身\n黝黑，隱隱透出黑色的氣勁。\n");
	set("unit", "把");             
	set("value",20000);
	set("sharp",9);
	set("material","blacksteel");
	set("e-weapon",1);
	set("no_give",1);
	set("no_steal",1);
	}
	init_sword(100);
	set("wield_msg",CYN + "$N" + CYN + "拿起$n" + CYN + "，$n" + CYN + "黝黑的劍身綻放絲絲的寒光!!\n" + NOR);
        set("unwield_msg","$N輕輕收下$n，$n絲絲的寒光化為黝黑的劍身。\n" + NOR);

	setup();
}                   


void init()
{
	add_action("do_drop","drop");
	add_action("do_auc","auc");
	add_action("do_wield","wield");
	add_action("do_unwield","unwield");
}
int do_wield(string str)
{
	int uexp;
//	::wield();
	if(str=="fon-sky-sword" || str=="sword" || str=="all")
	if( !query("equipped") )
	{
	user = this_player();
	uexp = user->query("combat_exp");
	  if( uexp < 3000000 )
	  {
	  message_vision("$N的經驗並不足以完全支配這樣的神兵利器!!\n" + NOR,user);
	  set_heart_beat(0);
	  return 0;
	  }else{
//	  message_vision(CYN + "$N" + CYN + "拿起$n" + CYN + "，$n" + CYN + "黝黑的劍身綻放絲絲的寒光!!\n" + NOR,user,ob);
	  set_heart_beat(1);
	  }
	}
}

int do_drop(string str)
{
	if(str=="fon-sky-sword" || str=="sword" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕收下$n，$n絲絲的寒光化為黝黑的劍身。\n" + NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="fon-sky-sword" || str=="sword" || str=="all")
	if( query("equipped") )
	{
//	message_vision("$N輕輕收下$n，$n絲絲的寒光化為黝黑的劍身。\n" + NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="fon-sky-sword" || str=="sword" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕收下$n，$n絲絲的寒光化為黝黑的劍身。\n" + NOR,user,ob);
	set_heart_beat(0);
	}
}
void heart_beat()
{
	object *enemy;
	int i;

	if( !objectp(user) )
	{
	set_heart_beat(0);
	return;
	}

	if( !user->query_skill("sword") )
	{
	be = random(120);
	}else{
	be = user->query_skill("sword");
	}

	if( be > 150) be=150;

	k = user->query_int(1);
	sp = user->query_spi(1);
	co = user->query_cor(1);
	st = user->query_str(1);
	qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);
	if( user->query("class") == "swordsman" )
	{
	qq = qq*1.25;
	be = be*1.25;
	}

	if( user->is_fighting() && query("equipped") )
	{
	  if( be > random(500) )
	  {
	  enemy=user->query_enemy();
	  if(!enemy) return ;
	  i=random(sizeof(enemy));
	  if( environment(user) == environment(enemy[i]) )
	  if( random(300) > random(enemy[i]->query_skill("dodge",1)) )
	  {
	  message_vision(HIB + "絲絲的寒光由" + NOR + "$n" + HIB + "中透射出來，不偏不倚的打在$N" + HIB + "身上!!\n" + NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(BLU + "$N" + BLU + "輕功\甚是了得，在慌忙之中閃了過去!!\n" + NOR,enemy[i],ob);
	  }
	}
	return;
}

