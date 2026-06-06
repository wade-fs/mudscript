// master_tor.c made by adam..

#include <ansi.h>
#include "marksman.h"
inherit NPC;
inherit F_MASTER;


void create()
 {
        set("class", "marksman");
set_name("李廣", ({ "master lee", "master", "lee" }) );
        set("title","射日派第二代掌門人");
        set("nickname",HIC + "心定穿石" + NOR);
        set("gender", "男性");
set("max_kee",5000);
        set("age", 55);
        set("attitude", "heroism");
        set("long","李廣為古代名將之一，曾在一次打獵中，把箭射進石頭裡，謂之讚嘆..\n");
        set("str", 18);
        set("cps", 30);
        set("per", 10);
        set("int", 40);
        set("kar", 16);
set("combat_exp",2000000);
set("bellicosity",5000);
set("force",8000);
set("max_force",8000);
set("force_factor",30);
        set("score"       , 200000);
set_skill("force",80);
set_skill("archery",120);
set_skill("god-shooting",100);
set_skill("move",70);
set_skill("parry",70);
set("functions/ten_kee/level",100);
set_skill("dodge",70);
set_skill("literate",40);
        set_skill("iceforce",100);
        set_skill("rain-steps",100);
set_skill("riding",80);
        map_skill("force", "iceforce");
        map_skill("dodge", "rain-steps");
        map_skill("parry", "rain-steps");
        map_skill("archery","god-shooting");
        map_skill("move","rain-steps");
set("chat_chance_combat",5);
                set("chat_msg_combat", ({
(: perform_action("archery.ten_kee") :)
        }));


        create_family("射日派", 2, "掌門人");


        setup();
carry_object(C_OBJ"/bow-9")->wield();
carry_object(C_OBJ"/arrow-8");
        add_money("gold",10);
}


void init()
{
add_action("do_level","level");
}

int do_level(int lv,object me)
{
me = this_player();
lv = me->query("combat_exp")/100000;
if(me->query("level") < lv)
{
write("李廣說: 你還不夠升級，再努力吧!!\n");
}else{
write("李廣說: 恭喜你升級了。\n");
me->set("level",lv);
}
return 1;
}

void attempt_apprentice(object ob)
{
        if(this_player()->query("class")!="marksman")
        {
                command("sigh");
                command("say 你不是射手﹐我不能收你。\n");
                return;
        }
      if((int)ob->query_str() <16 )
{
          command("sigh");
          command("say 你的膂力不夠，拿起弓來一定會顫抖..\n敝人觀之"+ RANK_D->query_respect(ob) + "的資質似乎不宜！\n");

return;
        }

      command("hmm");
new(C_OBJ"/bow-1")->move(ob);
command("say 給你把弓，可不要用不見啦!");
      command("pat" + ob->query("id"));
      command("recruit "+ob->query("id"));
ob->set("appraise",random(5));
message("system",HIR + "李廣笑道 :\n
      " + HIW + "" +this_player()->name()+ "" + NOR + "" + HIR + "拜入我門下 !\n
      他日必可成為一代神射手!\n
      成為武林至尊!!\n\n" + NOR,users());

ob->set("Lbird-shop","YES");
}
int accept_kill(object ob)
{
 command("say 老夫最近沒練武了，那就來動一動吧!");
 command("say 納命來!!");
 command("cmd holdup arrow with bow");
 command("kill"+ob->query("id"));
command("perform archery.ten_kee");
return 1;
}
int accept_fight(object ob)
{
command("say 那好吧!!老夫就來會會你");
command("cmd holdup arrow with bow");
return 1;
}
void heart_beat()
{
        if( random(4) < 1 ){
        if( is_fighting() ){
                if( query("kee") < query("eff_kee") )
                        command("exert recover");
        }
        else{
                if( query("eff_kee") < query("max_kee") )
                        command("exert heal");
        }
        }
     ::heart_beat();
}
void greeting(object ob)
{
if(ob->query("family/master_name")=="李廣")
{

if(!present("come",ob))
{
new(C_OBJ"/come")->move(ob);
command("hmm");
command("say 哨子呢?不見了?");
command("say 再給你一個。");
}
/*
if(!present("bow",ob))
{
new(C_OBJ"/bow-1")->move(ob);
command("hmm");
command("say 弓怎麼不見啦!!");
command("say 再給你一把，不要弄丟啦!");
}
*/
}
}

