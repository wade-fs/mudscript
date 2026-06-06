
#include <ansi.h>

inherit NPC;
void create()
{
	set_name("小孩",({"child"}) );
	set("long","
一個可愛的小孩子，頭上紮了兩個髻，他正高興的在玩耍著，似乎不知憂愁
為何物。\n");
	set("gender","男性");
	set("unarmed", 2);
	set("dodge", 3);
	set("attitude","friendly");
	set("age",14);
	set("max_kee",100);
	set("max_gin",100);
	set("max_sen",100);
	set("combat_exp",100);
	set("chat_chance",4);
	set("chat_msg" ,({
	"小孩高興地笑著。\n",
	(: this_object(), "random_move" :),
}) );
	setup();
	carry_object("/obj/cloth.c")->wear();
	add_money("coin", 5);
}
