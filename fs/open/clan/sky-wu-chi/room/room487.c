inherit ROOM;
void create() {
	set( "short", "魔龍塔第七層" );
	set( "object", ([
		"file6"    : "/open/ghost-hole/obj/eq/ghost-king-tooth",
		"amount4"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/killer/obj/kill_yar_head",
		"amount3"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount1"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-belt",
		"file4"    : "/open/killer/obj/kill_yar_head",
	]) );
	set( "build", 10939 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
		"up"        : "/open/clan/sky-wu-chi/room/room488.c",
		"down"      : "/open/clan/sky-wu-chi/room/room486.c",
	]) );
	set( "long", @LONG

這裡是魔龍塔的第七層，一踏入這裡，四周的殺氣突然濃烈了起來，一
雙雙怖滿殺氣的眼睛正凝視著你。你定了定神後，注意到這個房間的四
周，地上滿怖著刀痕，角落處推滿一堆堆的駭骨，使你不寒兒凜。可是
你又無法抗拒它所散發出來的氣息，深深的被吸引著。
LONG);
	setup();
	replace_program(ROOM);
}
