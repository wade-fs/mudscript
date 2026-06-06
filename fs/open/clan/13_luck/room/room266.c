inherit ROOM;
void create() {
	set( "short", "金織手套室" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount5"  : 1,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount8"  : 1,
	]) );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room309",
		"south"     : "/open/clan/13_luck/room/room304.c",
	]) );
	set( "light_up", 1 );
	set( "build", 11601 );
	set( "long", @LONG

    在那平南城，有那可怕的風行山寨，有那一群無惡不作的三頭目，
而手套就是出自他們第三頭目的手中，而他們的頭也被懸賞著，所以也
是也不少人去滅寨，為了經費需求，而打大頭目要小心一點，學了段家
的招式，會被他定到死。

LONG);
	setup();
	replace_program(ROOM);
}
