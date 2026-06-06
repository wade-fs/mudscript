// 風行山寨
inherit NPC;
void create()
{
       set_name("小囉囉",({"soldier"}));
set("long","
他是山寨裡頭的小囉囉，奉大頭目的命令在這裡查看有沒有可疑的人物，沒事就喜
歡欺壓善良的老百姓，不過看起來好像也不怎麼樣，三兩下子就可以把他幹掉了吧。
\n");
        set("gender","男性");
        set("combat_exp",250000);
        set("attitude","peaceful");
        set("age",22);
        set("class","soldier");
        set("max_force", 700);
        set("force", 700);
        set("max_kee", 700);
        set("kee", 700);
        set_skill("unarmed",85);
        set_skill("dodge",65);
        set_skill("parry",45);
        set_skill("six-fingers",75);
        set_skill("linpo-steps",55);
        map_skill("unarmed","six-fingers");
        map_skill("parry","six-fingers");
        map_skill("dodge","linpo-steps");
        set("chat_chance",10);
        set("chat_msg",({
         (: this_object(),"random_move" :),
        }));
        setup();
        add_money("silver",5);
}

