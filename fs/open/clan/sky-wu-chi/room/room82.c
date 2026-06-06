// Room : /open/clan/sky-wu-chi/room/room82.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "clan_room", "天道無極" );
	set( "short", "$HIR$長廊$NOR$" );
	set( "object", ([
		"file8"    : "/obj/gift/shenliwan",
		"file4"    : "/daemon/class/blademan/obj/shield",
		"amount4"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"file7"    : "/open/tendo/obj/chaosbelt",
		"amount5"  : 12,
		"file10"   : "/open/snow/obj/figring",
		"file9"    : "/open/fire-hole/obj/b-pill",
		"amount6"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"amount7"  : 1,
		"amount3"  : 52,
		"file3"    : "/open/mon/obj/mon-pill",
		"file5"    : "/open/ping/obj/poison_pill",
		"amount9"  : 2,
	]) );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "long", @LONG
寂靜的走道，兩旁懸掛著明亮的燈火，左方似乎有著些
許光線，也許快到天道無極的天極殿了，溫暖的火光照著自
己覺得格外的舒適，想不到看似冷寂的外表，竟有如此陽光
的一面，正一邊享受這美好的一片時，感覺似乎好像快走到
了。
LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "exits", ([ /* sizeof() == 2 */
		"north"     : "/open/clan/sky-wu-chi/room/room10",
		"east"      : "/open/clan/sky-wu-chi/room/room83.c",
		"south"     : "/open/clan/sky-wu-chi/room/room6.c",
]) );
	set( "cmkroom", 1 );
	setup();

	}
