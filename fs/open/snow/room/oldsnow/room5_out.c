#include <room.h>

inherit ROOM;

void create()
{
	set("short","紫雲寶殿門口");
	set("long","這裡是紫雲寶殿外面﹐大名頂頂的武者工會就在你面
只要加入了武者工會﹐就可以參加所有跟武者有關的門派。\n");
        set("exits", ([
		"north":__DIR__"room2",
		"down":__DIR__"room4",
        ]) );
	set("light_up",1);
	set("objects",([
	"/open/snow/npc/lu" : 1,
	]));
        setup();
}
int valid_leave( object me , string dir )
{
	if( dir != "north" ) return 1;
	if( present("lu",this_object()) )
	{
		tell_object(me,"陸小雙攔住了你的去路。\n");
		return 0;
	}
	return 1;
}
void init()
{
	object me = this_player();
	if( wizardp(me) && me->query("id") != "fund" ) me->move("/open/wiz/jobroom");
}
