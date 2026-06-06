
//j_guard.c
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("監牢守衛", ({"jail guard","guard"}));
        set("long",@LONG
    在你眼前的是一位全身肌肉糾結的男子，要和他打恐怕要付出相當
大的犧牲!!除非有十成的把握，否則建議你最好別試....從他的眼神中
，你能夠看出他似乎是個很喜歡錢 (money)的傢伙!!
LONG);
        set("gender", "男性");

        set("age", 23);
        set("attitude", "peaceful");
        set("score", 200000);
        set("combat_exp", 50000);

        set("str", 30);
        set("max_gin", 2000);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
        set("inquiry", ([
            "探監" : "嘿嘿....想看看親人是吧??拿個五兩銀子出來...我再考慮看看..嘿嘿...",
        ]) );

        setup();

        set("chat_chance", 15);
        set("chat_msg", ({
            "幹啥!!!沒事不要到這裡閒逛!!快滾!!\n",
            "你也想進去坐坐是吧!!免費的牢飯要不要試試!!嘿嘿..\n",
        }));
}

