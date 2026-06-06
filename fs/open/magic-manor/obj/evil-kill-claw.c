#include <weapon.h>
#include <ansi.h>

inherit UNARMED;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
	set_name(BLU + "魔爪混天殺" + NOR,({"evil-kill-claw","claw"}) );
	set_weight(10000);
	if( clonep() ) 
	set_default_object(__FILE__);
	else {
	set("long","莫道子所使用的武器，為一神秘鑄將精心鑄造的「八色靈器」之一，爪身\n散出極強的殺氣。\n");
	set("unit", "把");             
	set("value",20000);
	set("sharp",9);
	set("material","blacksteel");
	set("e-weapon",1);
	set("no_give",1);
	set("no_steal",1);
	}
	init_unarmed(100);
 	set("wield_msg",GRN + "$N" + GRN + "載上$n" + GRN + "，$n" + GRN + "周身散出濃烈的殺氣，似要吐噬一切事物!!\n" + NOR);
        set("unwield_msg","$N輕輕卸下$n，$n散出的殺氣也漸漸緩和下來。\n" + NOR);

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
	if( !query("equipped") )
	{
	user = this_player();
	uexp = user->query("combat_exp");
	  if( uexp < 3000000 )
	  {
	  message_vision("$N的經驗並不足以完全支配這樣的神兵利器!!\n" + NOR,user);
	  set_heart_beat(0);
	  }else{
//	  message_vision(GRN + "$N" + GRN + "載上$n" + GRN + "，$n" + GRN + "周身散出濃烈的殺氣，似要吐噬一切事物!!\n" + NOR,user,ob);
	  set_heart_beat(1);
	  }
	}
}

int do_drop(string str)
{
	if(str=="evil-kill-claw" || str=="claw" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕卸下$n，$n散出的殺氣也漸漸緩和下來。\n" + NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="evil-kill-claw" || str=="claw" || str=="all")
	if( query("equipped") )
	{
//	message_vision("$N輕輕卸下$n，$n散出的殺氣也漸漸緩和下來。\n" + NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="evil-kill-claw" || str=="claw" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕卸下$n，$n散出的殺氣也漸漸緩和下來。\n" + NOR,user,ob);
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

	if( !user->query_skill("unarmed") )
	{
	be = random(120);
	}else{
	be = user->query_skill("unarmed");
	}

	if( be > 150) be=150;

	k = user->query_int(1);
	sp = user->query_spi(1);
	co = user->query_cor(1);
	st = user->query_str(1);
	qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);
	if( user->query("class") == "bandit" )
	{
	qq = qq*1.25;
	be = be*1.25;
	}

	if( user->is_fighting() && query("equipped") )
	{
	  if( be > random(500) )
	  {
	  enemy=user->query_enemy();
  	  if(!sizeof(enemy)) return ;
	  i=random(sizeof(enemy));
	  if( environment(user) == environment(enemy[i]) )
	  if( random(300) > random(enemy[i]->query_skill("dodge",1)) )
	  {
	  message_vision(HIB + "只見" + NOR + "$n" + HIB + "周身散發出的殺氣忽然聚成一道氣勁，直衝$N" + HIB + "心坎要害!!\n" + NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(BLU + "$N" + BLU + "見狀，不慌不忙的避開了這道極具威力的殺氣!!\n" + NOR,enemy[i],ob);
	  }
	}
	return;
}

