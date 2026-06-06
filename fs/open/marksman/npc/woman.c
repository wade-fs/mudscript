#include <ansi.h>
inherit NPC;
void create()
{
        set_name("婦女", ({ "woman"}) );
        set("gender", "女性" );
        set("age",30);
        set("str", 17);
        set("cor",35);
        set("cps", 25);
        set("int", 15);
        set("long",
                "一位正在忙著幫她的老公工作.\n");
        set("combat_exp",8000);
set("max_kee",3000);
        set("attitude", "peaceful");

        set_skill("dodge", 7);
        set("chat_chance",20);
        set("chat_msg",({
        "婦女唉氣的說：唉!天天有洗不完的衣服。\n",
        }));
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 15);
}
int accept_kill(object ob)
{
 command("say 你以為女人是好欺負的嗎?");
 command("say 納命來!!");
 command("kill"+ob->query("id"));
return 1;
}
int accept_fight(object ob)
{
command("say 嗯!!就讓我來陪你玩玩幾招吧。");
return 1;
}

