// /open/center/npc/vendor.c
#include "/open/open.h"
inherit NPC;
int time=0;
void create()
{
	set_name("幽冥魔船",({"vessel"}));
	
	set("long", @LONG
船頭一個大骷顱頭 , 整騪船陰森森的 , 甚為恐怖 !
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
   say("前往冥魔島的船到囉 , 請趕快搭(board)船 !\n");
 }
 if(time==11)
 {
 say("開船囉 , 沒搭上的人等下一班吧 !\n");
 destruct(this_object());
 }
} 

int do_look(string str)
{
	if(str=="vessel")
	{
	write("一騪陰氣森森的魔船 , 有膽的就坐上去吧 !\n");
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
