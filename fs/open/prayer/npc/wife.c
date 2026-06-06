
#include <command.h>

inherit NPC;

void create()
{
    set_name("夫人",({"communion wife","communion","wife"}));
    set("title", "教主");
    set("gender", "女性");
    set("age",55);
    set("attitude","peaceful");
    set("long",@LONG

  其本身乃是波斯人,到中原來是為了波斯拜火教的聖火令,早年曾在魔刀
  的門下習武.自從尋獲聖火令之後,就要回波斯覆命,但在回波斯途中,巧
  遇聖火教教皇,但與聖皇墜入情網後,便背棄師門,遠走西域!並幫助聖火
  教皇創建[聖火奇功].

LONG);

    set("combat_exp",1000000);
    set("str",30);
    set("con",20);
    set("int",30);
    set("per",40);
    set("cps",30);
    set("kar",30);
    set("force",2000);
    set("max_force",2000);
	set("max_gin",3900);
	set("max_sen",3900);
    set("force_factor",10);
    set("max_kee",3500);
    set("kee",3500);
    set("limbs",({"頭","手","腳","背","腹","腰"})); 
    set_skill("dragon-blade",120);
    set_skill("haoforce",100);
    set_skill("blade",100);
    set_skill("parry",100);
    set_skill("dodge",100); 
    map_skill("blade","dragon-blade");
    map_skill("parry","dragon-blade");
    map_skill("force","haoforce");
    set("chat_chance_combat",100);
    set("chat_msg_combat",({
    (: perform_action,"blade.power-dest" :),}));

    setup();
    add_money("gold",10);
    carry_object("/open/gblade/obj/moon-blade")->wield();
    carry_object("/open/prayer/obj/girl-cloth")->wear();
    carry_object("/open/prayer/obj/girl-topknot")->wear();
    carry_object("/open/prayer/obj/girl-wrists")->wear();
    carry_object("/open/prayer/obj/girl-neck")->wear();
}

