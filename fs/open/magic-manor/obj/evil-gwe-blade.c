#include <weapon.h>
#include <ansi.h>

inherit BLADE;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
	set_name(HIB + "刀斬邪元歸" + NOR,({"evil-gwe-blade","blade"}) );
	set_weight(10000);
	if( clonep() ) 
	set_default_object(__FILE__);
	else {
	set("long","封圓真所使用的武器，為一神秘鑄將精心鑄造的「八色靈器」之一，刀身\n隱隱綻放著一點點的邪光。\n");
	set("unit", "把");             
	set("value",20000);
	set("sharp",9);
	set("material","blacksteel");
	set("e-weapon",1);
	set("no_give",1);
	set("no_steal",1);
	}
	init_blade(100);
 	set("wield_msg",CYN + "$N" + CYN + "拿起$n" + CYN + "，$n" + CYN + "散出一股邪惡的氣息!!\n" + NOR);
        set("unwield_msg","$N輕輕卸下$n，$n散出的邪惡氣息也消逝無蹤。\n" + NOR);

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
//	  message_vision(CYN + "$N" + CYN + "拿起$n" + CYN + "，$n" + CYN + "散出一股邪惡的氣息!!\n" + NOR,user,ob);
	  set_heart_beat(1);
	  }
	}
}

int do_drop(string str)
{
	if(str=="evil-gwe-blade" || str=="blade" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕卸下$n，$n散出的邪惡氣息也消逝無蹤。\n" + NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="evil-gwe-blade" || str=="blade" || str=="all")
	if( query("equipped") )
	{
//	message_vision("$N輕輕卸下$n，$n散出的邪惡氣息也消逝無蹤。\n" + NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="evil-gwe-blade" || str=="blade" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N輕輕卸下$n，$n散出的邪惡氣息也消逝無蹤。\n" + NOR,user,ob);
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
	  message_vision(HIC + "邪惡的氣息由" + NOR + "$n" + HIC + "裏急衝出來，$N" + HIC + "被這股氣息吸去不少血氣!!\n" + NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(BLU + "$N" + BLU + "左躲右閃之下，終於避開了這股邪氣!!\n" + NOR,enemy[i],ob);
	  }
	}
	return;
}

