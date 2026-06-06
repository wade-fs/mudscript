
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("莊稼漢",({"man"}) );
	set("age",30);
	set("str",25);
	set("con",20);
	set("max_kee",200);
	set("long","
一個普通的莊稼漢，他正為了農事忙碌不以。\n");
	set("unarmed", 5);
	set("gender","男性");
	set("dodge", 5);
set("chat_chance_combat", 100);
    set("chat_chance",25);
	set("chat_msg" , ({
        "莊稼漢愉快地說:最近村裡來了一個老人，村長好像同意他<落腳>在這邊。\n",
}) );
	set_temp("apply/armor",9);
	set_temp("apply/dodge",2);
	set("combat_exp", 400);

	setup();
	add_money("coin",20);
	carry_object("/obj/cloth.c")->wear();
	carry_object("/obj/example/bag.c");
}
