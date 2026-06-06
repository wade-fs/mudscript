#include <room.h>
#include "/open/open.h"
inherit ROOM;

int num_of_mob;

string call_mob();
string do_kick();

void create()
{
        set("short","洞穴");
        set("long",@LONG
這裡是一間密室, 經過了前面漫長的考驗, 你的直覺認為這一條
路應該就是通往雪蒼派的正確道路了!東邊的牆角好像有一個洞穴(hole)。
LONG);
        set("exits", ([
             "out":__DIR__"hole14",
                "north":__DIR__"hole27",
        ]) );
	set("search_desc", ([
	    "hole"	:	(: do_kick :),
	]) );
	set("mob_numbers",3);
	
	setup();
}

void init()
{
	add_action("do_look","look");
}

string do_kick()
{
	object ob;
	if(this_object()->query("mob_numbers")==0)
	  return "洞穴裡面似乎沒什麼東西了。\n";
	this_object()->add("mob_numbers",-1);
        ob = new("/open/snow/npc/bigmouse");
	ob->move("/open/snow/room/hole26");
	message_vision(
		"$N在洞裡搜尋半天，突然從洞穴裡跑出一隻大老鼠衝了出來。\n"+
		"哇...你被衝的頭昏眼花。", this_player());
	return "\n";
}

int do_look(string str)
{
	if(str!="hole") return 0;
        tell_object(this_player(),"你發現一個中型的洞穴,裡面似乎有什麼東西,可以找找看(search hole)。\n");
	return 1;
}
