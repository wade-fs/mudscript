#include <ansi.h>

inherit NPC;
void create()
{
	set_name("路人",({"person"}));
	set("gender","男性");
	set("combat_exp",1);
	set("attitude","heroism");
	set("age",30);
	setup();
}
void init()
{
	object me = this_player();
	call_out("do_say",1,me);
}
int do_say( object me )
{
	object ob = me;
	command("say 這位"+(ob->query("gender")=="男性" ? "壯士" : "姑娘")+
		"請留步﹐現在雪蒼山上面正在戒備中﹐勸你最好不要上去。");
}
