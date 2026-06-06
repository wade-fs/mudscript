// guard.c

#include <ansi.h>

inherit NPC;
void create()
{
	set_name("婦女", ({ "woman" }) );
        set("gender", "女性" );
        set("age",35);
        set("str", 17);
        set("cor",35);
	set("cps", 25);
	set("int", 15);
	set("long",
                "一位普通的婦女.\n");
	set("combat_exp",300);
	set("attitude", "peaceful");
/*
        set("chat_chance", 30);
        set("chat_msg", ({
             "婦女說: 客棧老闆每晚都在洗地板,不知到在洗甚麼?\n",
             "婦女說: 貪財小劍童身上似忽有些密秘.\n",
             "婦女說: 遼倒劍士每晚都對著一本書練武\n",
             (: "random_move" :),
        }) );
*/
	setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 15);
}
