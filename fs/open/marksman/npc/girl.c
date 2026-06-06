#include <ansi.h>
#include "/open/open.h"

inherit NPC;
void create()
{
        set_name("小女孩", ({ "girl" }) );
        set("gender", "女性" );
        set("age",9);
        set("long",
                "一位長得天真可愛的小女孩。\n");
        set("combat_exp",2500);
        set("attitude", "peaceful");
set("max_kee",4500);
        set("chat_chance", 30);
        set("chat_msg", ({
        "小女孩天真無邪在那裡跟其他小朋友玩捉迷藏。\n",
        }) );
        setup();
        add_money("coin", 10);
        carry_object("/obj/cloth")->wear();
}
int accept_kill(object ob)
{
 command("cry");
 command("say 爸爸!媽媽!你們在那裏!大哥哥，大姐姐要殺我!!!");
 command("holdwith arrow");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 好吧!!我們就在這裏玩吧。");
return 1;
}
