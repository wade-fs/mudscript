


// guard.c

#include <ansi.h>

inherit NPC;
void create()
{
        set_name("農夫", ({ "farmer" }) );
        set("gender", "男性" );
        set("age",65);
        set("str", 27);
        set("cor",35);
        set("cps", 25);
        set("int", 15);
        set("long",
                "一位久居於此的老農夫.\n");
        set("combat_exp",120000);
        set("attitude", "peaceful");
        set("chat_chance", 35);
        set("chat_msg", ({
             "農夫說: 有位姓顏的劍客曾經來過這, ,像是在找人!!\n",
             "農夫說: 島上那座火山 ,聽說住了神龜呀!! 不知道是真是假 .\n",
             "農夫說: 傳聞神龜怕雷響 ,所以從來沒有出現過!!\n",
             (: "random_move" :),
        }) );
        set_skill("dodge", 120);
        setup();
        carry_object("/obj/cloth")->wear();
        add_money("gold", 5);
}


