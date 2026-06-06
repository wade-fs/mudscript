inherit NPC;
void create()
{
	set_name("小童", ({"clean boy","boy"}));
	set("long","仙劍派的小童,在這兒忙得昏頭轉向,因為受了師父陸正清的命令,
要把這兒所有的防具給擦拭乾淨,小孩子哪敢違背師父的命令,只好
拿著小油布拼命的擦拭著.\n");
	set("gender","男性");
	set("combat_exp",1000);
        set("attitude","friendly");
	set("age",15);
	set("title","仙劍派小童子");
	set("score",1000);
	set("force",0);
	set("max_force",0);
	set_skill("force",5);
        set_skill("shasword",4);
	set_skill("sword",7);
	set_skill("dodge",10);
	set_skill("parry",6);
	set_skill("literate",15);
	set_skill("unarmed",10);
	set_skill("blade",7);
	set_skill("dagger",5);
        set("str", 20);
        set("cor", 26);
	set("per", 20);
	set("int", 15);
	set("cps", 10);
	set("con", 20);
	set("spi", 15);
	set("kar", 15);
	setup();
	carry_object("/open/gsword/obj/suit")->wear();
	add_money("coin",50);
}

