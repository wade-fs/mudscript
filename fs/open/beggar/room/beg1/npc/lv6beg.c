#include <ansi.h>
inherit NPC;

void create()
{
        set_name("六袋弟子",({"beg six beggar","beggar","beg","six"}));
        set("nickname",HIC + "丐幫幫眾" + NOR);
        set("long","他是丐幫的弟子\n");
        set("gender","男性");
        set("class","beggar");
        set("combat_exp",250000);
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
        set("max_kee",3300);
        set("kee",3300);
        set("max_sen", 1000);
        set("sen", 1000);
        set("force",4000);
        set("max_force",4000);
        set_skill("staff",80);
        set_skill("pkdog-staff",80);
        map_skill("staff","pkdog-staff");
        set_skill("force",80);
        set_skill("pkdog-force",80);
        map_skill("force","pkdog-force");
        set_skill("shift-steps",90);
        set_skill("parry",80);
        set_skill("dodge",80);
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        set("force_factor",8);
setup();
carry_object("/open/beggar/obj/staff.c")->wield();
carry_object("/open/beggar/obj/cloak.c")->wear();
}

