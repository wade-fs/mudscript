inherit NPC;
void create()
{
    set_name("小女孩",({"cute girl","girl"}) );
    set("gender", "女性");
    set("age",25);
    set("attitude", "peaceful");
    set("long","奇墓派輩份最低的小妹，通常是負責門派內打掃、準備三餐\的工作。\n");
    set("kee",3600);
    set("force",5000);
    set("max_force",5000);
    set("max_kee",3600);
    set("force_factor",10);
    set("combat_exp",1300000);
    set_skill("sword",120);
    set_skill("move",500);
    set_skill("dodge",500);
    set_skill("mogi-steps",500);
    map_skill("dodge","mogi-steps");
    map_skill("move","mogi-steps");
    set_skill("mogi-strike7",100);
    map_skill("parry","mogi-strike7");
    map_skill("sword","mogi-strike7");
    set("chat_chance", 1);
    set("chat_msg", ({
"小女孩自言自語說道：我師父說我們必須與原真教那些人保持距離。",
}));
    setup();
carry_object("/open/hall/npc/obj/redsword")->wield();
add_money("gold",5);
create_family("奇墓派",63,"第子");
}
