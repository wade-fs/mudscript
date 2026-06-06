#include <ansi.h>
inherit NPC;

void create()
{
        set_name("丐胎鴿",({"master dirty","master","dirty"}));
        set("long","他就是號召丐幫的總召集人，身旁還圍繞了一堆蒼蠅！\n");
        set("gender","男性");
        set("class","beggar");
        set("combat_exp",100000);
        set("attitude","friendly");
        set("age",40);
        set("title",HBCYN+HIW"丐幫召集人"NOR);
        set("str", 40);
        set("cor", 40);
        set("cps", 30);
        set("per", 35);
        set("spi", 40);
        set("int", 20);
        set("con", 30);
        set("kar", 30);
        set("max_gin", 1000);
        set("gin", 1000);
        set("max_kee", 5000);
        set("kee", 5000);
        set("max_sen", 1000);
        set("sen", 1000);
        set("force",5000);
        set("max_force",10000);
        set("max_atman",1000);
        set("max_mana",1000);
        set("mana",1000);
        set("atman",1000); 
        set_skill("staff",80);
        set_skill("pkdog-staff",80);
        map_skill("staff","pkdog-staff");
        set_skill("force",80);
        set_skill("pkdog-force",80);
        map_skill("force","pkdog-force");
        set_skill("dodge",50);
        set_skill("move",40);
        set_skill("shift-steps",50);
        map_skill("dodge","shift-steps");
        map_skill("move","shift-steps");
        set("force_factor",10);
        set_skill("parry",40);
        set("bellicosity",500);
        set("MKS",4000);
                set("inquiry" , ([
			"長老" : "長老呀，好久的事了，他只要一心情不好就會往山林裡去，你也許\可以到各處的山林找找看。\n",
                        ]));
        setup();
}


int accept_kill (object who)
{
  command ("say 你真是討皮痛耶！"); 
  command ("wear all");
  return 1;
}

int accept_fight (object who)
{
  command("ohoh");
  command ("say 既然如此﹐看我的狗屎攻擊！"); 
  command ("wear all");
  return 1;
}


void init()
{
   add_action("do_join","join");
}


int do_join()
{
        if(this_player()->query("class")=="beggar")
        return notify_fail("你已經是乞丐囉 !\n");
        if(this_player()->query("have_officer")==1)
        return notify_fail("朝庭的走狗，快走開！\n");
        if(this_player()->query("class"))
        return notify_fail("你已經加入其他工會了。\n");
        this_player()->set("class","beggar");
        message("system",HIW "丐胎鴿"HIC"縱聲大笑：\n
我們丐幫又多了個生力軍" +this_player()->name()+ "囉！\n
各位夥伴們，一起歡迎他吧！\n\n"NOR,users());
        command("smile "+this_player()->query("id"));
        command("say 希望你能好好乞討，才不會餓死！\n");
        return 1;
}


