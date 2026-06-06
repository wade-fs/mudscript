
#include <ansi.h>

inherit NPC;

void create()
{
	set_name("寨主",({"bandit leader","leader"}));
	set("long","
此人長的虎背熊腰，體型高大，手上一柄鬼頭刀使的虎虎生風，莫怪能
當上寨主，統領一群綠林豪傑雄霸一方。\n");
	set("age",35);
	set("gender","男性");
	set("title","黑風寨");
	set_skill("blade",40);
	set_skill("dodge",35);
	set_skill("parry",40);
	set("combat_exp" ,400000);
	set("attitude","aggressive");
	set("chat_chance_combat", 5);
	set("chat_msg_combat" ,({
	"寨主說道:小子，要不加入我們寨，包你吃香的喝辣的。\n",

}) );
	
	setup();
	add_money("silver", 30);
	carry_object("/open/poison/obj/ghblade.c")->wield();
	carry_object("/obj/cloth.c")->wear();
}
