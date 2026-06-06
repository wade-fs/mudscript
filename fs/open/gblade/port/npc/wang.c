// /open/center/npc/vendor.c
#include "/open/open.h"
inherit F_VENDOR;
void create()
{
	set_name("刀疤王五", ({ "wang" }) );
	set("gender", "男性" );
	set("age", 42);
	set("long", @LONG
看他臉上一條條令人怵目驚心的刀疤 , 你可以想見他年輕
時一定也是條鐵錚錚的好漢 .
LONG);
	set("attitude", "friendly");
	set("combat_exp",20000);
	set_skill("dodge",50);
	set_skill("blade",50);
	set_skill("parry",50);
	set_skill("gold-blade",30);
	set_skill("fly-steps",30);
	map_skill("blade","gold-blade");
	map_skill("dodge","fly-steps");
	set("vendor_goods", ({
            GS_OBJ"woodblade",
	    "/open/gblade/obj/blade",
            "/open/gblade/obj/knife",	
	"/open/badman/obj/blade",
	"/open/gblade/port/obj/steel_blade",
	"/open/gblade/port/obj/knife",
	"/open/gsword/obj/blade",
	"/open/gblade/obj/oldblade",

	}) );
	set("chat_chance_combat",20);
	set("chat_msg_combat",({
	"刀疤王五喝到 : 不自量力的小子 , 我殺死的人比你看過還多勒 !\n",
	"刀疤王五怒道 : 可惡 , 我讓你看看什麼叫做功\夫 !\n",
	}));
	
	set("greeting_msg", ({
 	    "刀疤王五說道: 年輕人 , 買把武器防身吧!\n",
	    	}) );
	setup();
        add_money("silver",10);
	carry_object("/open/gblade/port/obj/ghost_blade")->wield();
}
