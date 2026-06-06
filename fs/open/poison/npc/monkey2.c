inherit NPC;

void create()
{
        set_name("小猴子", ({ "small monkey","monkey" }) );
        set("race", "野獸");
        set("age", 5);
        set("long", "一隻小猴子.\n");
        set("str", 35);
        set("cor", 45);
        set("limbs", ({ "利牙", "身體", "前爪" , "後爪" , "尾巴" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp",2000);
        set_temp("apply/armor", 40);
        set_temp("apply/attack", 60);
        set_skill("dodge",60);
        set("chat_chance",10);
        set("chat_msg",({
                "猴子抓抓屁股 ,覺得很舒服 .\n",
                }));
        setup();

}
