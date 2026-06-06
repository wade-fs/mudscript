// Room : /open/clan/sky-wu-chi/room/room4.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
	set( "long", @LONG
寂靜的走道，兩旁懸掛著明亮的燈火，右方似乎有著些
許光線，也許快到天道無極的天極殿了，溫暖的火光照著自
己覺得格外的舒適，想不到看似冷寂的外表，竟有如此陽光
的一面，正一邊享受這美好的一片時，感覺似乎好像快走到
了。

LONG);
	set( "short", "長廊1" );
	set( "object", ([
		"file8"    : "/open/gsword/obj1/bbladeball",
		"amount7"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/gsword/obj1/bbladeball",
		"amount5"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/gsword/obj1/bbladeball",
		"file3"    : "/open/gsword/obj1/bbladeball",
		"file5"    : "/open/gsword/obj1/bbladeball",
		"amount1"  : 1,
		"file1"    : "/open/mogi/village/obj/mogi_ring",
		"amount2"  : 1,
	]) );
	set( "build", 11191 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room103.c",
		"south"     : "/open/clan/sky-wu-chi/room/room85.c",
		"east"      : "/open/clan/sky-wu-chi/room/hall.c",
]) );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	setup();

	}
