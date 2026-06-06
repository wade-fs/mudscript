#include <weapon.h>
#include <ansi.h>

inherit DAGGER;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
	set_name(RED"閻匕影螫魂"NOR,({"dark-soul-dagger","dagger"}) );
	set_weight(10000);
	if( clonep() ) 
	set_default_object(__FILE__);
	else {
	set("long","柔媚生所使用的武器，為一神秘鑄將精心鑄造的「八色靈器」之一，匕身\n散出陣陣白霧，煞是好看。\n");
	set("unit", "把");             
	set("value",20000);
	set("sharp",9);
	set("material","blacksteel");
	set("e-weapon",1);
	set("no_give",1);
	set("no_steal",1);
	}
	init_dagger(100);
  	set("wield_msg",RED"$N"RED"拿出$n"RED"，$n"RED"周身泛起一陣白色的光霧!!\n"NOR);
        set("unwield_msg","$N收藏好$n，$n周身的光霧隨即消散。\n"NOR);


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
//	  message_vision(RED"$N"RED"拿出$n"RED"，$n"RED"周身泛起一陣白色的光霧!!\n"NOR,user,ob);
	  set_heart_beat(1);
	  }
	}
}

int do_drop(string str)
{
	if(str=="dark-soul-dagger" || str=="dagger" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N收藏好$n，$n周身的光霧隨即消散。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="dark-soul-dagger" || str=="dagger" || str=="all")
	if( query("equipped") )
	{
//	message_vision("$N收藏好$n，$n周身的光霧隨即消散。\n"NOR,user,ob);
	set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="dark-soul-dagger" || str=="dagger" || str=="all")
	if( query("equipped") )
	{
	message_vision("$N收藏好$n，$n周身的光霧隨即消散。\n"NOR,user,ob);
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

	if( !user->query_skill("dagger") )
	{
	be = random(120);
	}else{
	be = user->query_skill("dagger");
	}

	if( be > 150) be=150;

	k = user->query_int(1);
	sp = user->query_spi(1);
	co = user->query_cor(1);
	st = user->query_str(1);
	qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);
	if( user->query("class") == "killer" )
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
    if(!enemy[i]) return ;
	  if( environment(user) == environment(enemy[i]) )
	  if( random(300) > random(enemy[i]->query_skill("dodge",1)) )
	  {
	  message_vision(HIB"只見"NOR"$n"HIB"的匕刃鋒緣衝出一道白影直衝$N"HIB"致命要穴!!\n"NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(BLU"$N"BLU"見狀，從容得體的避開這道白影!!\n"NOR,enemy[i],ob);
	  }
	}
	return;
}

