inherit NPC;
#include <ansi.h>
string do_steal();

void create()
{
	set_name("小偷",({"thief"}));
	set("long","嘴尖眼利，手腳俐落的小偷，時常遊走在大街上，偷偷將人們腰帶裡面的錢偷走。\n");
	set("race", "人類");
	set("gender","男性");
	set("title",HIR + "極火山寨" + NOR);
        set("age",23);
        set("attitude","friendly");
        set("combat_exp",100000);
        set("max_gin",1000);
        set("eff_gin",1000);
        set("gin",1000);
        set("max_kee",4000);
        set("eff_kee",4000);
        set("kee",4000);
        set("max_sen",1000);
        set("eff_sen",1000);
        set("sen",1000);
        set("max_force",10000);
        set("force",10000);
        set("force_factor",20);
        set("str",20);
        set("cor",30);
        set("int",10);
        set("spi",10);
        set("cps",30);
        set("per",10);
        set("con",10);
        set("kar",50);
        set_skill("force",40);
        set_skill("parry",40);
        set_skill("move",40);
        set_skill("dodge",40);
        set_skill("fireforce",40);
        set_skill("mogi-steps",40);
        set_skill("firestrike",40);
        map_skill("unarmed","firestrike");
        map_skill("parry","firestrike");
        map_skill("dodge","mogi-steps");
        map_skill("move","mogi-steps");
        map_skill("force","foreforce");
        set("functions/gold-fire/level",40);
        set("quest/gold-fire",1);
	set("quest/new_gold_fire",1);			
        set_temp("no_die_soon",1);			
        set_temp("apply/armor",40);			
        set_temp("apply/defense",40);			
        set_temp("apply/damage",40);			
        set_temp("apply/attack",40);
        set_temp("no_steal",1);
        set("chat_chance_combat", 100);			//設定機率
        set("chat_msg_combat", ({			//將執行function
        (:do_steal:),
        }));
	setup();
        carry_object("/open/area/fortress/npc/obj/cloth01")->wear();
        carry_object("/open/area/fortress/npc/obj/pants01")->wear();
        carry_object("/open/area/fortress/npc/obj/boots01")->wear();
        carry_object("/open/area/fortress/npc/obj/head01")->wear();
        add_money("gold",5);
}

string do_steal()
{
	object ob;
	mixed enemy,item;
	string style,cstyle;					//style錢的類型
	int i,j,money,del;
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
			del=random(money)+1;
			message_vision(HIY + "\n$N被$n偷走 "+cstyle+" "+del+" "+present(style,enemy[j])->query("base_unit")+"！！\n\n" + NOR,enemy[j],ob);
			del=money-del;			//扣掉被偷的
			present(style,enemy[j])->set_amount(del);	//剩下來的
		}
	}
	return "";
}
