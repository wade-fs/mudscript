// crazy_dog.c

inherit NPC;

void create()
{
	set_name("王安", ({ "wang ani", "wang" }) );
	set("title","仙劍派廚子");
	set("race", "人類");
	set("age", 53);
	set("long", "瞧他手執菜刀的姿勢,便知道他是個一等一個大廚。\n");
	set("attitude", "peaceful");
	set("str", 17);
	set("cor", 15);
	set("force",200);
	set("max_force",200);
	set("force_factor",2);
	set_skill("blade",20);
	set("combat_exp",3000);
	set_skill("blade",20);
	set_skill("her-blade",20);
	set_skill("force",20);
	set_skill("oneforce",20);
	set_skill("dodge",20);
	set_skill("parry",20);
	map_skill("blade","her-blade");
	map_skill("force","oneforce");
	setup();
       add_money("coin",50);
	carry_object("/open/gsword/obj/knife")->wield();
	carry_object("/open/gsword/obj/dirty_cloth")->wear();
}
