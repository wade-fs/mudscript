inherit NPC;
void create()
{
        set_name("銀針弟子",({"needle trainee","trainee"}));
        set("long","銀針門的見習弟子,正在勤奮的練抸穴。\n");
        set("class","doctor");
        set("gender","男性");
        set("combat_exp",4000);
        set("max_force",200);
        set("force",200);
        set("max_kee",250);
        set("kee",250);
        set("age",16);
        set("str",40);
        set_skill("force",20);
        set_skill("stabber",15);
        set_skill("shinnoforce",15);
        set_skill("cure",15);
        set_skill("dodge",15);
        set_skill("move",10);
        set_skill("parry",15);
set_skill("seven-steps",10);
        set_skill("yu-needle",18);
map_skill("dodge","seven-steps");
map_skill("move","seven-steps");
        map_skill("stabber","yu-needle");
        map_skill("force","shinnoforce");
        map_skill("parry","yu-needle");
        setup();
        add_money("coin",40);
        carry_object("/open/doctor/obj/needle3.c")->wield();
}


