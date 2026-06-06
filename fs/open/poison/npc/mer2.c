
#include <ansi.h>
inherit F_VENDOR;
      

void create()
{
	set_name("雜貨店老闆",({"shop keeper","keeper"}) );
	set("long","
雜貨店的老闆，他正舒舒服服的躺在籐椅上悠閒地抽著手上的煙管，似乎
不因你的到來而感到驚訝。他以手勢示意要你自己到處看看需要甚麼再告
訴他。\n");
		set("age",33);
		set("gender","男性");
		set("str",25);
		set("no_kill",1);
 
		set("attitude","friendly");
		set("vendor_goods",({
		"/open/poison/obj/lamp.c",
		"/open/poison/obj/carver.c",
		"/open/poison/obj/broom.c",
	//	"/open/poison/obj/axe.c",
		"/open/poison/obj/rope.c",
		"/open/poison/obj/pipe.c",
		"/open/poison/obj/rain.c",
		"/open/poison/obj/hat.c",
		"/obj/example/wineskin.c",
	                           
	}) );
		set("max_kee",500);
		setup();
		carry_object("/obj/cloth.c")->wear();
		carry_object("/open/poison/obj/pipe.c")->wield();
 
}

void greeting(object me)
{
	if (!me || environment(me)!=environment()) return;
	{
	  command("yawn "+me->query("id"));
	  command("say 你好呀..要甚自己看看吧。");
	}
}
