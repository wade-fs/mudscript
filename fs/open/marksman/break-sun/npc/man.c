#include <ansi.h>

inherit NPC;
void create()
{
        set_name("鎮民", ({ "man" }) );
        set("gender", "男性" );
        set("age",35);
        set("str", 17);
        set("cor",35);
        set("cps", 25);
        set("int", 15);
        set("long",
                "隸屬東夷族部落，世代居住於炎日村的普通鎮民。\n");
        set("combat_exp",2500);
        set("attitude", "peaceful");

        set("chat_chance", 40);
	    set("chat_msg_combat",({
        "鎮民說: 天氣再這麼熱下去啊，我們都快曬成人乾嘍...\n",
        }));

        set_skill("dodge", 25);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 55);
                
}
