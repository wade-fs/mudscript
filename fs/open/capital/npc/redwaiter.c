// /d/snow/npc/waiter.c
#include "/open/capital/capital.h"  

inherit F_VENDOR;

void create()
{
	set_name("錦衣侍者", ({ "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",@LONG
這位侍者身上穿著華麗的衣服，而且氣質相當的高雅，不愧
是特別聘來服務達官貴人的。
LONG);
						
	set("combat_exp",500);
	set("attitude", "friendly");
	set("vendor_goods", ({
		CAP_OBJ"dumpling1",
		CAP_OBJ"chicken_leg1",
                CAP_OBJ"soup",
	}) );
	setup();
	carry_object("/open/capital/obj/silk_cloth1")->wear();
}

void init()
{	
	object ob;

	::init();
	add_action("do_vendor_list", "list");
}


