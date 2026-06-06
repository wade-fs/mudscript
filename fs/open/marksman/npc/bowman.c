inherit NPC;
#include <ansi.h>
#include "marksman.h"
void create()
{
        set_name("初級弓箭手", ({ "bowman" }) );
set("class","marksman");
create_family("射日派",4,"門生");
        set("gender", "男性" );
        set("age", 25);
        set("long", "一位正在努力的想要把弓箭練好的生手。\n");
set("combat_exp",50000);
set("max_kee",800);
        set("max_force",500);
set_skill("dodge",50);
set_skill("parry",50);
set_skill("archery",50);
set_skill("god-shooting",30);
set_skill("rain-steps",50);
map_skill("parry","rain-steps");
map_skill("force","iceforce");
set_skill("iceforce",50);
        map_skill("archery","god-shooting");
        set_temp("apply/attack",10);
        set_temp("apply/dodge",10);
        set("force_factor",5);
        set("chat_msg",({
        "初級弓箭手努力的說著：我一定會把李廣師父教我的弓箭努力學習。 ",
        }));
          setup();
carry_object(C_OBJ"/bow-1")->wield();
carry_object(C_OBJ"/arrow-1");
carry_object(C_OBJ"/book");
}
int accept_kill(object ob)
{
 command("say 你竟敢動上我的頭上來，你想必是活的不耐煩了!");
 command("say 納命來!!");
command("cmd holdup arrow with bow");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 好吧!!我就陪你玩玩。");
command("cmd holdup arrow with bow");
return 1;
}


