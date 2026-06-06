inherit NPC;

void create()
{
	set_name("銅刀護院",({"bronze-blade guardian","guardian"}));
        set("long","
專門負責金刀門內院安全的衛士，神采奕奕，精神抖擻，一雙眼睛炯炯有
神地注視著你的一舉一動。
");
        set("gender","男性");
        set("combat_exp",4000);
	set("attitude","heroism");
        set("age",20);
	set("force",150);
	set("max_force",150);
	set("force_factor",2);
        set_skill("blade", 25);
        set_skill("dodge", 20);
        set_skill("parry", 15);
        set_skill("force", 15);
	set_skill("gold-blade",10);
        set_skill("sixforce",10);
	set_skill("fly-steps",15);
        map_skill("force", "sixforce");
        map_skill("blade", "gold-blade");
        map_skill("dodge", "fly-steps");
        set("race", "人類");
        set("limbs", ({ "頭部",  "雙腳", "雙手", "胸部" ,"腹部","腰部"}) );
                setup();
	carry_object("/open/gblade/obj/bronze-blade.c")->wield();
	carry_object("/open/gblade/obj/bronze-robe")->wear();
	add_money("silver",20);

}
