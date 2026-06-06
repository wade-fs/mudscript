inherit NPC;
#include <ansi.h>

void create()
{
        set_name("野人",({"wild man","wild","man"}));
        set("long","蓬鬆的頭髮，已經破爛不堪的衣服，說明了野人的生活。

她身上掛著似乎與別人不太一樣的裝飾品。\n");
        set("race","野獸");
        set("attitude","friendly");
        set("limbs", ({ "頭部", "身體", "手臂" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp",400000);
        set("max_gin",5000);
        set("max_kee",10000);
        set("max_sen",5000);
        set("max_force",10000);
        set("gin",5000);
        set("kee",10000);
        set("sen",5000);
        set("force",10000);
        set("chat_chance",20);
        set_temp("apply/armor", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set_skill("dodge",200);
        set_skill("move",200);
        set_skill("unarmed",100);
        set_skill("force",200);
        set("force_factor",30);
        setup();
}

void greeting(object ob)
{
	 if( !ob || environment(ob) != environment() ) return;

	say("野人說：想進去野人村嗎？給我黃金我就告訴你方法。\n");
}

int accept_object(object me,object obj)
{
object ob,item;
	ob = this_object();

	if ( obj->query("id") != "gold" )
		return  1;

	if ( obj->query_amount() < 150 )
		message_vision("$N失望的搖搖頭，示意不夠．．．\n",ob);
	else
	{
		item = new(__DIR__"obj/item01");
		message_vision("野人高興的將$n交給了$N\n",me,item);
		item->move(me);
	}
	destruct(obj);
return 1;
}
