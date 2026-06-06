#include <ansi.h>
#include "/open/open.h"

inherit NPC;
void create()
{
        set_name("老人", ({ "old man","old","man" }) );
        set("gender", "男性" );
        set("age",60);
        set("str",35);
        set("cor",35);
        set("cps", 25);
        set("int", 15);
        set("long",
                "一位白頭的老頭子，整天在這裡到處走來走去。\n");
        set("combat_exp",5000);
set("max_kee",4000);
        set("attitude", "peaceful");
        set("chat_chance", 30);
        set("chat_msg", ({
      "老爺爺唉氣的說：唉!難道要以後都要繼續吃藥過日子嗎?\n",
        }) );
        set_skill("parry", 20);
        set_skill("dodge", 7);
        setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();
        carry_object(COMMON_OBJ"pill");
}
int accept_kill(object ob)
{
 command("say 你連我這個老人家都不放過，真是罪惡!");
 command("say 救命呀!!");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 偶不行了!我都這麼老了如何陪你玩。");
return 0;
}
