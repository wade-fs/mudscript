inherit NPC;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        set_name("八爪章魚",({ "octopus" }) );
        set("long","生長在深溝裡面的大章魚!!\n");
        set("race", "野獸");
        set("age", 1240);
        set("max_gin", 10000);
        set("max_kee", 10000);
        set("max_sen", 10000);
        set("max_force", 50000);
        set("force", 50000);
        set("force_factor",0);
        set("bellicosity",10000);
        set("limbs", ({"頭部", "身體"}) );
        set("verbs", ({ "claw","bite" }) );
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor",  100);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",500);
        set("combat_exp", 4000000);
        setup();
}

