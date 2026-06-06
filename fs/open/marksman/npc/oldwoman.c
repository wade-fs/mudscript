#include <ansi.h>

inherit NPC;
void create()
{
        set_name("老婦女", ({ "old woman","old","woman" }) );
        set("gender", "女性" );
        set("age",60);
        set("str", 20);
        set("cor",30);
        set("cps", 30);
        set("int", 20);
        set("long",
                "一位年歲以高的老婦女.\n");
        set("combat_exp",6000);
set("max_kee",3500);
        set("attitude", "peaceful");
        set_skill("dodge", 7);
        set("chat_chance", 30);
        set("chat_msg", ({
        "老婦女輕輕的問：小傢伙，要不要吃點東西呀?\n",
        }) );

        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 15);
}
int accept_kill(object ob)
{
 command("say 別以為老人家是好欺負的，看我的厲害");
 command("say 領死吧!!");
 command("holdwith arrow");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("smile");
command("say 不行，最近風濕很厲害，無法動粗。");
return 0;
}
