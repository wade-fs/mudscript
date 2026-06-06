#include <weapon.h>
#include <ansi.h>
inherit UNARMED;
object user=this_player();
object ob=this_object();
int be,bb,k,sp,qq,co,st;

void create()
{
 	        set_name(HIM"花舞飄香"NOR, ({ "flower claw" ,"claw" }) );
	        set_weight(1500);
       		if( clonep() )
                set_default_object(__FILE__);
        	else {
        	set("long", "千年花精–淡情悠法力所幻化，帶有些微的法力和強大的殺傷力。\n");
                set("unit", "把");
                set("value", 300000);
                set("material", "blacksteel");
		set("sharp",9);
		set("type", 1);
		set("no_steal",1);
		set("no_give",1);
       		}
		init_unarmed(150);
 		set("wield_msg",HIM"$N"HIM"運起內力，緩緩將內力灌入$n"HIM"，由$n"HIM"之中散出淡淡花香!!\n"NOR);
		set("unwield_msg",HIM"$N"HIM"緩緩收回內力，$n"HIM"也漸漸變回一般不起眼的武器。\n"NOR);
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
	if(str=="flower claw" || str=="claw" || str=="all")
	if( !query("equipped") )
	{
        user = this_player();
        set_heart_beat(1);
	}
}

int do_drop(string str)
{
	if(str=="flower claw" || str=="claw" || str=="all")
	if( query("equipped") )
	{
	message_vision(HIM"$N"HIM"緩緩收回內力，$n"HIM"也漸漸變回一般不起眼的武器。\n"NOR,user,ob);
        set_heart_beat(0);
	}
}

int do_unwield(string str)
{
	if(str=="flower claw" || str=="claw" || str=="all")
	if( query("equipped") )
	{
        set_heart_beat(0);
	}
}

int do_auc(string str)
{
	if(str=="flower claw" || str=="claw" || str=="all")
	if( query("equipped") )
	{
	message_vision(HIM"$N"HIM"緩緩收回內力，$n"HIM"也漸漸變回一般不起眼的武器。\n"NOR,user,ob);
        set_heart_beat(0);
	}
}
void heart_beat()
{
	object *enemy;
	int i;

	if ( !objectp(user) )
        {
        set_heart_beat(0);
        return;
        }

	if( !user->query_skill("unarmed") )
	{
	be = random(120);
	}else{
	be = user->query_skill("unarmed",1);
	}

	k = user->query_int(1);
	sp = user->query_spi(1);
	co = user->query_cor(1);
	st = user->query_str(1);
	qq = (int)((k+sp+co+st)*(k+sp+co+st) / 60);

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
	  message_vision(HIM"一片花辦由$n"HIM"輕舞飛出，轉化為無形的悠香吸取了$N"HIM"的些許\精力!!\n"NOR,enemy[i],ob);
	  enemy[i]->receive_wound("kee",(int)(qq+be),user);
	  COMBAT_D->report_status(enemy[i], 0);
	  }else
	  message_vision(HIW"一片花辦由$n"HIW"輕舞飛出，但被$N"HIW"識破而閃過!!\n"NOR,enemy[i],ob);
	  }
	}
	return;
}

