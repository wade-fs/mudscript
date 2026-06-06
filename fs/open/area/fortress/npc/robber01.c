inherit NPC;
#include <ansi.h>
void create()
{
	set_name("強盜",({"robber"}));
	set("long","橫眉豎眼，臉上有數條刀巴，一臉兇相。\n");
	set("race", "人類");
	set("gender","男性");
	set("title",HIR + "極火山寨" + NOR);
        set("age",30);
        set("attitude","aggressive");
        set("combat_exp",150000);
        set("max_gin",2000);
        set("eff_gin",2000);
        set("gin",2000);
        set("max_kee",4000);
        set("eff_kee",4000);
        set("kee",4000);
        set("max_sen",2000);
        set("eff_sen",2000);
        set("sen",2000);
        set("max_force",20000);
        set("force",20000);
        set("force_factor",40);
        set("str",50);
        set("cor",40);
        set("int",10);
        set("spi",10);
        set("cps",50);
        set("per",10);
        set("con",40);
        set("kar",10);
        set_skill("force",80);
        set_skill("parry",80);
        set_skill("move",80);
        set_skill("dodge",80);
        set_skill("fireforce",80);
        set_skill("mogi-steps",80);
        set_skill("firestrike",80);
        map_skill("unarmed","firestrike");
        map_skill("parry","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","foreforce");
        set("functions/gold-fire/level",80);
        set("quest/gold-fire",1);
	set("quest/new_gold_fire",1);			
        set_temp("no_die_soon",1);			
        set_temp("apply/armor",80);			
        set_temp("apply/defense",80);			
        set_temp("apply/damage",80);			
        set_temp("apply/attack",80);
        set_temp("no_steal",1);
	setup();
        carry_object("/open/area/fortress/npc/obj/cloth01")->wear();
        carry_object("/open/area/fortress/npc/obj/pants01")->wear();
        carry_object("/open/area/fortress/npc/obj/boots01")->wear();
        carry_object("/open/area/fortress/npc/obj/head01")->wear();
        add_money("gold",10);
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
		if (!target->is_corpse() && target->is_character()&& random(100) < 50 )
                {
                	if ( !target->query_busy() ) { s=1+random(1); enemy[i]->start_busy(s); };		//定身
                	d=100+random(100);
			target->add("gin",-d); target->add("kee",-d);
                	target->add("sen",-d); target->add("force",-d);
                	message_vision(HIR + "$N衝向$n！又咬又打，猶如一條瘋狗！！$n受傷了！\n" + NOR,ob,target);
                	COMBAT_D->report_status(target);
                }
        }
::heart_beat(1);
}
