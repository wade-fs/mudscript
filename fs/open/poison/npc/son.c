
inherit NPC;




void create()
{
	set_name("大牛",({"son"}));
	set("age",15);
	set_skill("dodge",10);
	set("combat_exp",100);
	
	set("long","樵夫的兒子,由於天生的弱智,使的他的反應較一般人遲鈍,他看起來呆呆的.\n");
	set("chat_chance",6);
	set("chat_msg",({
		"大牛喃喃自語道:阿～～阿達!.\n",
		}) );
	setup();
}



