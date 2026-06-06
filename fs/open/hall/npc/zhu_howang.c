inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("朱火旺", ({ "zhu howang", "zhu", "wang"}));
        set("title", "縣衙二捕頭");
        set("nickname",YEL"屠牛師"NOR);
        set("gender", "男性" );
        set("age", 46);
        set("str", 50);
        set("cor", 50);
        set("cps", 50);
        set("int", 50);
        set("spi", 50);
        set("kar", 50);
        set("per", 50);
        set("con", 50);

        set("max_atman", 5000);
        set("max_force", 5000);
        set("max_mana", 5000);
        set("atman", 5000);
        set("force", 5000);
        set("mana", 5000);
        set("force_factor", 5);

        set("long", @LONG
一位身材矮小的男子，眼中透著隱隱的殺氣，在他的身邊使你感到
很不自在。據說他曾為了追一個江洋大盜，
LONG);

	set("combat_exp",172805);
        set("score", 130000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        "嘿嘿....憑你這兩下子!!只有見閻王的份!!\n",
        "不知天高地厚的小子!!受死吧!!\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("literate", 90);

        set("inquiry", ([
                "機器人" : "哼!! 誰被我抓到是機器人的話, 立斬!!",
                "accuse" : "想緝捕機器人的話, 請先到門口擊鼓申冤(accuse)。",
        ]) );

        setup();
}
