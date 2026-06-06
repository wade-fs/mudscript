// Room : /open/clan/sky-wu-chi/room/room45.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "long", @LONG
     你進入了小鬼頭的領域，四周充滿了充沛的氣勁，讓你想起了
 聖火教絕世心法「渾天心法」。一切讓人覺得心情非常的愉快，讓
 你渾然不知道自已的處境，以致你極度的放鬆，然而你的四周卻充
 滿了無數的危機。突然四周的氣息，慢慢的形成一種壓力，而這壓
 力來自門口進來的那個人，怨世天魔小鬼頭。
LONG);
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	set( "short", "萬鬼朝宗" );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room270.c",
		"west"      : "/open/clan/sky-wu-chi/room/room169",
	]) );
	set( "object", ([
		"amount10" : 175,
		"file10"   : "/open/mogi/castle/obj/sspill",
		"amount2"  : 1,
		"amount7"  : 200,
		"file9"    : "/open/killer/obj/atman_pill",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount5"  : 102,
		"amount3"  : 218,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 60,
		"file6"    : "/open/doctor/pill/sky_pill",
		"file5"    : "/open/doctor/pill/gnd_pill",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/castle/obj/sspill",
		"amount6"  : 90,
		"amount4"  : 27,
		"file1"    : "/open/magic-manor/obj/fire-ball",
		"amount1"  : 1,
		"file3"    : "/open/doctor/pill/human_pill",
		"amount8"  : 200,
	]) );
	set( "light_up", 1 );
	set( "build", 10114 );
	set( "clan_room", "天道無極" );
	setup();

	}
