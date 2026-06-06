inherit NPC;

void create()
{
        set_name("五袋弟子",({"beg five beggar","beggar","beg","five"}));
        set("long","他是丐幫的弟子\n");
        set("gender","男性");
        set("class","beggar");
        set("combat_exp",100000);
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
        set("max_kee",2800);
        set("kee",2800);
        set("max_sen", 1000);
        set("sen", 1000);
        set("force",3000);
        set("max_force",3000);
        set_skill("staff",65);
        set_skill("pkdog-staff",60);
        map_skill("staff","pkdog-staff");
        set_skill("force",60);
        set_skill("pkdog-force",60);
        map_skill("force","pkdog-force");
        set("force_factor",6);
setup();
carry_object("/open/beggar/obj/staff.c")->wield();
}

