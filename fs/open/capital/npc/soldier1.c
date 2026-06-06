//禁衛軍小隊長 by Onion

#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("禁衛軍小隊長",({"soldier leader","leader","soldier"}) );
	set("gender","男性");
	set("age",33);
	set("class","soldier");
	set("str",30);
	set("long","禁衛軍中的小隊長, 唯有較出色武藝與表現才能升為隊長。\n");
	set("combat_exp",20000 );
        set("chat_chance",5);
	set("chat_msg",({
	"禁衛軍小隊長說道: 這兒是糧草重地, 不相干人等逕速離去。\n",
	}));
	set("inquiry", ([
	"thief" : "大盜? 只要他敢來這偷糧草, 我馬上讓他束手就擒。 hehe ",
	]));
	set_skill("unarmed",60);
	set_skill("blade",60);
	set_skill("parry",60);
	set_skill("dodge",60);
        set_skill("her-blade",50);
        map_skill("blade","her-blade");
                
	setup();
	carry_object(CAPITAL_OBJ"Ns_suit")->wear();
	carry_object(CAPITAL_OBJ"Ns_boots")->wear();
	carry_object(CAPITAL_OBJ"Ns_hat")->wear();
        carry_object(CAPITAL_OBJ"Hblade")->wield();
}

int accept_fight(object who)
{
	return notify_fail("禁衛軍說：對不起，我正在執行公務。\n");
}

