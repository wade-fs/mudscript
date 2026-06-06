// rewrite from old_buffalo.c by oda
// brownhorse.c by powell

inherit NPC;

void create()
{
        set_name("棕色馬", ({ "Brown horse", "horse" }) );
        set("race", "野獸");
        set("age", 20);
        set("long", 
            "一匹健壯的棕色馬, 可以禁的住長途的跋涉, 是代步的好工具。\n");

        set("str", 20);
        set("cor", 25);
        set("max_gin", 220);
        set("max_kee", 210);
        set("max_sen", 200);

        set("limbs", ({ "身體", "頭部", "前腳", "後腿", "尾巴" }) );
        set("verbs", ({ "hoof", "bite"  }) );

        set("chat_chance", 3);
        set("chat_msg", ({
                "粽色馬跺過來又跺過去, 一副精神亦亦的樣子。\n"}) );
                
        set("combat_exp",200);

        setup();
}
