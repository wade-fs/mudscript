inherit ROOM;
void create() {
	set( "short", "$HIB$海潮之聲$NOR$" );
	set( "object", ([
		"amount6"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount3"  : 1,
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount4"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file9"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount5"  : 1,
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10499 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room433.c",
		"east"      : "/open/clan/ou-cloud-club/room/room439.c",
		"south"     : "/open/clan/ou-cloud-club/room/room564",
		"west"      : "/open/clan/ou-cloud-club/room/room441.c",
	]) );
	set( "long", @LONG
這一條通道是以海之王者海龍『利拜亞桑』體內的龍脊作為
主要的架構，起伏不定的路面讓人不得不小心行走，不過在行進
間所吸進的龍靈之氣有助於調勻內息，難怪這裡常常有這麼多人
走動。兩旁還有陣陣微風吹來，令人心曠神怡。

北邊現在是Superpker的家。

LONG);
	setup();
	replace_program(ROOM);
}
