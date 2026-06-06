#include <ansi.h>
inherit NPC;

void create()
{
        set_name("蘇由",({"su leader","su","leader"}));
        set("long","他是丐幫布袋長老中的一員！\n");
        set("gender","男性");
        set("class","beggar");
        set("nickname",HIY"乞中神丐"NOR);
        set("combat_exp",1000000);
        set("attitude","friendly");
        set("age",40);
        set("title",HIW"八袋長老"NOR);
        set("str", 40);
        set("cor", 40);
        set("cps", 30);
        set("per", 35);
        set("spi", 40);
        set("int", 20);
        set("con", 30);
        set("kar", 30);
        set("max_gin", 5000);
        set("gin", 5000);
        set("max_kee",4000);
        set("kee", 4000);
        set("max_sen", 5000);
        set("sen", 5000);
        set("force",6000);
        set("max_force",6000);
        set("max_atman",1000);
        set("max_mana",1000);
        set("mana",1000);
        set("atman",1000); 
        set_skill("staff",120);
        set_skill("pkdog-staff",100);
        map_skill("staff","pkdog-staff");
        set_skill("force",90);
        set_skill("pkdog-force",90);
        set_skill("pkdog-force",90);
        map_skill("force","pkdog-force");
        set_skill("dodge",100);
        set_skill("move",100);
        set_skill("shift-steps",100);
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        set("force_factor",10);
        set_skill("parry",90);
        set("bellicosity",1000);
        set("chat_chance",50);
        set("functions/skydog/level",80);
        set("chat_chance_combat",30);
        set("chat_msg_combat",({
        (: perform_action ("staff.skydog") :),
        }));
        set("chat_msg", ({
   
        HIC"蘇由說道：該趕快去找個好地方行乞喔!!\n"NOR,}));
        setup();
carry_object("/open/beggar/obj/gstaff.c")->wield();
carry_object("/open/beggar/obj/neck.c")->wear();
}




int accept_kill (object who)
{
        who=this_player();
  kill_ob(who);
  command("perform staff.skydog");
  return 1;
}

int accept_fight (object who)
{
  command("ohoh");
  command ("say 讓你瞧瞧乞丐的厲害！"); 
  command ("wear all");
  return 1;
}



