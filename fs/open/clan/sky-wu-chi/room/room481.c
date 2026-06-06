inherit ROOM;
void create() {
	set( "short", "魔龍塔第一層" );
	set( "owner", "hild" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount5"  : 1,
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"file3"    : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "build", 10076 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
		"up"        : "/open/clan/sky-wu-chi/room/room482.c",
	]) );
	set( "long", @LONG

這裡是魔龍塔的第一層，一踏入這裡，四周的殺氣突然濃烈了起來，一
雙雙怖滿殺氣的眼睛正凝視著你。你定了定神後，注意到這個房間的四
周，地上滿怖著刀痕，角落處推滿一堆堆的駭骨，使你不寒兒凜。可是
你又無法抗拒它所散發出來的氣息，深深的被吸引著。
LONG);
	setup();
	replace_program(ROOM);
}
