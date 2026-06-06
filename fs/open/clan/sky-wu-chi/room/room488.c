inherit ROOM;
void create() {
	set( "short", "魔龍塔第八層" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"amount1"  : 1,
		"amount6"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file4"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-cloak",
		"amount2"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount8"  : 1,
	]) );
	set( "build", 10478 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"out"       : "/open/clan/sky-wu-chi/room/room441",
		"up"        : "/open/clan/sky-wu-chi/room/room489.c",
		"down"      : "/open/clan/sky-wu-chi/room/room487.c",
	]) );
	set( "long", @LONG

這裡是魔龍塔的第八層，一踏入這裡，四周的殺氣突然濃烈了起來，一
雙雙怖滿殺氣的眼睛正凝視著你。你定了定神後，注意到這個房間的四
周，地上滿怖著刀痕，角落處推滿一堆堆的駭骨，使你不寒兒凜。可是
你又無法抗拒它所散發出來的氣息，深深的被吸引著。
LONG);
	setup();
	replace_program(ROOM);
}
