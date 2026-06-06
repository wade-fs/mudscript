inherit NPC;
#include <ansi.h>
#include "log/log.c"

void create()
{
	set_name("火神舞",({"firedancer"}));
	set("long","極火山寨的大寨主，極火功\無人能及，傳說此技巧是焚天魔王直接傳授的。\n");
	set("race", "人類");
	set("gender","女性");
	set("title",HIR + "蒙面俠女" + NOR);
        set("age",40);
        set("attitude","heroism");
        set("combat_exp",50000000);
        set("max_gin",200000);
        set("eff_gin",200000);
        set("gin",200000);
        set("max_kee",400000);
        set("eff_kee",400000);
        set("kee",400000);
        set("max_sen",200000);
        set("eff_sen",200000);
        set("sen",200000);
        set("max_force",3000000);
        set("force",3000000);
        set("force_factor",600);
        set("str",500);
        set("cor",500);
        set("int",500);
        set("spi",500);
        set("cps",500);
        set("per",500);
        set("con",500);
        set("kar",500);
        set_skill("force",2000);
        set_skill("parry",2000);
        set_skill("move",2000);
        set_skill("dodge",2000);
        set_skill("fireforce",2000);
        set_skill("mogi-steps",2000);
        set_skill("firestrike",2000);
        map_skill("unarmed","firestrike");
        map_skill("parry","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","foreforce");
        set("functions/gold-fire/level",2000);
        set("quest/gold-fire",1);
	set("quest/new_gold_fire",1);			
        set_temp("no_die_soon",1);			
        set_temp("apply/armor",2000);			
        set_temp("apply/defense",2000);			
        set_temp("apply/damage",2000);			
        set_temp("apply/attack",2000);
	setup();
}
