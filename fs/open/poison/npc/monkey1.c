inherit NPC;

void create()
{
        set_name("大猴子", ({ "big monkey","monkey" }) );
        set("race", "野獸");
        set("age", 5);
        set("long", "一隻大猴子.\n");
        set("str", 35);
        set("cor", 45);
        set("max_kee",1000);
        set("kee",1000);
        set("limbs", ({ "利牙", "身體", "前爪" , "後爪" , "尾巴" }) );
        set("verbs", ({ "bite"}));
        set("combat_exp",100000);
        set_temp("apply/armor", 40);
        set_temp("apply/attack", 60);
        set_skill("dodge",70);
        set("chat_chance",10);
        set("chat_msg",({
                "猴子抓抓屁股 ,覺得很舒服 .\n",
                }));
        setup();

}
