
inherit NPC;

void create()
{
        set_name("水煙閣司事", ({ "waterfog watcher", "watcher" }) );
        set("gender", "男性");
        set("age", 34);
        set("long", "這個人看起來十分和藹可親﹐一雙眼睛炯炯有神。\n");

        set("attitude", "peaceful");
        set("combat_exp", 60000);
        set("score", 15000);

        set("str", 25);
        set("cor", 23);
        set("cps", 23);
        set("con", 27);

        set("force", 1100);
        set("max_force", 1100);
        set("force_factor", 5);

        set("chat_chance_combat", 40);
        set("chat_msg_combat", ({
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set_skill("force", 70);
        set_skill("unarmed", 70);
        set_skill("parry", 60);
        set_skill("dodge", 65);

        set_skill("celestial", 70);
        set_skill("celestrike", 60);

        map_skill("force", "celestial");
        map_skill("unarmed", "celestrike");

        setup();
}

