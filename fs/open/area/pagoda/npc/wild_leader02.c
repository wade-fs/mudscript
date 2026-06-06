inherit NPC;
#include <ansi.h>
#include <move_log.c>;

void create()
{
	set_name("呂布",({"iv bu","bu","iv"}));
	set("gender","男性");
	set("title",HIY"野人領袖"NOR);
	set("age",32);
	set("attitude","aggressive");
	set("combat_exp",3500000);
	set("max_gin",30000);
	set("eff_gin",30000);
	set("gin",30000);
	set("max_kee",70000);
	set("eff_kee",70000);
	set("kee",70000);
	set("max_sen",30000);
	set("eff_sen",30000);
	set("sen",30000);
	set("max_force",1000000);
	set("force",1000000);
	set("str",50);
	set("cor",50);
	set("int",1);
	set("spi",1);
	set("cps",50);
	set("per",30);
	set("con",50);
	set("kar",30);
	set("force_factor",30);
	set_skill("force",150);
	set_skill("parry",150);
	set_skill("move",150);
	set_skill("dodge",150);
	set_skill("fireforce",150);
	set_skill("mogi-steps",150);
	set_skill("firestrike",150);
	map_skill("unarmed","firestrike");
	map_skill("parry","firestrike");
	map_skill("dodge","mogi-steps");
	map_skill("move","mogi-steps");
	map_skill("force","foreforce");
        set("functions/gold-fire/level",100);
        set("quest/gold-fire",1);
        set("quest/new_gold_fire",1);
	set_temp("no_die_soon",1);
	set_temp("apply/armor",200);
	set_temp("apply/defense",200);
	set_temp("apply/damage",200);
	set_temp("apply/attack",300);
	setup();
}

void heart_beat()
{
object ob;
mixed enemy;
int i,n,d,s;
	enemy = all_inventory(environment(this_object()));
	n = sizeof(enemy);
	ob = this_object();
//  回復能力
	if ( random(100) < 25 ) {
	if ( ob->query_busy() ) ob->delete_busy();
	if ( ob->query("gin") < ob->query("max_gin") ) { ob->receive_curing("gin",200); ob->receive_heal("gin",1000); };
	if ( ob->query("kee") < ob->query("max_kee") ) { ob->receive_curing("kee",200); ob->receive_heal("kee",1000); };
	if ( ob->query("sen") < ob->query("max_sen") ) { ob->receive_curing("sen",200); ob->receive_heal("sen",1000); };
	if ( ob->query("force") < ob->query("max_force") ) { ob->add("force",200); };
				};
//  攻擊
	if ( ob->is_fighting() ) 
	{
		for(i=0;i<n;i++)
		{
			if ( !enemy[i]->is_corpse() && enemy[i]->is_character() &&enemy[i]->query("id") != "iv bu" && enemy[i]->query("id") != "wild man" && random(100) < 20 )
			{
				if ( !enemy[i]->query_busy() ) { s=1+random(1); enemy[i]->start_busy(s); };
				d=100+random(200);
				enemy[i]->add("gin",-d); enemy[i]->add("kee",-d);
				enemy[i]->add("sen",-d); enemy[i]->add("force",-d);
				message_vision(HIR"$N放出狂大的鬥氣～$n受傷了！\n"NOR,ob,enemy[i]);
			}
		}
	}
::heart_beat(1);
}

void die()
{
object ob,me,obj,mob;
int i;

	ob = this_object();
	me = ob->query_temp("last_damage_from");

	if ( !me ) ::die();

	if ( writelog(ob,"open-war01") )
	{
		message_vision(HIW"$N用盡最後一口氣，緩緩的說：來不及了．．．呂布大人已經．．．

$N臉上的面膜掉了下來．．．\n"NOR,ob);
	tell_object(users(),HIR"

	撼天動地～鼓聲大作～邊境的野人入侵乾坤八卦塔！

\n"NOR);
		obj = new(__DIR__"wild_leader");
		obj->move("/open/area/pagoda/p01");
		for (i=0;i<7;i++) { mob = new(__DIR__"wild01"); mob->move("/open/area/pagoda/p01"); }
	}
::die();
}
