inherit NPC;

void create()
{
	set_name("樵夫",({ "woodcutter","cutter" }) );
	set("long", "這是一個平凡的樵夫，但不知他在喃喃自語些什麼。\n");

	set( "age", 35);

	set("str", 32);
        set("cor", 30);


	set("combat_exp",264);


	set_skill("dodge",10);
	set_skill("hammer",20);

	set("race", "人類");

	set( "gender", "男性");


        set("attitude", "friendly");

	set("chat_chance",10);
        set("chat_msg", ({
	"樵夫說道:最近這附近常常有魔教徒出末。\n",
	"樵夫喃喃自語:住在北邊的獵人居然不怕魔教徒。\n",
	"樵夫說道:我懷疑他也是魔教徒。\n",
	 }) );
    setup();
}
