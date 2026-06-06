inherit NPC;
#include <ansi.h>
#include "marksman.h"
void create()
{
        set_name("張揚", ({ "chang yang","chang","yang" }) );
set("class","marksman");
create_family("射日派",3,"弟子");
        set("gender", "男性" );
        set("age", 40);
        set("long", "李廣身邊最貼身的護法之一。\n");
        set("nickname",HIY"左護法"NOR);
set("combat_exp",200000);
        set("max_force",1000);
	set("force",1000);
        set_skill("archery",85);
	set_skill("god-shooting",85);
	set_skill("force",50);
	set_skill("iceforce",50);
set_skill("dodge",80);
set_skill("parry",80);
set_skill("rain-steps",70);
        map_skill("parry","rain-steps");
        map_skill("archery","god-shooting");
	map_skill("dodge","rain-steps");
	map_skill("force","iceforce");
        set_temp("apply/attack",10);
        set_temp("apply/dodge",10);
        set("force_factor",5);
set("functions/ten_kee/level",65);
set("chat_chance_combat",10);
set("chat_msg_combat", ({
(: perform_action("archery.ten_kee") :),
}));
          setup();
carry_object(C_OBJ"/arrow-7");
carry_object(C_OBJ"/bow-7")->wield();
}
int accept_kill(object ob)
{
 command("say 真不知死活，沒有看清楚我是誰嗎?想殺我!");
 command("say 納命來!!");
command("cmd holdup arrow with bow");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 最近骨頭有一點散，我就陪你玩幾招當作運動吧。");
command("cmd holdup arrow with bow");
return 1;
}
