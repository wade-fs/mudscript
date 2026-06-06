#include "/open/gsword/npc/attack_bloodsword.h"

inherit NPC;

void create()
{
	set_name("張應龍",({"in long","long"}));
	set("long","仙劍第五代大師兄 ,也是張乘風之長子 .\n");
	set("gender","男性");
	set("combat_exp",15507);
        set("attitude","heroism");
	set("age",23);
	set("title","仙劍派第五代大師兄");
	set("class","swordsman");
	set("force",500);
	set("max_force",500);
	set("family/master_name","張乘風");
	set("force_factor",5);
	set("str",30);
        set("cor", 30);
	set("per", 25);
	set("int", 30);
	set_skill("shasword",10);
	set_skill("sha-steps",3);
	map_skill("sword","shasword");
	map_skill("dodge","sha-steps");
	set("chat_chance",6);
	set("chat_msg",({
		"張應龍喃喃的說:小師妹之所以發生這種不幸的事，都是我一時貪玩造成的，
被師父責罰是理所當然的。\n",
          }));	
	set("cps",20);
	set("con", 30);
	set("spi", 15);
	set("kar", 30);
	set_skill("sword",60);
	set("inquiry",([
	"小師妹": "那天我帶他到後山遊玩，走著走著，看到奉命守在禁地入口
	的淡月師弟，我們也就上前聊了幾句，不料一個不小心，竟讓小師妹溜進
	了禁地，那禁地我們是決不能進入的，只好馬上回報師父，師父大怒之下
	罰我在這私過一個月，至於小師妹現在的情形我也不太清楚。\n"
	]));
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("move",40);
	set_skill("literate",40);
	set_skill("force",40);
	setup();
	carry_object("/obj/longsword.c")->wield();
	carry_object("/open/gsword/obj/robe_1")->wear();
	carry_object("/open/gsword/obj/ff_pill")->set_amount(1);
	create_family("仙劍派",5,"弟子");
}
