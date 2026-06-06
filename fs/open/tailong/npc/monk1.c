inherit NPC;
void create()
{
        set_name("小僧",({"monk"}));
        set("gender","男性");
        set("class","scholar");
        set("combat_exp", 1000);
        set("attitude","peaceful");
        set("age",15);
        set("chat_chance", 50);
        set("chat_msg", ({
        "小僧說道: 施主您好,這裡是崇聖寺。\n",
        "小僧說道: 施主,如果您有事要找方丈,可以入內請問接待師兄。\n",
        }));
        set("inquiry", ([
        "崇聖寺" : "這裡就是崇聖寺,不過一般人都稱這裡為天龍寺",
"天龍寺" : "這裡就是了!",
        ]));
        set("force",150);
        set("max_force",150);
        set("max_kee",300);
        set("kee",300);
        set("force_factor", 1);
        set_skill("force",20);
        set_skill("unarmed",30);
        set_temp("apply/dodge",30);
        setup();
      add_money("silver",1);
}
