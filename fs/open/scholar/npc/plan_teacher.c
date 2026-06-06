#include <ansi.h>
inherit NPC;

void create()
{
        set_name("萬計藏",({"plan teacher","teacher"}));
        set("title","謀略之星");
        set("gender","男性");
        set("race", "人類");
        set("age", 42);
        set("long", "此人乃儒門授業之人,負責教育儒門弟子計謀.\n");
        set("str", 30);
        set("family/family_name","儒門");
        set("class","scholar");
set("max_kee",1500);
set("kee",1500);
        set("max_force", 2000);
        set("force", 2000);
        set_skill("parry",80);
        set("combat_exp",350000);
        set_skill("knowpen", 100);
        set_skill("stabber", 60);
        set_skill("force",80);
        set_skill("winter-steps",70);
        set_skill("dodge",70);
        map_skill("stabber","knowpen");
        map_skill("parry","knowpen");
        map_skill("dodge","winter-steps");
        set_skill("plan",80);
        set_skill("god-plan",80);
        map_skill("plan","god-plan");
        set("force_factor", 10);
set("chat_chance_combat",90);
        set("chat_msg_combat",({
        (: perform_action,"plan.lock-link" :)
          }));
        setup();
        add_money("gold",10);
     carry_object("/open/scholar/obj/pen")->wield();
}

