// made by onion
#include "/open/open.h"
inherit NPC;
object leader;
void create()
{
        set_name("鳳雙雙",({"feng"}));
        set("long","她的樣子恬靜秀麗、溫馴善良, 唇厚而豔紅欲滴, 眼瞇時露笑意, 但卻給人豔麗的感覺。\n");
        set("gender","女性");
	set("class","swordsman");
        set("combat_exp", 200000);
        set("attitude","heroism");
	set("age",29);
	create_family("仙劍派",5,"弟子");
	set("nickname","黑白雙俠");
	set("force",1000);
	set("max_force",1000);
        set("force_factor", 10);
        
        set_skill("force",20);
        set_skill("shaforce",40);
        set_skill("sha-array",60);
        set_skill("sha-steps",60);
        set_skill("shasword",50);
        set_skill("sword",80);
        set_skill("dodge",60);
        set_skill("parry",60);
        set_skill("unarmed",40);
        set_skill("array",80);
        map_skill("sword","shasword");
        map_skill("force","shaforce");
	map_skill("array","sha-array");
	map_skill("dodge","sha-steps");
	map_skill("move","sha-steps");
        set("functions/sha_kee/level",30);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: command,"perform sword.swordkee" :),
                (: perform_action("sword.sha_kee") :),
        }));
	setup();
	carry_object(CAPITAL_OBJ"cloth3")->wear();
	carry_object(CAPITAL_OBJ"sword1")->wield();
	add_money("silver",10);
}

void init()
{
	leader=find_object(CAPITAL_NPC"g0");
	set_temp("leader",leader);
        set_leader(leader);
}

int accept_fight(object who)
{
	leader=present("chang-shun",environment(this_object()));
	if( leader )
		leader->accept_fight(who);
	else	::accept_fight(who);
	return 1;
}
int accept_kill(object who)
{
	leader=present("chang-shun",environment(this_object()));
        if( leader )
        	leader->accept_kill(who);
	else    ::accept_kill(who);
        return 1;
}


