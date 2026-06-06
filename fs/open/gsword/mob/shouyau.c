inherit NPC;
#include "/open/open.h"
inherit F_MASTER;

void create()
{
	set_name("李逍遙",({"shou yau","yau"}));
 set("long","逍遙子的第七個徒弟,在仙劍七俠中,入門最晚,但是際遇不凡,兼之
悟性奇高,據說其實際武功\已在其大師兄張乘風之上,李逍遙天性不拘
小節,愛好打抱不平,近幾年來仗劍行俠於江湖,也已小有俠名.\n");
	set("gender","男性");
	set("combat_exp",500000);
	set("guild_master",1);
        set("attitude","heroism");
	set("age",21);
	set("class","swordsman");
	set("title","仙劍派第四代七弟子");
	set("score",100000);
	set("force",1000);
	set("max_force",1000);
	set("force_factor",10);
	set_skill("sword",100);
	set_skill("force",60);
	set_skill("array",100);
	set_skill("parry",80);
	set_skill("dodge",90);
	set_skill("literate",60);
	set_skill("move",80);
	set_skill("unarmed",60);
	set_skill("blade",40);
	set_skill("stick",90);
	set_skill("poison",40);
	set_skill("fonxansword",100);
	map_skill("parry","fonxansword");
	map_skill("sword","fonxansword");
        set("str", 30);
        set("cor", 30);
	set("per", 30);
	set("int", 30);
	set("cps", 30);
	set("con", 30);
	set("spi", 30);
	set("kar", 30);
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
	(:perform_action,"sword.counterattack":)
	}));
	setup();
	carry_object("/u/w/wugi/obj/sword-7")->wield();
 	create_family("仙劍派",4,"弟子");
}
 int accept_fight(object me)
 {
 if((int)me->query("combat_exp")<=80000)
 {
  command(":P");
  command("say 年輕人,生命是很可貴的,請好好珍惜!");
  return 0;
 }
 command(":D");
 command("say 好久沒遇到對手了,亮劍吧!");
  return 1;
 }
         
void attempt_apprentice(object ob)
  {
	if(!ob->query_temp("allow_7"))
	{
	command("say 好小子,有眼光! ..不過 ...");
	command("say 師父說過,不能亂收徒弟!");
	command("shrug");
	return 0;
	}
  command("giggle");
 command("say 跟著我就對啦!");
 command("say 以後可要認真學喔!");
  command("recruit "+ob->query("id"));
  ob->set("marks/仙劍七俠",1);
  }
