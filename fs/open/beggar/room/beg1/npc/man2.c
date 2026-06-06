
inherit NPC;
void create()
{
    set_name("火伕", ({ "man" }) );
	set("gender", "男性" );
        set("age",45);
        set("str",35);
        set("cor",45);
	set("cps",25);
	set("int",15);
	set("long",
"他是廚房的火伕.\n");
	set("combat_exp",350);
	set("attitude", "peaceful");
        set("chat_chance", 25);
	set_skill("parry", 15);
        set_skill("dodge", 5);
	setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();
        carry_object("/open/gsword/obj/g_pill");
         	
}

