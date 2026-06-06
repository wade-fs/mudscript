#include <weapon.h>
#include <ansi.h>

inherit UNARMED;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
     set_name(CYN"化劫菱歸真"NOR,({"hwa-je-icer","icer"}) );
     set_weight(10000);
     if( clonep() ) 
            set_default_object(__FILE__);
     else {
            set("long","寂元子所使用的武器，為一神秘鑄將精心鑄造的「八色靈器」之一，菱身\n隱隱透出黑白兩股氣勁。\n");
            set("unit", "把");             
            set("value",20000);
            set("sharp",9);
            set("material","blacksteel");
			set("e-weapon",1);
			set("no_give",1);
 			set("no_steal",1);
            }
	init_unarmed(100);
 	set("wield_msg",CYN"$N"CYN"載上$n"CYN"，$n"CYN"周身泛起黑白兩色的詭異氣息!!\n"NOR);
        set("unwield_msg","$N輕輕卸下$n，$n周身的詭異氣息也消失殆盡。\n"NOR);

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
	  message_vision("$N的經驗並不足以完全支配這樣的神兵利器!!\n"NOR,user);
	  set_heart_beat(0);
	  }else{
//	  message_vision(CYN"$N"CYN"載上$n"CYN"，$n"CYN"周身泛起黑白兩色的詭異氣息!!\n"NOR,user,ob);
	  set_heart_beat(1);
	  }
	}
}

int do_drop(string str)
{
	if(str=="hwa-je-icer" || str=="icer" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕卸下$n，$n周身的詭異氣息也消失殆盡。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="hwa-je-icer" || str=="icer" || str=="all")
	if( query("equipped") )
	{
//	message_vision("$N輕輕卸下$n，$n周身的詭異氣息也消失殆盡。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="hwa-je-icer" || str=="icer" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕卸下$n，$n周身的詭異氣息也消失殆盡。\n"NOR,user,ob);
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

	if( user->query_skill("unarmed") )
	{
	be = user->query_skill("unarmed",1);
	}else{
	be = random(120);
	}

	k = user->query_int(1);
	sp = user->query_spi(1);
	co = user->query_cor(1);
	st = user->query_str(1);
	qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);
	if( user->query("class") == "prayer" )
	{
	qq = qq*1.5;
	be = be*0.75;
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
	  message_vision(HIB"只見【"NOR"黑"HIW"白"NOR+HIB"】兩道氣勁迅速由"NOR"$n"HIB"竄出，飛向$N"HIB"的周身要害!!\n"NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(BLU"只見$N"BLU"，左躲右閃的免強避開這兩道黑白氣勁!!\n"NOR,enemy[i],ob);
	  }
	}
	return;
}

