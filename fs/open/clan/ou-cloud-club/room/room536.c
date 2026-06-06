inherit ROOM;
void create() {
	set( "short", "穹蒼無悔" );
	set( "light_up", 1 );
	set( "object", ([
		"file1"    : "/open/killer/headkill/obj/i_dag",
		"amount9"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount6"  : 1,
		"amount5"  : 1,
		"file6"    : "/open/ghost-hole/obj/dark-spirit",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/scholar/room/newplan/obj/s-shield",
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/scholar/room/newplan/obj/s-shield",
		"amount4"  : 1,
	]) );
	set( "build", 10476 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room537.c",
		"down"      : "/open/clan/ou-cloud-club/room/room253.c",
		"south"     : "/open/clan/ou-cloud-club/room/room539",
		"west"      : "/open/clan/ou-cloud-club/room/room538.c",
	]) );
	set( "long", @LONG

天天天天天天天天天天天天天天天天天天天天天天天天天天天天
天天天天天天天天天天天天天天天天天天天天天天天天天天天天

雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲
雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲雲

海海海海海海海海海海海海海海海海海海海海海海海海海海海海
海海海海海海海海海海海海海海海海海海海海海海海海海海海海

LONG);
	setup();
	replace_program(ROOM);
}
