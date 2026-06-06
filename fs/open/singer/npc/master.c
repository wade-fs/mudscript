inherit F_MASTER;
inherit NPC;
#include <ansi.h>

void create()
{
	set_name("柯淚\詩",({"master crazy","crazy"}));
	set("class","scholar");
	create_family("詠樂門",1,"掌門人");
	set("gender","女性");
	set("long","\n");
	set("age",24);
	set("combat_exp",5000000);
	set("max_gin",50000);
	set("max_kee",60000);
	set("max_sen",50000);
	set("gin",50000);
	set("kee",60000);
	set("sen",50000);
	set("max_atman",60000);
	set("atman",60000);
	set("max_force",100000);
	set("force",100000);
	set("max_mana",50000);
	set("mana",50000);
	set("str",10);
	set("cor",50);
	set("int",50);
	set("spi",50);
	set("cps",50);
	set("per",50);
	set("con",50);
	set("kar",50);
	set_skill("sing",100);
setup();
}


void attempt_apprentice(object me)
{
	command("say 好～我收你為徒!");
	command("recruit "+me->query("id"));
	me->set("class-level/singer/level",5);
}
