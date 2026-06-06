#include "/open/open.h"
inherit NPC;
int do_say();
string do_thief();
void create()
{
	set_name("武林豪客", ({ "fighter" }) );
	set("race", "人類");
	set("gender", "男性");
	set("age", 33);
	set("class","fighter");
	set("long","他是一位武林裡的豪客, 身形魁梧, 臉生橫肉, 嘴大唇厚, 鐵髭如蜂窩, "+
        "他為了闖出一番功\名而到京城來碰碰運氣。\n");
	set("cps", 5);
	set("str", 30);
	set("cor", 20);
	set("kar",10);

        set( "inquiry", ([
       	  "name"  : "待我闖出一番事業來再說吧。",
       	  "here"  : "這裡是京城啊, 我也為了前途而來到這兒, 你呢?",
	  "thief" : (: do_thief :),
        ]));	 	
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
	(: this_object(),"do_say" :),
	 }) );
		
        set_temp("apply/attack", 50);
        set_skill("dodge",30);
        set_skill("parry",40);
        set_skill("blade",60);
	set_skill("her-blade",50);
	map_skill("blade","her-blade");
        set("combat_exp",5000);
	setup();
        add_money("silver",1);
        carry_object(CAPITAL_OBJ"Bblade")->wield();
}

string do_thief()
{
	object ob=this_object();
	object me=this_player();
	if( ob->query_temp("show_mark")==getuid(me) )
	{
	  command("say 既然大人為辦案而來, 小的這就原原本本的告訴你了。");
command("say 此名大盜的武功\似乎是平南城段家一派的六脈神劍，且此盜的右耳後有小傷痕(scar)。");
	  me->set_temp("thief",3);
	  return("我就知道這麼多了");
	}
	else
	  return("哈哈哈!!有天夜裡我起來小解時恰巧碰到那名大盜, 才兩三招便把他打的落荒而逃, 至於他的長相我可就不能跟你說了, 我要自個把他抓來領賞, 哈哈哈....");
}

int do_say()
{
	object ob=this_player();
	tell_room(environment(this_object()),
	"豪客喝道﹕可惡!!你這"+RANK_D->query_rude(ob)+", 讓大爺我來教訓你!!\n");
}
	
void defeated_enemy(object ob)
{
	say("豪客冷笑一聲道 : 沒本事也敢到京城撒野。\n");
        remove_killer(ob);
}        
