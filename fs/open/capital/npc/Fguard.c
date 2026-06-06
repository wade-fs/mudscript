//競技場守衛

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("競技場守衛",({"fightroom guard","guard"}) );
	set("gender","男性");
	set("age",30);
	set("class","soldier");
	set("str",44);
	set("long","他是乾通天請來負責競技場內的安全工作的。\n");

        set("max_kee",1000);
	set("combat_exp", 22000);
	set_skill("unarmed",60);
	set_skill("parry",40);
	set_skill("dodge",40);
	set_skill("longfist",80);
	map_skill("unarmed","longfist");
	set_temp("apply/damage",40);
        set_temp("apply/dodge",40);
        set_temp("apply/attack",40);

	setup();
}

int accept_fight(object who)
{
	return notify_fail(name()+"說：要打就去櫃臺那找人挑。\n");
}
int accept_kill(object who)
{
	object *inv=all_inventory(environment(this_object()));
	int i;
	say(name()+"喝道：找死嗎？"+RANK_D->query_rude(who)+"\n");
        command("say 兄弟們, 上!!\n");
	who->set_temp("殺競技場守衛",1);
	for(i=0;i<sizeof(inv);i++)
                if( getuid(inv[i])=="fightroom guard" )
			inv[i]->kill_ob(who);
	return 1;
}

void greeting(object who)
{
    if(!who) return ;
        if( who->query_temp("殺競技場守衛") )
	{
	  command("angry "+getuid(who));
	  command("say 好啊"+RANK_D->query_rude(who)+"!!殺人償命，還不束手就擒。\n");
	  kill_ob(who);
	}
}

