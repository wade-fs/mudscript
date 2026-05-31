
inherit NPC;

void create()
{
        set_name("天邪虎", ({ "celestial tiger", "tiger" }) );
        set("long",

"這是一隻天邪派的靈獸「天邪虎」﹐火紅的毛皮上有著如白銀般的\n"
                "白紋﹐湛藍色的眼珠中散發出妖異的光芒。\n");

        set("race", "野獸");
        set("age", 160);
        set("attitude", "friendly");

        set("max_gin", 2000);
        set("max_kee", 3000);
        set("max_sen", 1000);

        set("str", 110);
        set("cor", 40);
        set("spi", 40);
        set("int", 60);
        set("limbs", ({ "頭部", "身體", "前腳", "後腿", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set_temp("apply/attack", 80);
        set_temp("apply/damage", 160);
        set_temp("apply/armor", 20);

        set("combat_exp", 1000000);
        set("score", 100000);
        setup();
}

