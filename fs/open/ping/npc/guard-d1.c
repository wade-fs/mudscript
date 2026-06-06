// guard.c
inherit NPC;

void create()
{
	set_name("城門守衛", ({ "door guard", "guard" }) );
	set("gender", "男性" );
	set("age", 35);
	set("str", 30);
	set("cor", 55);
        set("cps",20);
	set("int", 15);
	set("long",
		"一個看守城門的守衛.\n"
                "將軍剛剛發軍餉,他還沒回家就被派來守門,\n"
                "正一肚子氣 ...\n" );
        set("combat_exp",2000);
	set("attitude","peaceful");
	set("force",200);
        set("max_force",200);
        set("force_factor",4);
	set_skill("parry", 3);
	set_skill("dodge", 3);
	set_skill("unarmed",25);
        set_skill("gold-blade",20);
        set_skill("fly-steps",3);
        map_skill("blade","gold-blade");
        map_skill("dodge","fly-steps");
        map_skill("parry","gold-blade"); 
 	setup();
	add_money("silver",5);
	carry_object("/open/gblade/obj/blade")->wield();
        carry_object("/open/gsword/obj/g_pill")->set_amount(10);
	carry_object("/open/ping/obj/chainmail")->wear();
         	
}

