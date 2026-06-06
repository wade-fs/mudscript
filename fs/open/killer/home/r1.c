#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","懸壁");
  set ("long", @LONG
順著繩子(rope)往下﹐一直爬到了懸壁中間﹐你發現這裡有一處洞穴
洞穴裡看起來暗暗的﹐不知道藏著什麼玄機﹐有怪物? 還是有寶物
或是什麼人藏在這? 要進入? 還是要逃?
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"enter":__DIR__"r2",
]));

  set("light_up", 1);

  setup();
}
void init()
{
	add_action("do_look","look");
	add_action("do_catch","catch");
	add_action("do_climb","climb");
}
int valid_leave(object me,string dir)
{
	if(dir=="enter")
	me->delete_temp("catch_robe");
	return 1;
}
int do_look(string str)
{
if(str=="rope")
	{
  tell_object(this_player(),"你看到這條繩子掛在懸壁上﹐必須用抓的(catch)過來。\n");
		return 1;
	}
	return 0;
}
int do_catch(string str)
{
        if(str=="rope")
	{
        message_vision("$N緊緊的抓住繩子﹐發現出口就在上方(climb up)。\n",this_player());
                this_player()->set_temp("catch_rope",1);
		return 1;
	}
	return 0;
}
int do_climb(string str)
{
	if(str!="up") return 0;
	message_vision("$N抓住繩子慢慢的爬了上去。\n",this_player());
        this_player()->move("/open/snow/room/black1");
	return 1;
}
