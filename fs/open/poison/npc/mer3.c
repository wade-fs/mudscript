
#include <ansi.h>

inherit F_VENDOR;

void create()
{
	set_name("茶店老板", ({"shop keeper","keeper"}) );
	set("long","
本間茶店的主人，他正跟來這飲茶的其它村民聊的不亦樂乎而無暇招呼你，
看來如果你想喝茶的話最好的方法是自助囉。\n");
	set("age",31);
	set("gender","男性");
	set("str",25);
	set("no_kill",1);

	set("vendor_goods",({
	"/open/poison/obj/tea1.c",
	"/open/poison/obj/tea2.c",
	"/open/poison/obj/bean.c",
	"/obj/example/chicken_leg.c",
	"/obj/example/dumpling.c",
 }) );              
	set("attitude","friendly");
	set("max_kee",500);
	setup();
	carry_object("/obj/cloth.c")->wear();
}
void greeting(object me)
{
	if(!me || environment(me)!= environment()) return ;
{
	command("welcome "+me->query("id"));
	command("say 您好，來壺茶止止渴吧。");
}
}
