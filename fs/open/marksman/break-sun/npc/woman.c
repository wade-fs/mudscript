#include <ansi.h>

inherit NPC;
void create()
{
        set_name("婦人", ({ "woman" }) );
        set("gender", "女性" );
        set("age",35);
        set("str", 17);
        set("cor",35);
        set("cps", 25);
        set("int", 15);
        set("long",
                "隸屬東夷族部落，世代居住於炎日村的普通婦女。\n");
        set("combat_exp",1500);
        set("attitude", "peaceful");

        set("chat_chance", 40);
	    set("chat_msg_combat",({
        "婦人說: 天氣實在太熱了，食物很難保存，這樣煮飯的人會很困擾耶...\n",
        }));

        set_skill("dodge", 15);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("coin", 25);
                
}
