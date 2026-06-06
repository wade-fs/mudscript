inherit NPC;

void create()
{
        set_name("三袋弟子",({"beg three beggar","beggar","beg","three"}));
        set("long","他是丐幫的弟子\n");
        set("gender","男性");
        set("class","beggar");
        set("combat_exp",50000);
        set("attitude","friendly");
        set("age",40);
        set("str", 30);
        set("cor", 40);
        set("cps", 30);
        set("per", 35);
        set("spi", 20);
        set("con", 30);
        set("int", 30);
        set("kar", 30);
        set("max_gin",1000);
        set("gin", 1000);
        set("max_kee",2000);
        set("kee",1500);
        set("max_sen", 1000);
        set("sen", 1000);
        set("force",2000);
        set("max_force",2000);
        set_skill("staff",55);
        set_skill("pkdog-staff",30);
        map_skill("staff","pkdog-staff");
        set_skill("force",30);
        set_skill("pkdog-force",40);
        map_skill("force","pkdog-force");
        set("force_factor",5);
setup();
carry_object("/open/beggar/obj/staff.c")->wield();
}

