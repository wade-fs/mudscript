inherit NPC;
void create()
{
        set_name("紀嫣然",({"chi-yen ran ","ran",}));
        set("gender","女性");
        set("age",25);
        set("str",25);
        set("bellicosity", 100);
        set("title","石才女");
        set("long","一個有傾城之色的絕世美女 ,她正在梳著她那又黑又亮的秀髮 ,
不過 ,可別動她的歪腦筋喔 ,她可是一名數一數二的劍手喔 !\n");
        set("combat_exp",400000);
        set("max_kee",1200);
        set("kee",1200);
        set("max_force",1300);
        set("force",1300);
        set_skill("sword",90);
        set_skill("parry",40);
        set_skill("dodge",100);
        set_skill("force",60);
/*	沒這個 skill 吧!?	arthur
        set_skill("wusword",80);
*/
        set_skill("paull-steps",120);
        set_skill("dreamforce",80);
        map_skill("sword","wusword");
        map_skill("parry","wusword");
        map_skill("dodge","paull-steps");
        map_skill("force","dreamforce");
        
        set("chat_chance",10);
        set("chat_msg",({
                "紀嫣然吟道 : 絕對權力的絕對腐化 ...\n",
                "紀嫣然說 : 真是好句子 .\n",
                }));
        setup();
}

