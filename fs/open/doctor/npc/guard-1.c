inherit NPC;

void create()
{
        set_name("銀針門侍衛",({"guard"}));
        set("long","
滿臉和善的笑容中隱含著一股不容侵犯的威嚴，望著他不怒自威的眼神，
使得你內心的作歹念頭，一掃而空。
");
        set("gender","男性");
        set("combat_exp",100000);
        set("attitude","heroism");
        set("age",30);
        set_skill("unarmed",16);
        set_skill("dodge", 20);
        set_skill("parry", 20);
        set_skill("force", 20);
        set_skill("shinnoforce",10);
        set_skill("yu-needle",50);
        set("force",300);
        set("max_force",300);
        set("force_factor",5);
        set_skill("seven-steps",30);
        map_skill("force", "shinnoforce");
        map_skill("unarmed", "yu-needle");
        map_skill("dodge", "seven-steps");
        set("race", "人類");
                setup();
        add_money("silver",70);

}

