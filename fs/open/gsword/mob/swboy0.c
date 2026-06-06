// guard.c

#include <ansi.h>

inherit NPC;
void create()
{        
	set_name("仙劍派劍童", ({ "sword boy", "boy" }) );
	set("gender", "男性" );
	set("age", 18);
	set("str", 35);
	set("cor", 45);
	set("cps", 25);
	set("int", 25);
	set("long",
                "一位仙劍派的小劍童,他身上可有些武藝,\n"
		"他被派來看守陣門,你可不要小看他.\n" );
        set_skill("sword", 20);
	set("combat_exp",717);
	set("attitude", "peaceful");
	set("chat_chance", 15);
	set("chat_msg", ({
		"劍童說: 西方就是蜀山奇陣,沒事不要亂走.\n",
		"劍童說: 要闖蜀山奇陣,請先確定你已經了解五行之法.\n",
		"劍童說: 亂走迷路,仙劍派可不負責...\n",
	}) );
	set("inquiry", ([
		"五行": "連五行都不知道你闖甚麼蜀山奇陣...\n",
		"無極真人": "那是本派掌門.\n",
		"蜀山奇陣": "這是本門的密秘,你最好不要多問!!\n",
	]) );
        set_skill("shasword", 13);
        map_skill("sword","shasword");
        set_skill("sword",15);
        set_skill("unarmed", 15);
	set_skill("parry", 30);
	set_skill("dodge", 25);
	setup();
	add_money("coin",100);
        carry_object("/open/gsword/obj/wrists")->wear();
        carry_object("/open/gsword/obj/map1");
        carry_object("/open/gsword/obj/suit")->wear();
        carry_object("/open/gsword/obj/boot-1")->wear();
        carry_object("/open/gsword/obj/woodsword")->wield();
}
