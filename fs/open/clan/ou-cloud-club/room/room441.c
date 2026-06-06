inherit ROOM;
void create() {
	set( "short", "$HIB$海潮之聲$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount2"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
	]) );
	set( "build", 10588 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room203",
		"north"     : "/open/clan/ou-cloud-club/room/room435.c",
		"east"      : "/open/clan/ou-cloud-club/room/room440.c",
		"south"     : "/open/clan/ou-cloud-club/room/room434",
	]) );
	set( "long", @LONG
這一條通道是以海之王者海龍$HIM$『利拜亞桑』$NOR$體內的龍脊作為
主要的架構，起伏不定的路面讓人不得不小心行走，不過在行進
間所吸進的龍靈之氣有助於調勻內息，難怪這裡常常有這麼多人
走動。兩旁還有陣陣微風吹來，令人心曠神怡。

北邊現在是Bear的家，南邊現在是Sina的家。

LONG);
	setup();
	replace_program(ROOM);
}
