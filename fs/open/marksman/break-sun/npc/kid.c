#include <ansi.h>

inherit NPC;
void create()
{
        set_name("小孩", ({ "kid" }) );
        set("gender", "男性" );
        set("age",12);
        set("str", 17);
        set("cor",35);
        set("cps", 25);
        set("int", 15);
        set("long",
                "隸屬東夷族部落，世代居住於炎日村的普通小孩。\n");
        set("combat_exp",1000);
        set("attitude", "peaceful");

        set("chat_chance", 40);
	    set("chat_msg_combat",({
        "小孩無精打采的說: 太陽好大喔，天氣熱得我都不想出去玩了...\n",
        }));


        set_skill("dodge", 10);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 15);
                
}
