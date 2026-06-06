// /open/center/npc/vendor.c
#include "/open/capital/capital.h"
					
inherit F_VENDOR;

void create()
{
	set_name("小販", ({ "vendor"}) );
	set("gender", "男性" );
	set("age", 37);
	set("long", @LONG
一個販賣雜貨的小販，濃眉大眼，看起來像是關外的胡人。
LONG);
	set("attitude", "friendly");
	set("combat_exp",170);
	set("no_kill",1);

	set("vendor_goods", ({
	    "/obj/torch",
	    CAP_OBJ"map",
	}) );
						
	set("greeting_msg", ({
 	    "小販說道: 大爺小姐們，有木頭賣喔!\n",
	    "小販說道: 大爺小姐們，有地圖賣喔!\n",	
	}) );
	setup();
}

				
