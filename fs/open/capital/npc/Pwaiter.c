//vendor.c
#include "/open/open.h"
inherit F_VENDOR;

void create()
{
	set_name("藥鋪伙計",({"medicine waiter","waiter"}));
	set("gender", "男性" );
	set("age", 27);
	set("long", @LONG
他是藥鋪裡的店員, 專門負責招待上門的顧客, 因此嗓門特別大。
LONG
	);
	set("combat_exp",116);
        set("attitude", "friendly");
        set("score",1000000);
        set_skill("dodge", 40);
        set_skill("unarmed", 20);
	set("vendor_goods", ({
        COMMON_OBJ"bandage",
        COMMON_OBJ"pill",
"/open/doctor/pill/ff_pill",
"/open/doctor/pill/ice_pill",
"open/doctor/pill/f_pill",
        COMMON_OBJ"pill1",
        COMMON_OBJ"pill2",
        COMMON_OBJ"plaster",
        COMMON_OBJ"plaster1",
        COMMON_OBJ"plaster2",
        COMMON_OBJ"plaster3",
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
		say("店員靠近你說: 這位"+RANK_D->query_respect(ob)
		    +"來買些特製補品吧!\n");
		break;
		case 1:
                say("店員客氣的道: 這兒什麼藥材都有 "+RANK_D->query_respect(ob)
                    +"要過來看看嗎!?\n");
		break;
		case 2:
		say("店員高聲喊道: 來來來, "+RANK_D->query_respect(ob)
		    +"要的話，我可以算便宜一點喔!\n");
		break;
	}
}
