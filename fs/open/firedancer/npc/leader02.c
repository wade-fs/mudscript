inherit NPC;
#include <ansi.h>
#include "log/log.c"
string do_steal();
void create()
{
	set_name("極火",({"huo wu cing","cing"}));
	set("long","極火山寨的大寨主，極火功\無人能及，傳說此技巧是焚天魔王直接傳授的。\n");
	set("race", "人類");
	set("gender","男性");
	set("title",HIR"極火山寨 大寨主"NOR);
	set("nickname",HIC"極火無敵"NOR);
        set("age",40);
        set("attitude","aggressive");
        set("combat_exp",1000000);
        set("max_gin",20000);
        set("eff_gin",20000);
        set("gin",20000);
        set("max_kee",40000);
        set("eff_kee",40000);
        set("kee",40000);
        set("max_sen",20000);
        set("eff_sen",20000);
        set("sen",20000);
        set("max_force",300000);
        set("force",300000);
        set("force_factor",60);
        set("str",50);
        set("cor",50);
        set("int",10);
        set("spi",10);
        set("cps",50);
        set("per",10);
        set("con",50);
        set("kar",10);
        set_skill("force",200);
        set_skill("parry",200);
        set_skill("move",200);
        set_skill("dodge",200);
        set_skill("fireforce",200);
        set_skill("mogi-steps",200);
        set_skill("firestrike",200);
        map_skill("unarmed","firestrike");
        map_skill("parry","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","foreforce");
        set("functions/gold-fire/level",200);
        set("quest/gold-fire",1);
	set("quest/new_gold_fire",1);			
        set_temp("no_die_soon",1);			
        set_temp("apply/armor",200);			
        set_temp("apply/defense",200);			
        set_temp("apply/damage",200);			
        set_temp("apply/attack",200);
        set_temp("no_steal",1);
        set("must_heart_beat",1);
        set("chat_chance_combat", 200);			//設定機率
        set("chat_msg_combat", ({			//將執行function
        (:do_steal:),
        }));
	setup();
        add_money("gold",100);
        carry_object("/open/area/fortress/npc/obj/cloth01")->wear();
        carry_object("/open/area/fortress/npc/obj/pants01")->wear();
        carry_object("/open/area/fortress/npc/obj/boots02")->wear();
        carry_object("/open/area/fortress/npc/obj/head01")->wear();
}

void heart_beat()
{
object ob,target;
int i,n,d,s,a;
        ob = this_object();
//  呼叫NPC
	if(!present("robber",environment(ob)) && random(100) < 50)
	{
		message_vision(HIR"$N大喊：人呢！一群飯桶死去哪去了！給我叫人來！\n$N這麼一呼，幾個小嘍嘍加入了戰局。\n\n"NOR,this_object());
		for(a=0;a<2;a++)
			new("/open/area/fortress/npc/robber02")->move(environment(ob));
	}
//  回復能力
        if ( ob->query("kee") < ob->query("max_kee") && random(100) < 80 ) {
	message_vision(HIY"$N一吞一吐，口與手中輪迴著一道紅色光圈。\n$N的氣色好多了。\n"NOR,ob);
        if ( ob->query_busy() ) ob->delete_busy();			//自動解除定身
        if ( ob->query("gin") < ob->query("max_gin") ) { ob->receive_curing("gin",1000); ob->receive_heal("gin",1000); };
        if ( ob->query("kee") < ob->query("max_kee") ) { ob->receive_curing("kee",1000); ob->receive_heal("kee",1000); };
        if ( ob->query("sen") < ob->query("max_sen") ) { ob->receive_curing("sen",1000); ob->receive_heal("sen",1000); };
        if ( ob->query("force") < ob->query("max_force") ) { ob->add("force",1000); };
	}
//  攻擊
       	target=ob->query_temp("last_opponent");
        if (ob->is_fighting() && !ob->is_unconcious() && target && environment(this_object())==environment(target)) 
        {
		if (!target->is_corpse() && target->is_character()&& random(100) < 90 )
                {
                	if ( !target->query_busy() ) { s=2+random(2); enemy[i]->start_busy(s); };		//定身
                	d=400+random(400);
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

string do_steal()
{
	object ob;
	mixed enemy,item;
	string style,cstyle;					//style錢的類型
	int i,j,money;
	ob = this_object();
	enemy = all_inventory(environment(ob));		//this_object()附近所有的objects
	i = sizeof(enemy);				//objects數量
	j=random(i);					//隨機找一個
	if(!enemy[j]->query_temp("no_steal",1) && enemy[j]->is_character() && !enemy[j]->is_corpse())		//物件沒有設定no_steal，不是死物，是角色，則偷錢
	{
		switch(random(5))			//選擇要偷的種類
		{
			case 0:
				style="diamond";
				cstyle="鑽石";
				break;
			case 1:
				style="cash";
				cstyle="銀票";
				break;
			case 2:
				style="gold";
				cstyle="黃金";
				break;
			case 3:
				style="silver";
				cstyle="銀子";
				break;
			default:
				style="coin";
				cstyle="銅錢";
				break;
		}
		
		if(present(style,enemy[j]))		//有此style類型的錢才偷
		{
			money=present(style,enemy[j])->query_amount();
			message_vision(HIY"\n$N的 "+cstyle+" 被$n給偷光了！！\n"NOR,enemy[j],ob);
			tell_object(enemy[j],HIY"（你遺失了 "+cstyle+" "+money+" "+present(style,enemy[j])->query("base_unit")+"）\n\n"NOR);
			present(style,enemy[j])->set_amount(0);		//全部偷光
		}
	}
	return "";
}

void die()
{
	object who=this_object()->query_temp("last_damage_from");
	if(!who)	::die();
	else
	{
		if(random(100)<5)
		{
			tell_object(users(),HIY"
天空出現一道金光流星劃過～～
		\n"NOR);
			new("/open/area/fortress/npc/obj/star.c")->move(who);
			write_log(who,"第一個拿到土靈");			//紀錄得獎人，之後拿掉...
		}
	}
	::die();
}
