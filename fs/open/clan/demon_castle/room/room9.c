// Room : /open/clan/demon_castle/room/room9.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "short", "ζ奶茶室ζ" );
	set( "build", 1 );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/capital/obj/king-boots",
		"file3"    : "/open/capital/obj/king-belt",
		"file5"    : "/open/capital/obj/king-cloth",
		"amount6"  : 1,
		"file7"    : "/open/ping/obj/ring-2",
		"amount2"  : 1,
		"file6"    : "/open/capital/obj/king-cloak",
		"amount7"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/capital/obj/king-ring",
		"file4"    : "/open/capital/guard/gring",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
	]) );
	set( "owner", "rickshu" );
	set( "long", @LONG
    這裡是惡魔城內的喝茶室，亦是惡魔城裡人人口中的江湖樂園， 
當你一走進來時, 一眼看出維修小站正熱情的等待你開口, 看你需要哪些茶類
但小心茶當中不知是否有詐, 看著維修小站熟練的泡茶技術, 讓你頭昏昏的了 
看維修小站後方有個神秘的櫃子,看來需要維修小站腰帶上的鑰匙
LONG);
	set( "exits", ([ /* sizeof() == 1 */
  "east" : "/open/clan/demon_castle/room/room5",
]) );
	set( "clan_room", "惡魔城" );
	setup();

	}
