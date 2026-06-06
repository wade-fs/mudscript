#include <ansi.h>
inherit ROOM;

void create ()
{
	set ("short", HIB"絕道"NOR" - "HIY"封靈道"NOR" - "HIB"無邊"NOR);
	set( "build", 24 );
	set ("long", @LONG
封靈道的最後一關，由聚靈山莊的莊主親自坐鎮，為了防止不宵
的人進入天靈地界中，取得強大的靈器禍亂天下，所以在此守護最後
一關的通道，並防止有心人士破壙了天下的靈氣源頭，天靈地界的靈
氣。

LONG);

	set("no_auc", 1);
	set("no_transmit", 1);
	set("no_chome", 1);

	set("exits", ([
	"out"		: "/open/magic-manor/ghost/rest10",
	"takeroad"	: "/open/magic-manor/ghost/fon01",
	]));


	set("objects", ([
//    "/open/magic-manor/npc/fengxiang-tian" : 1,
	]));

	set("light_up", 1);

	setup();
}

int valid_leave(object who,string dir)
{
if ( dir=="takeroad" && present("fengxiang tian",environment(who)) ) 
return notify_fail("『暢談』鳳翔天說道: 你們這般惡徒，休想進入天靈地界!!\n");
return 1;
}
