inherit ROOM;
void create() {
	set( "short", "魔龍塔第九層" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/killer/obj/kill_yar_head",
		"amount1"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/gsword/obj1/bpball",
		"file3"    : "/open/gsword/obj1/bpball",
		"file8"    : "/open/gsword/obj1/bpball",
		"amount6"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file6"    : "/open/gsword/obj1/bpball",
		"file9"    : "/open/gsword/obj1/bpball",
		"file10"   : "/open/gsword/obj1/bpball",
		"file7"    : "/open/gsword/obj1/bpball",
		"file2"    : "/open/gsword/obj1/bpball",
		"amount8"  : 1,
		"file1"    : "/open/gsword/obj1/bpball",
	]) );
	set( "build", 11698 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
		"up"        : "/open/clan/sky-wu-chi/room/room490.c",
		"down"      : "/open/clan/sky-wu-chi/room/room488.c",
	]) );
	set( "long", @LONG

這裡是魔龍塔的第九層，一踏入這裡，四周的殺氣突然濃烈了起來，一
雙雙怖滿殺氣的眼睛正凝視著你。你定了定神後，注意到這個房間的四
周，地上滿怖著刀痕，角落處推滿一堆堆的駭骨，使你不寒兒凜。可是
你又無法抗拒它所散發出來的氣息，深深的被吸引著。
LONG);
	setup();
	replace_program(ROOM);
}
