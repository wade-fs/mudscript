inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create()
{
        object ob;
	set_name("樓外細護衛",({"thin guard","guard"}));
	set("long","
金風細雨樓中，「金風細雨」四輩護衛中的細護衛
負責樓外花園的巡邏。
");
	set("gender","男性");
	set("combat_exp",100000);
	set("attitude","peaceful");
	set("age",25);
	set("class","soldier");
	set("str",30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
        set("max_force",1000);
        set("force",1000);
        set("max_kee",450);
        set("force_factor",3);
	set_skill("dagger",30);
        set_skill("thin-dagger",45);
	set_skill("parry",30);
        set_skill("wind-rain",45);
	set_skill("dodge",30);
        set_skill("move",45);
        set_skill("lo-steps",45);
        map_skill("dagger", "thin-dagger");
        map_skill("dodge","lo-steps");
        map_skill("move","lo-steps");
        map_skill("parry","wind-rain");

	setup();
        carry_object(C_OBJ"/dagger-1")->wield();
	add_money("silver",20);
}
int accept_kill(object who)
{
  command("say 竟敢動風雨樓的人！");
  return 1;
}
