inherit NPC;
#include <ansi.h>

void create()
{
        set_name("野人",({"wild man","man"}));
        set("long","最低階層的野人哨兵。\n");
        set("race","野獸");
        set("attitude","aggressive");
        set("limbs", ({ "頭部", "身體", "手臂" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp",400000);
        set("max_gin",5000);
        set("max_kee",10000);
        set("max_sen",5000);
        set("max_force",10000);
        set("gin",5000);
        set("kee",10000);
        set("sen",5000);
        set("force",10000);
        set("chat_chance",20);
        set_temp("apply/armor", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set_skill("dodge",200);
        set_skill("move",200);
        set_skill("unarmed",100);
        set_skill("force",200);
        set("force_factor",30);
	apply_condition("open-war01",1);
	set("must_heart_beat",1);
        setup();
}
