#include <ansi.h>

inherit NPC;
void create()
{
        set_name("新進弟子", ({ "new man","man"}));
        set("gender", "男性" );
        set("age", 20);
        set("str", 25);
        set("cor", 45);
        set("cps", 25);
        set("int", 30);
        set("long",
                "剛加入儒門的儒生, 也是儒門的新進弟子。\n");
        set("combat_exp",8000);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: command ("sigh") :),
                (: command ("say 床前明月光....疑似地上霜...."):),
                (: command ("say 舉頭望明月....低頭思故鄉....") :),
        }) );
        set_skill("parry", 70);
        set_skill("unarmed", 70);
        set_skill("dodge", 40);
        set_skill("winter-steps", 40);
        map_skill("dodge","winter-steps");
        setup();
        add_money("silver",30);
        carry_object("/obj/cloth")->wear();
}

