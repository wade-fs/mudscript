inherit NPC;
void create()
{
    set_name("女丐婦", ({ " woman beggar","beggar","woman" }) );
    set("gender", "女性" );
    set("age",45);
    set("str",35);
    set("cor",45);
    set("cps",25);
    set("int",15);
    set("long","他是一個身穿破爛衣裳的乞丐.\n");
    set("combat_exp",3000);
    set("attitude", "peaceful");
    set("chat_chance", 25);

    set_skill("parry", 25);
    set_skill("dodge", 35);
    set_skill("unarmed", 45);
    setup();
        add_money("coin", 25);
        carry_object("/obj/cloth")->wear();

 }      





