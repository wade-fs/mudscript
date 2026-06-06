inherit ROOM;
void create() {
	set( "short", "魔龍塔第十層" );
	set( "owner", "hild" );
	set( "object", ([
		"file3"    : "/open/gsword/obj1/bbladeball",
		"amount9"  : 1,
		"amount8"  : 1,
		"amount10" : 1,
		"amount2"  : 1,
		"file10"   : "/open/gsword/obj1/bbladeball",
		"amount1"  : 1,
		"file1"    : "/open/gsword/obj1/bbladeball",
		"file9"    : "/open/gsword/obj1/bbladeball",
		"file6"    : "/open/gsword/obj1/bbladeball",
		"file2"    : "/open/gsword/obj1/bbladeball",
		"amount7"  : 1,
		"file7"    : "/open/gsword/obj1/bbladeball",
		"amount5"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/gsword/obj1/bbladeball",
		"file5"    : "/open/gsword/obj1/bbladeball",
		"amount6"  : 1,
	]) );
	set( "build", 23391 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"out"       : "/open/clan/sky-wu-chi/room/room441.c",
		"down"      : "/open/clan/sky-wu-chi/room/room489.c",
	]) );
	set( "long", @LONG

這裡是魔龍塔的第十層，一踏入這裡，四周的殺氣突然濃烈了起來，一
雙雙怖滿殺氣的眼睛正凝視著你。你定了定神後，注意到這個房間的四
周，地上滿怖著刀痕，角落處推滿一堆堆的駭骨，使你不寒兒凜。可是
你又無法抗拒它所散發出來的氣息，深深的被吸引著。
LONG);
	setup();
	replace_program(ROOM);
}
