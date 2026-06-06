#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
 set("short","急風坡");
  set ("long", @LONG
這裡是雪蒼山邊的急風坡﹐在這裡不時捲起急風﹐吹得讓人害怕會掉
到山谷之下﹐相聞這裡不時有些神秘人物在此出入﹐不知是否暗藏玄機 ?
在山谷邊有條繩子(rope)垂吊而下﹐不之是做何而用﹐從山谷看下去﹐
大約有數百丈高﹐要是摔下去不是死就是重傷。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"southup":__DIR__"water2",
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
	if(dir=="southup")
	me->delete_temp("catch_robe");
	return 1;
}
int do_look(string str)
{
	if(str=="robe")
	{
		tell_object(this_player(),"你看到這條繩子直通下方﹐但不知道到底通到那。\n");
		return 1;
	}
	return 0;
}
int do_catch(string str)
{
if(str=="rope")
	{
		message_vision("$N緊緊的抓住繩子。\n",this_player());
		this_player()->set_temp("catch_robe",1);
		return 1;
	}
	return 0;
}
int do_climb(string str)
{
if(str!="down" && str != "rope") return 0;

message_vision("$N抓住繩子慢慢的爬了下去,但是好似無底般的深,又爬了上來。\n",this_player());
        this_player()->move("/open/snow/room/black1");
	return 1;
}
