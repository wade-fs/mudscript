
//j_master.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("筱孰落", ({"jail master","master"}));
        set("title", "牢房統領");
        set("nickname", "一錢一命");
        set("long",@LONG
    一個身著短衫的彪形巨漢，身上配著一把亮閃閃的鋼刀，好像
會兩下子的樣子!!他是牢房的頭頭，你可以問問看贖人的消息。
LONG);
        set("gender", "男性");

        set("age", 35);
        set("attitude", "peaceful");
        set("score", 200000);
        set("combat_exp", 70000);

        set("str", 30);
        set("max_gin", 2000);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("inquiry", ([
            "贖人" : "要贖人!!??沒問題...除了死牢裡的我沒辦法...其他一律一百兩!!不二價!!嘿嘿..",
        ]) );

        setup();

        set("chat_chance", 5);
        set("chat_msg", ({
            "沒啥事就快滾!!老子很忙....沒空跟你們這些龜兒子瞎扯!!\n",
            "啥事!!快說!!\n",
        }));
}

