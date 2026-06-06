#include <ansi.h>

inherit NPC;

void create()
{
        set_name("衙門捕快", ({ "hall soldier", "hall", "soldier" }) );
        set("long",@LONG
這是個衙門捕快﹐也就是衙門的基層，論功夫而言～實在是不怎麼
樣，不過起來他們人數眾多，似乎有點跋扈、不可一世的樣子～讓人想
教訓他們一下。
LONG);
        set("attitude", "peaceful");
        set("pursuer", 1);

        set("str", 17);
        set("cor", 16);
        set("cps", 15);

        set("combat_exp", 8000);

        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                "捕快喝道：找死!!\n",
                "捕快喝道：他媽的!!去死吧!!\n"
        }) );

        set_skill("unarmed", 25);
        set_skill("parry", 30);
        set_skill("dodge", 30);
        set_skill("move",  10);

        setup();

}
