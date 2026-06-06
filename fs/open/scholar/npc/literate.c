#include <ansi.h>
inherit NPC;

void create()
{
        set_name("萬卷書",({"literate teacher","teacher"}));
        set("title","智慧之星");
        set("gender","男性");
        set("race", "人類");
        set("family/family_name","儒門");
        set("age", 47);
        set("long", "此人乃儒門授業之人,負責教育儒門弟子智慧.\n");
        set("str", 30);
set("max_kee",1000);
set("kee",1000);
        set("max_force", 2000);
        set("force", 2000);
        set_skill("parry",80);
        set("combat_exp",300000);
        set_skill("knowpen", 100);
        set_skill("stabber", 60);
        set_skill("force",80);
        set_skill("winter-steps",70);
        set_skill("dodge",70);
        map_skill("stabber","knowpen");
        map_skill("parry","knowpen");
        map_skill("dodge","winter-steps");
        set("force_factor", 10);
        set("chat_chance_combat",15);
        set("chat_msg_combat",({
           (: perform_action, "stabber.movedown" :)
          }));
        setup();
        add_money("gold",10);
        carry_object("/open/scholar/obj/pen")->wield();
}

