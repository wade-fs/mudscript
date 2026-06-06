inherit NPC;
#include <ansi.h>
void create()
{
    set_name("邱迪方", ({ "boss chu","boss","chu" }) );
    set("nickname",HIY + "夠摳" + NOR);
    set("gender", "男性" );
    set("age",45);
    set("str",35);
    set("cor",45);
    set("cps",25);
    set("int",15);
    set("long","他是老闆, 不過做人實在是有夠摳門的.\n");
    set("combat_exp",3000);
    set("attitude", "peaceful");
    set("chat_chance", 25);

    set_skill("parry", 25);
    set_skill("snow-martial",25);
    set_skill("dodge", 35);
    set_skill("unarmed", 45);
    map_skill("unarmed","snow-martial");
    setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();

 }      





