#include <ansi.h>
#include "/open/open.h"

inherit NPC;
void create()
{
        set_name("小男孩", ({ "boy" }) );
        set("gender", "男性" );
        set("age",15);
        set("str",20);
        set("cor",20);
        set("cps", 20);
        set("int", 10);
        set("long",
                "可愛天真的小男孩，正在努力的玩耍中。\n");
        set("combat_exp",2000);
set("max_kee",5000);
        set("attitude", "peaceful");
        set("chat_chance", 30);
        set("chat_msg", ({
        "小男孩天真無邪的說: 大哥哥，大姐姐，你們要不要陪我玩遊戲嗎？\n",
      "小男孩正在和鄰居的小妹妹努力的玩耍中。\n",
        }) );
        setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();

}
int accept_kill(object ob)
{
 command("say 救命呀，大哥哥，大姐姐，要殺人呀!");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 大哥哥，大姐姐，都不陪我玩，我才懶得理你們。");
return 0;
}
