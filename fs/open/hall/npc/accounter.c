inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
set_name("神算子", ({ "accounter"}));
        set("title", "衙門師爺");
        set("gender", "男性" );
        set("nickname",HIY"九面玲瓏"NOR);
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

        set("long",
        "人稱黑臉包公的就是他, 據說他斷案如神, 公私分明。所以這裡的百姓\n"
        "都很尊敬他。也因為他的豐功\偉業, 皇上特賜其一柄尚方寶劍。\n");


	set("combat_exp", 1658290);
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
     carry_object(__DIR__"obj/o_cloth")->wear();
}
