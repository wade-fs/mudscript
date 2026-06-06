// Room : /open/clan/sky-wu-chi/room/room6.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "light_up", 1 );
	set( "long", @LONG
寂靜的走道，兩旁懸掛著明亮的燈火，左方似乎有著些
許光線，也許快到天道無極的天極殿了，溫暖的火光照著自
己覺得格外的舒適，想不到看似冷寂的外表，竟有如此陽光
的一面，正一邊享受這美好的一片時，感覺似乎好像快走到
了。

LONG);
	set( "short", "長廊 2" );
	set( "object", ([
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/killer/obj/soul-hands",
		"file9"    : "/open/dancer/obj/yuawaist",
		"file3"    : "/open/capital/obj/steps_book",
		"amount3"  : 1,
		"file4"    : "/open/killer/obj/s_pill",
		"amount9"  : 1,
		"file8"    : "/open/gblade/obj/dragon_book",
		"amount10" : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file7"    : "/open/prayer/obj/boris-cloth",
		"amount8"  : 1,
		"amount4"  : 120,
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "build", 10166 );
	set( "no_transmit", 1 );
	set( "exits", ([ /* sizeof() == 4 */
		"east"      : "/open/clan/sky-wu-chi/room/room105.c",
		"north"     : "/open/clan/sky-wu-chi/room/room82.c",
		"west"      : "/open/clan/sky-wu-chi/room/hall.c",
]) );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	setup();

	}
