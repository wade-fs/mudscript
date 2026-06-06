inherit NPC;
void create()
{
        set_name("王語嫣",({"wang yu yan","wang","yan"}));
        set("title","武學圖書館");
        set("long","她可是精通百家武學的奇女子,舉凡各家武學,她都能如數家珍的說
出來
C\n");
        set("gender","女性");
        set("combat_exp", 1000000);
        set("attitude","friendly");
        set("age",22);
        set("force",5000);
        set("max_force",5000);
        set("kee",1000);
        set("max_kee",1000);
        set("force_factor",30);
        setup();
        add_money("gold",100);
}
