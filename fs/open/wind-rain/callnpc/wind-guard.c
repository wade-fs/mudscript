inherit PARTY_NPC;
#include <ansi.h>
void create()
{
	set_name("風護衛",({"wind guard","guard"}));
	set("long","
金風細雨樓中，「金風細雨」四輩護衛中的風護衛，可以為持有風雨令
的人犧牲生命在所不惜。
");
	set("gender","男性");
	set("combat_exp",450000);
	set("attitude","peaceful");
	set("age",33);
	set("str", 30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
        set("max_force",2200);
        set("force",2200);
        set("max_kee",1100);
        set("force_factor",18);
	set_skill("hammer",80);
        set_skill("wind-hammer",85);
	set_skill("parry",80);
        set_skill("wind-rain",75);
	set_skill("dodge",75);
        set_skill("move",65);
        set_skill("lo-steps",85);
        map_skill("hammer", "wind-hammer");
        map_skill("dodge","lo-steps");
        map_skill("move","lo-steps");
        map_skill("parry","wind-rain");
	setup();
        carry_object("/open/wind-rain/obj/star-hammer")->wield();
	add_money("silver",90);
}
int accept_kill(object who)
{
  command("say 竟敢動風雨樓的人！");
  return 1;
}
