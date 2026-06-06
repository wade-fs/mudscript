inherit NPC;
#include <ansi.h>
void create()
{
    set_name("老闆娘", ({ " woman boss","boss","woman" }) );
    set("nickname",HIW"小氣巴拉"NOR);
    set("gender", "女性" );
    set("age",45);
    set("str",35);
    set("cor",45);
    set("cps",25);
    set("int",15);
    set("long","他是客棧的女老闆.\n");
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





