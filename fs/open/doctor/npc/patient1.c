
inherit NPC;
void create()
{
        set_name("病人", ({ "paitent" }) );
	set("gender", "女性" );
        set("age",45);
        set("str",35);
        set("cor",45);
	set("cps",25);
	set("int",15);
	set("long","病厭厭的她是來銀針門看病的.\n");
	set("combat_exp",350);
	set("attitude", "peaceful");
        set("chat_chance", 25);
        set("chat_msg", ({
              "病人說: 怎麼那麼多人啊!!那時才會輪到我呢?\n",
              "病人說: 最近不知道怎麼搞的,吃不下飯,也睡不著..*_*\n",
        }) );
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();
         	
}


