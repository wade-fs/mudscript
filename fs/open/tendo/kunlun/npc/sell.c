//vendor.c
#include "/open/open.h"
inherit F_VENDOR;

void create()
{
	set_name("賣藥郎中",({"medicine vendor","vendor"}));
	set("gender", "男性" );
	set("age", 27);
	set("long", @LONG
    一位以賣藥為生的落魄郎中。
LONG
	);
	set("combat_exp",116);
        set("attitude", "friendly");
        set_skill("dodge", 40);
        set_skill("unarmed", 20);
	set("vendor_goods", ({
"/open/tendo/kunlun/obj/pill1",
"/open/tendo/kunlun/obj/pill2",
        COMMON_OBJ"pill1",
        COMMON_OBJ"plaster1",
	}) );
	set("no_kill",1);
	setup();
	add_money("coin",35);
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
	say("賣藥郎中客氣的道: 這兒什麼藥材都有,"+RANK_D->query_respect(ob)+"要過來看看嗎!?\n");
		break;
		case 1:
		break;
		case 2:
		say("賣藥郎中高聲喊道: 來來來, "+RANK_D->query_respect(ob)
		    +"要的話，我可以算便宜一點喔!\n");
		break;
	}
}
