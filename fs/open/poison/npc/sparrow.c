
# include <ansi.h>
inherit NPC; 

void create()
{
	set_name("麻雀",({"sparrow"}) );
	set("long","
一隻正在啄著地上穀\物的小麻雀，發覺你的靠近，牠驚慌的跳開，等跟你
保持一距離後，又低下頭來繼續啄牠的食物。\n");
	set("age",3);
	set("str",7);
	set("con",8);
	set("race","野獸");
	set("max_kee",70);
	set("max_gin",70);
	set("max_sen",70);
	set("limbs",({
	"頭部","翅膀","身體","左腳","右腳","腹部"}) );
	set("verbs",({"claw","poke"}) );
	set("chat_chance", 4);
	set("chat_msg",({
	"麻雀啄了一口穀\物。\n",
}) );
	set("combat_exp",100);
	setup();
}

