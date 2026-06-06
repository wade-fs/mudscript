inherit ROOM;
void create() {
	set( "short", "西方極樂" );
	set( "owner", "papt" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/love/obj/cloth1",
		"amount7"  : 1,
		"file7"    : "/open/scholar/obj/icefan",
		"file4"    : "/open/ping/obj/chilin_legging",
		"amount5"  : 1,
		"file3"    : "/open/gsword/obj/dragon-sword",
		"amount6"  : 1,
		"file2"    : "/open/gsword/obj/dragon-sword",
		"amount3"  : 1,
		"file8"    : "/open/killer/obj/bellstar",
		"amount1"  : 1,
		"file9"    : "/open/ping/obj/chilin_legging",
		"amount9"  : 1,
		"file5"    : "/open/wind-rain/obj/bird-blade",
		"amount8"  : 95552,
		"amount10" : 359,
		"file10"   : "/open/doctor/pill/gnd_pill",
		"file6"    : "/open/gsword/obj/dragon-cloth",
	]) );
	set( "build", 10762 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room62",
	]) );
	set( "long", @LONG

        西        西        西        西        西        西

            方        方        方        方        方        方

                極        極        極        極        極        極

                    樂        樂        樂        樂        樂        樂

LONG);
	setup();
	replace_program(ROOM);
}
