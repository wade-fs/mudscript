
#include <ansi.h>
#include "/open/open.h"
inherit NPC;

void create()
{
	set_name("當鋪老闆",({"pawn"}) );
	set("long","
本店的老闆，聽說他以前還是京城一著名當鋪的當家朝奉，告老還鄉之後卻
不知為何又在此地開起當鋪來。\n");
	set("no_kill",1);
	set("age",70);
	set("gender","男性");
	set("str",25);
	set("con",24);
	set("max_kee",350);
        setup();
}
void greeting(object me)
{
	if(!me || environment(me)!=environment()) return;
{
	command("grin "+me->query("id"));
	command("say 客人好，想當些東西嗎");
}
}
