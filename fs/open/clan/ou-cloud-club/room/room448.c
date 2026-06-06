inherit ROOM;
void create() {
	set( "short", "$HIB$龍王道$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount4"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file7"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount7"  : 1,
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount3"  : 1,
		"amount10" : 1,
		"amount9"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/gold/obj/golden-blade",
	]) );
	set( "build", 10426 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room401.c",
		"north"     : "/open/clan/ou-cloud-club/room/room129.c",
		"south"     : "/open/clan/ou-cloud-club/room/room133",
		"west"      : "/open/clan/ou-cloud-club/room/room118",
	]) );
	set( "long", @LONG
這一道迴廊的建材據說是從遠古龍王『巴哈姆特』上的鱗片
用煉獄之火以及脈動之血加工後所製造出來的，走在這裡雖然會
覺得有一股莫名的壓力籠罩著你，但遠古龍王所蘊藏的能量也讓
你覺得全身上下充滿了蓄勢待發的戰力。

北邊是一個涼亭，歡迎大家去坐，南邊是QOO，歡迎大家去喝。

LONG);
	setup();
	replace_program(ROOM);
}
