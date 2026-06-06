// buffalo.c by oda
// loto.c    by powell

inherit NPC;

void create()
{
        set_name("駱駝", ({ "Camel", "camel" }) );
        set("race", "野獸");
        set("age", 10);
        set("long", "這隻駱駝正優閒地躺在地上, 咀嚼著飼料。\n");

        set("str",25);
        set("con",20);
        set("max_gin",140);
        set("max_kee",240);
        set("max_sen", 100);

        set("limbs", ({ "身體", "頭部", "前腳", "後腿", }) );
        set("verbs",({"hoof","bite"}) );

        set("combat_exp", 250);

        setup();
}
