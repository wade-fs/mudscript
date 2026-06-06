// rewrite from old_buffalo.c by oda
// blackhorse.c by powell

inherit NPC;

void create()
{
        set_name("黑馬", ({ "Black horse", "horse" }) );
        set("race", "野獸");
        set("age", 20);
        set("long", 
            "一匹雄糾糾的黑馬, 全身的毛黑的發亮, 看起來頗有千里馬的架勢。\n");


        set("str", 30);
        set("cor", 35);
        set("max_gin", 500);
        set("max_kee", 500);
        set("max_sen", 500);

        set("limbs", ({ "身體", "頭部", "前腳", "後腿", "尾巴" }) );
        set("verbs", ({ "hoof", "bite"  }) );

        set("chat_chance", 1);
        set("chat_msg", ({
                "黑馬抬頭嘶鳴一聲, 嚇了你一大跳。\n"}) );
                
        set("combat_exp",300);

        setup();
}
