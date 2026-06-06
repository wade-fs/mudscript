//junkwawa.c
//by casey..
//Object : /open/main/npc/junkman.c
//增加mark 以符合少林區域的判斷 by blazakira

#include <ansi.h>
#include <npc.h>
#include "/open/open.h"

inherit NPC;

void create()
{
	set_name("侍女", ({ "maid girl","maid","girl","g"  }));
	set("long",
		"傳聞是無所不能的神秘老人「拾荒老頭」的孫女，因感恩當初的一碗飯的恩情，\n"
		"因此讓他的孫女前來服侍周芷若。一身宮廷傳統仕女服，令她有種出人意料的氣\n"
		"質，眾人相信她將來會是一位顛倒眾生的大美女。\n" //她負責周芷若生活起居的大小事，別小看她嬌滴滴的模樣，她可是傳聞中無所不能
		"\n" ); //一雙水汪汪的大眼睛，一頭烏黑秀麗的長髮，稚嫩的嗓音，一身xxx 讓人忍不住低憐愛。
            set("gender","女性");
            set("class","dancer");
            set("combat_exp",10);
//        set("attitude","heroism"); //不主動攻擊 會被殺氣瞪==會因為殺氣比內力高 而被玩家自動殺mob
        set("attitude","friendly"); //不主動攻擊 不會被殺氣瞪==不會因為殺氣比內力高 而被玩家自動殺mob
//        set("attitude","aggressive"); //主動攻擊玩家
            set("age",13);
//   set_temp("roared", 1 ); //雙重roar 判斷 以增加mob差異性
 //練功型的mob 暫時不考慮太多的特攻
			set("adv_dancer",1);
//            set("allow_hellfire",1);
//            set("get_dan_sp",1);
            set("per", 41);
            set("int", 45);
	set("force",30000);
	set("max_force",30000);
	set("kee",30000);
	set("max_kee",30000);
	set("gin",30000);
	set("max_gin",30000);
	set("sen",30000);
	set("max_sen",30000);
	set("atman",30000);
	set("max_atman",30000);
	set("mana",30000);
	set("max_mana",30000);
	set("no_kill", 1);
	set("no_fight", 1);
	set("bounty/mortal sin", 5);
//	set("random_move",1500);
	// 自由行走的格數
	set("chat_chance", 10);
	// 平時會自動出現的訊息
	// 可以包括副程式及訊息
	// 補充一下 combat_msg是用來戰鬥時mob所參生的訊息......	
	set("chat_msg",({
//	(: random_move :),
//	(: random_move :),
//	(: command("get corpse") :),
//	(: command("get all from corpse") :),
//	(: command("get all") :),
	(: command("get broken") :),
	(: this_object(),"get all" :),
	}));
	set_temp("quests/bonze/mob", 1 ); //設定【query("quests/bonze/mob")== "1" 】
                                                       //為巡邏mob的判斷 避免觸發本區mob的呼叫
	setup();
}

void init()
{
	set_heart_beat(1);
}


void die()
{
	object ob, ob1, ob2, ob3, ob4, ob5, ob6, ob7;
	if( !ob = query_temp("last_damage_from") )
		ob = this_player(1);

	if( !ob ) return;
	write(HIC + "遠方飄來一句：「你也來陪葬吧。」拾荒老頭冷笑的嗓音。\n" + NOR);
	  ob->set("last_on", time());
	  ob->set("last_from", query_ip_name(ob));
	  ob->set_temp("last_damage_from", ob);
	  ob -> die();

	destruct(this_object());
}
