inherit NPC;

void create()
{
	set_name("銀刀護院",({"silver-blade guardian","guardian"}));
        set("long","
滿臉和善的笑容中隱含著一股不容侵犯的威嚴，望著他不怒自威的眼神，
使得你內心的作歹念頭，一掃而空。
");
        set("gender","男性");
        set("combat_exp",5500);
	set("attitude","heroism");
        set("age",35);
        set_skill("unarmed",30);
        set_skill("blade", 30);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("force", 20);
        set_skill("gold-blade",25);
        set_skill("sixforce",10);
	set("force",300);
	set("max_force",300);
	set("force_factor",3);
	set_skill("fly-steps",25);
        map_skill("force", "sixforce");
        map_skill("blade", "gold-blade");
        map_skill("dodge", "fly-steps");
        set("race", "人類");
        set("limbs", ({ "頭部",  "雙腳", "雙手", "胸部" ,"腹部","腰部"}) );
                setup();
	carry_object("/open/gblade/obj/silver-blade.c")->wield();
	carry_object("/open/gblade/obj/snake-boots.c")->wear();
	carry_object("/open/gblade/obj/silver-robe")->wear();
	add_money("silver",50);

}
