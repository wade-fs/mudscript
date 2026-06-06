#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
          set("short","紫雲寶殿");
        set("valid_startroom", 1);
set ("long", @LONG
這裡是雪蒼派的聖地『紫雲寶殿』，寶殿裡裝飾著 無數的珍寶 ,
顯得華麗非凡，是雪蒼派弟子聚會時，或有貴客來臨時候的一個重要
場所。
LONG);
set("exits",([
		"south":__DIR__"room5_out",
		"north":__DIR__"room6",
		"east":__DIR__"room10",
		"west":__DIR__"room18",
        ]) );
	set("light_up",1);
	set("objects",([
	"/open/snow/npc/sing-chens" : 1,
	]));
        setup();
}
void init()
{
	object me = this_player();
	if( wizardp(me) && me->query("id") != "fund" ) me->move("/open/wiz/jobroom");
}
int valid_leave( object me , string dir )
{
	object ob;
	if( dir != "north" ) return 1;
	if( ( ob = present( "sing chens",this_object() ) ) ) {
		message_vision("$N說道﹕這個地方不能隨便進入。\n",ob);
		return 0;
	}
	return 1;
}
