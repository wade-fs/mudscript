#include <command.h>
 
inherit NPC;
 
void create()
{
    set_name("園丁",({"gardener"}));
    set("gender", "男性");
    set("age",68);
    set("attitude","peaceful");
    set("long",@LONG

	聖火教的教徒,!!負責飼樣門主所帶回來的奇異野獸.

LONG);
 
    set("combat_exp",2000);
    set("str",30);
    set("con",25);
    set("int",30);
    set("per",30);
    set("cps",30);
    set("kar",20);
    set("max_kee",310);
    set("kee",310);
    set("limbs",({"頭","手","腳","背","腹","腰"}));
    set_skill("universe",5);
    set_skill("force",20);
    set_skill("superforce",20);
    set_skill("move",20);
    set_skill("shift-steps",20);
    set_skill("unarmed",20);
    set_skill("parry",20);
    set_skill("dodge",20);
    set("chat_chance",30);   
     set("chat_msg", ({
     "老人說: 這個花園是教主吩咐我照顧的!!很恐怖嗎??不會啦!!\n",
             "老人說: 教主很喜歡到這裡來練功\喔!!\n",
             "老人說: 常常會聽到類似石頭搬動的聲音!!不曉得是為什麼??\n",
        }) );
 
    setup();
    add_money("silver",1);
    carry_object("/open/prayer/obj/communion-cloth")->wear();

}
