#include <weapon.h>
#include <ansi.h>

inherit BLADE;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
	set_name(GRN"幔羅刀無影"NOR,({"maun-shadow-blade","blade"}) );
	set_weight(10000);
	if( clonep() ) 
	set_default_object(__FILE__);
	else {
	set("long","香靈吟所使用的武器，為一神秘鑄將精心鑄造的「八色靈器」之一，刀身\n精緻小巧，卻具有強大殺傷力。\n");
	set("unit", "把");             
	set("value",20000);
	set("sharp",9);
	set("material","blacksteel");
	set("e-weapon",1);
	set("no_give",1);
	set("no_steal",1);
	}
	init_blade(100);
 	set("wield_msg",CYN"$N"CYN"拿起$n"CYN"，$n"CYN"散出一股奇異的淡淡幽香!!\n"NOR);
        set("unwield_msg","$N輕輕卸下$n，$n散出的香味也消逝無蹤。\n"NOR);

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
	if(str=="maun-shadow-blade" || str=="blade" || str=="all")
	if( !query("equipped") )
	{
	user = this_player();
	uexp = user->query("combat_exp");
	  if( uexp < 3000000 )
	  {
	  message_vision("$N的經驗並不足以完全支配這樣的神兵利器!!\n"NOR,user);
	  set_heart_beat(0);
	  }else{
//	  message_vision(CYN"$N"CYN"拿起$n"CYN"，$n"CYN"散出一股奇異的淡淡幽香!!\n"NOR,user,ob);
	  set_heart_beat(1);
	  }
	}
}

int do_drop(string str)
{
	if(str=="maun-shadow-blade" || str=="blade" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕卸下$n，$n散出的香味也消逝無蹤。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="maun-shadow-blade" || str=="blade" || str=="all")
	if( query("equipped") )
	{
//	message_vision("$N輕輕卸下$n，$n散出的香味也消逝無蹤。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="maun-shadow-blade" || str=="blade" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕卸下$n，$n散出的香味也消逝無蹤。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}
void heart_beat()
{
	object *enemy;
	int i,be;

	if( !objectp(user) )
	{
	set_heart_beat(0);
	return;
	}

	if( !user->query_skill("blade") )
	{
	be = random(120);
	}else{
	be = user->query_skill("blade");
	}

	if( be > 150) be=150;

	k = user->query_int();
	sp = user->query_spi();
	co = user->query_cor();
	st = user->query_str();
	qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);
	if( user->query("class") == "blademan" )
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
	  message_vision(HIB"清淡的幽香隨風由"NOR"$n"HIB"裏飄散出來，$N"HIB"只覺血氣被香味散去不少!!\n"NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(BLU"$N"BLU"識破了香味的玄機，閉氣凝神的全心應戰!!\n"NOR,enemy[i],ob);
	  }
	}
	return;
}

