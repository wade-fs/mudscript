// trainee.c

inherit NPC;

void create()
{
        set_name("瀧山守尉", ({ "guard" }) );
        set("gender", "男性" );
        set("long", "這是從瀧山派中的弟子中所挑選出精英，用來看守牢房的。\n");
        set("combat_exp",250000);
        set("attitude","aggressive");
        set("age",35);
        set("force",800);
        set("max_gin",500);
        set("max_kee",1200);
        set("max_force",800);
        set("force_factor",15);
        set("str",30);
        set("cor", 30);
        set("per", 30);
         set("env/狂擊","YES");
        set("int", 30);
        set("cps", 20);
        set("con", 30);
        set("spi", 30);
        set("kar", 20);
        set_skill("lungshan", 80);
        set_skill("haoforce", 70);
        set_skill("henma-steps",70);
        set_skill("unarmed",80);
        set_skill("dodge",70);
        set_skill("parry",70);
        set_skill("move",70);
        set_skill("force",70);
        map_skill("unarmed", "lungshan");
        map_skill("parry","lungshan");
        map_skill("force", "haoforce");
        map_skill("dodge", "henma-steps");
        map_skill("move", "henma-steps");
        setup();
        carry_object("/open/wu/obj/silverfinger")->wield();
        add_money("gold", 10);
}

