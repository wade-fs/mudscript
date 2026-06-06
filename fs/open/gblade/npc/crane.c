inherit NPC;

void create()
{
        set_name("仙鶴", ({ "holy crane","crane" }) );
        set("race", "野獸");
        set("age", 3);
        set("long", "
一身雪白的羽翼，體態豐而不腴，嬌而不媚，顧盼之間顯得俗塵不染，翹
首之際分外靈動巧捷，或昂然而立，或翩然而趨，抑或展翅而翔，無不令
人神往。");
        set("str", 20);
        set("cor", 25);
        set("verbs", ({ "bite"}));
                set("limbs", ({ "頭部", "身體",  }) );
        set("combat_exp",1000);
        set_temp("apply/armor", 15);
        set_temp("apply/attack", 10);
        set_skill("dodge",20);
        setup();

}
