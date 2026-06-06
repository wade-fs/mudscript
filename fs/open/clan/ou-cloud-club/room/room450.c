inherit ROOM;
void create() {
	set( "short", "$HIB$龍王道$NOR$" );
	set( "object", ([
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file10"   : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount3"  : 1,
		"amount2"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount9"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10194 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room613.c",
		"west"      : "/open/clan/ou-cloud-club/room/room400.c",
		"east"      : "/open/clan/ou-cloud-club/room/room471.c",
		"south"     : "/open/clan/ou-cloud-club/room/room734",
	]) );
	set( "long", @LONG
這一道迴廊的建材據說是從遠古龍王『巴哈姆特』上的鱗片
用煉獄之火以及脈動之血加工後所製造出來的，走在這裡雖然會
覺得有一股莫名的壓力籠罩著你，但遠古龍王所蘊藏的能量也讓
你覺得全身上下充滿了蓄勢待發的戰力。

LONG);
	setup();
	replace_program(ROOM);
}
