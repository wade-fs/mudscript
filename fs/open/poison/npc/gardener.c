#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
	set_name("老園丁", ({"old gardener","gardener"}) );
	set("age", 70);
	set("combat_exp",100000);
	set("score", 100000);
	set("long","一個園丁模樣的人,瞧他的服飾應是魔教中人.但你奇怪他為何能終年
在此地做事而不為毒所侵,想必是具有深厚內力的內家高手。\n"+
"他正為了井水不足的問題在煩惱著。\n");
	set("class", "poisoner");
	set("gender", "男性");
	set("attitude", "friendly");
	set("str", 44);
	set("cps", 30);
	set("cor", 30);
	set("con", 33);
	set("force", 600);
	set("max_kee",800);
	set("max_sen",800);

	set("gin", 800);
	set("max_gin",800);
	set("max_force", 600);
	set("force_factor",1);
	set_skill("parry", 30);
	set_skill("dodge", 50);
	set_skill("move", 50);
	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("poison", 60);
	set_skill("poisonforce", 30);
	set_skill("coldpoison", 60);
	set_skill("nine-steps", 60);
	map_skill("move","nine-steps");
	map_skill("dodge","nine-steps");
	map_skill("poison", "coldpoison");
	map_skill("force", "poisonforce");
	set_skill("dagger",40);
	set("chat_chance", 10);
	set_skill("dragon-dagger", 40);
	map_skill("dagger", "dragon-dagger");
	set("chat_msg",({
		"老園丁說道:嘿,這裡很漂亮吧.我可是每天很辛苦的除草、澆花喔!\n",
            "老園丁憂愁說道:最近園子裡不知怎麼了,井水的供給一直不足。\n",
}) );
	set("chat_chance_combat", 6);
	set("chat_msg_combat",({
		"老園丁說道:不自量力的小伙子,敢向我挑戰。\n",
		"老園丁說道:我老歸老,但可是寶刀未老,小子你還嫩得很吶!\n",
}) );
	set("inquiry", ([
	"井水" : " 你能幫老朽查探查探嗎?若事成,老朽有一物相贈。\n",
"巨蟒" : "原來是此物在做怪,你若是能制伏此物,並帶來證明之物,老朽即將身上所帶
之奇書贈之。\n",
]) );
	setup();

                                                             
                                                              
                                                              
                                                             
                                                              
	carry_object("/open/poison/obj/scissors.c")->wield();
        carry_object("/open/poison/obj/ecloth.c")->wear();
	carry_object("/open/poison/obj/ebelt.c")->wear();
carry_object("/obj/poison/rose_poison")->set_amount(5);
carry_object("/obj/poison/five_poison")->set_amount(5);
carry_object("/obj/poison/dark_poison")->set_amount(5);
carry_object("/obj/poison/faint_poison")->set_amount(5);

}
int accept_object(object who, object item)
{
	object me;
	me = this_player();
	if (item->query("id") == "serpent tooth")
	{ destruct (item);
	tell_object (who, "老園丁高興的說:真是多謝了,這本書就當謝禮吧。\n");
	new("/open/poison/obj/pkingbook.c")->move(who);
	return 1;
	}
	else
	{
	tell_object (who, "老園丁疑惑的說:你給我這樣東西做甚？？\n");
	 return 1;
	}
}
