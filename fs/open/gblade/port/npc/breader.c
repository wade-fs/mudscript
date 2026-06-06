// /open/center/npc/vendor.c
#include "/open/open.h"
inherit F_VENDOR;
void create()
{
	set_name("麵包師父",({"breader"}));
	set("gender", "男性" );
	set("age", 42);
	set("long", @LONG
一個矮矮胖胖的麵包師父 , 看他這副德行做出來的麵包
會好吃嗎 ? 
LONG);
	set("attitude", "friendly");
	set("combat_exp",2000);
	set_skill("dodge",20);
	set_skill("unarmed",50);
	set_skill("parry",50);
	set("vendor_goods", ({
	"/open/gblade/port/obj/bread",
	}));
	set("greeting_msg", ({
 	    "麵包師說道: 來喔 !來喔 ! 皇帝最喜歡吃的波蘿麵包喔 !\n",
	    	}) );
	setup();
	add_money("silver",1);
	
}
