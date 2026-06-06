// /open/center/npc/vendor.c
#include "/open/open.h"
inherit NPC;
int time=0;
void create()
{
	set_name("渡船", ({ "ship" }) );
	
	set("long", @LONG
來往於鏡月島和楓林港之間的渡船 ! 
LONG);
	set("attitude", "friendly");
	
	setup();
	set_heart_beat(1);	
}
void init()
{
	add_action("do_look","look");
	add_action("do_look","l");
}

void heart_beat()
{
 time++;
 if(time==1)
 {
 say("前往鏡月島的渡船到囉 , 請趕快搭(board)船 !\n");
 }
 if(time==11)
 {
 say("開船囉 , 沒搭上的人等下一班吧 !\n");
 destruct(this_object());
 }
} 

int do_look(string str)
{
	if(str=="ship")
	{
	write("來往於鏡月島和楓林港之間的船!\n");
	return 1;
	}
return 0;
}
int accept_fight(object me)
{
	return notify_fail("看清楚 , 那並不是生物 !\n");
}
int accept_kill(object me)
{
	return notify_fail("看清楚 , 那並不是生物 !\n");
}
