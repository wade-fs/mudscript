
inherit NPC;
void create()
{
        set_name("病人", ({ "paitent" }) );
	set("gender", "男性" );
        set("age",45);
        set("str",35);
        set("cor",45);
	set("cps",25);
	set("int",15);
	set("long","病厭厭的他是來銀針門看病的.\n");
	set("combat_exp",350);
	set("attitude", "peaceful");
        set("chat_chance", 25);
        set("chat_msg", ({
              "病人說: 好痛苦喔!!.\n",
              "病人說: 頭痛,流鼻涕~\n",
        }) );
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();
         	
}


