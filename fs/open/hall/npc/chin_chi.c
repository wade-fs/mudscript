
inherit NPC;
#include <ansi.h>

void create()
{
set_name("秦  忌", ({ "chin chi", "chin", "chi" }));
        set("title", "縣衙三捕頭");
        set("nickname","追魂槍");
        set("age", 23);
        set("str", 25);
        set("cor", 20);
        set("cps", 20);
        set("int", 20);
        set("spi", 20);
        set("kar", 24);
        set("per", 20);
        set("con", 30);

        set("max_force", 2000);
        set("force", 2000);
        set("force_factor", 3);

        set("long", @LONG
    一位身材矮小的男子，眼中透著隱隱的殺氣，在他的身邊使你感到
很不自在。據說他曾為了追一個江洋大盜，隻身殺進黑風寨，在一片腥
風血雨下宰了那大盜，造成武林一時的轟動!!
LONG);
        set("combat_exp", 150000);
        set("score",  3000);

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        "嘿嘿....!!  乖乖地餵我的槍吧!!\n",
        "看『追魂六式』!!  受死吧!!\n"
        }) );

        set_skill("unarmed", 20);
        set_skill("force",  60);
        set_skill("parry",  40);
        set_skill("dodge",  60);
        set_skill("sword",  30);
        set_skill("literate", 20);

        set("inquiry", ([
                "追魂槍" : "嘿嘿!!想要我的槍嗎?!拿你的命來換吧!!",
        ]) );

        setup();
        carry_object(__DIR__"obj/g_lance")->wield();
        carry_object(__DIR__"obj/b_suit")->wear();
}
