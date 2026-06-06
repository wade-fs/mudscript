
#include <ansi.h>
inherit F_VENDOR;
void create()
{
	set_name("麵店老闆", ({"shop keeper","keeper"}) );
	set("long","
這間麵店的主人，他看起來似乎十分好客，他正急促的催促你趕快坐下品
嘗一下他的拿手絕活。\n");
	set("age",35);
	set("no_kill", 1);
	set("gender","男性");
	set("vendor_goods",({
	"/open/poison/obj/no1.c",
	"/open/poison/obj/no2.c",
	"/open/poison/obj/no3.c",
}) );
	setup();
	carry_object("/obj/cloth.c")->wear();
}
void greeting(object me)
{
	if(!me || environment(me) != environment()) return;
{
	command("smile "+me->query("id"));
	command("say 你好...要來碗麵嗎?");
 }
}
