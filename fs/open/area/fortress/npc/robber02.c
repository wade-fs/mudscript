inherit NPC;
#include <ansi.h>

void create()
{
	set_name("強盜",({"robber"}));
	set("long","橫眉豎眼，臉上有數條刀巴，一臉兇相。\n");
	set("race", "人類");
	set("gender","男性");
	set("title",HIR"極火山寨"NOR);
        set("age",40);
        set("attitude","aggressive");
        set("combat_exp",500000);
        set("max_gin",8000);
        set("eff_gin",8000);
        set("gin",8000);
        set("max_kee",10000);
        set("eff_kee",10000);
        set("kee",10000);
        set("max_sen",8000);
        set("eff_sen",8000);
        set("sen",8000);
        set("max_force",80000);
        set("force",80000);
        set("force_factor",50);
        set("str",50);
        set("cor",50);
        set("int",10);
        set("spi",10);
        set("cps",50);
        set("per",10);
        set("con",50);
        set("kar",10);
        set_skill("force",120);
        set_skill("parry",120);
        set_skill("move",120);
        set_skill("dodge",120);
        set_skill("fireforce",120);
        set_skill("mogi-steps",120);
        set_skill("firestrike",120);
        map_skill("unarmed","firestrike");
        map_skill("parry","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","foreforce");
        set("functions/gold-fire/level",120);
        set("quest/gold-fire",1);
	set("quest/new_gold_fire",1);			
        set_temp("no_die_soon",1);			
        set_temp("apply/armor",120);			
        set_temp("apply/defense",120);			
        set_temp("apply/damage",120);			
        set_temp("apply/attack",120);
        set_temp("no_steal",1);
	setup();
        carry_object("/open/area/fortress/npc/obj/cloth01")->wear();
        carry_object("/open/area/fortress/npc/obj/pants01")->wear();
        carry_object("/open/area/fortress/npc/obj/boots01")->wear();
        carry_object("/open/area/fortress/npc/obj/head01")->wear();
        add_money("gold",15);
}

void heart_beat()
{
object ob,target;
int i,n,d,s;
        ob = this_object();
//  攻擊
       	target=ob->query_temp("last_opponent");
        if (ob->is_fighting() && target && !ob->is_unconcious() && environment(this_object())==environment(target)) 
        {
		if (!target->is_corpse() && target->is_character()&& random(100) < 80 )
                {
                	if ( !target->query_busy() ) { s=1+random(2); enemy[i]->start_busy(s); };		//定身
                	d=100+random(100);
			target->add("gin",-d); target->add("kee",-d);
                	target->add("sen",-d); target->add("force",-d);
                	message_vision(HIR"$N張開血盆大口，見人就咬！$n來不及閃躲，受傷了！\n"NOR,ob,target);
                	COMBAT_D->report_status(target);
                	target->add("gin",-d); target->add("kee",-d);
                	target->add("sen",-d); target->add("force",-d);
                	COMBAT_D->report_status(target);
                }
        }
::heart_beat(1);
}
