// /open/center/npc/vendor.c
#include "/open/open.h"
inherit F_VENDOR;
void create()
{
	set_name("店小二",({"keeper"}));
	set("gender", "男性" );
	set("age",23);
	set("long", "清風樓客棧的店小二 , 他正忙著招呼客人 .\n");
	set("attitude", "friendly");
	set("no_kill",1);
	set("vendor_goods", ({
	"/obj/example/chicken_leg",
	"/obj/example/dumpling",
	"/obj/example/wineskin",

	}) );
	
	setup();
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
	say("店小二說道: 這位"+RANK_D->query_respect(ob)+"你好 , 進來歇會兒吧 !\n");
return;
}
