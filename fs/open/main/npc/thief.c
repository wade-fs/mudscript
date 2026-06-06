#include <ansi.h>

inherit NPC;

void create()
{
        set_name("迷路小賊", ({"little thief", "thief"}) );
        set("long","他是一個在森林裏迷路的小賊，在
稚氣未脫的臉上，流露出一股慌張
的表情。\n" );
        set("attitude", "peaceful");
        set("limbs", ({"頭部", "胸部", "腿部", "手臂"}) );
        set("age", 17);
	set("combat_exp", 6000);
        set("chat_chance", 10);
         set("chat_msg", ({
                 "小賊說道:這裏是哪兒啊?\n",
                 "小賊說道:我想我是迷路了.\n",}) );

        setup();

        add_money("coin", 70);
        carry_object("/obj/cloth")->wear();
        carry_object("/u/j/judy/ok/hat.c")->wear();
        carry_object("/u/j/judy/ok/dagger.c")->wield();
}
