inherit ROOM;
void create() {
	set( "short", "風的故鄉" );
	set( "owner", "warhammer" );
	set( "object", ([
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"amount4"  : 1,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"file1"    : "/open/firedancer/npc/eq/r_hands",
		"amount2"  : 18,
		"file8"    : "/open/gsword/obj1/bpball",
		"amount1"  : 1,
		"file9"    : "/open/ghost-hole/obj/light-spirit",
		"file4"    : "/open/ghost-hole/obj/light-spirit",
		"file3"    : "/open/firedancer/npc/eq/r_boots",
		"file5"    : "/open/gsword/obj1/bpball",
		"amount3"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10171 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room442",
		"north"     : "/open/clan/ou-cloud-club/room/room552",
		"west"      : "/open/clan/ou-cloud-club/room/room172.c",
	]) );
	set( "long", @LONG

微風輕輕的吹拂著, 令你感到無比的舒暢, 這裡正是傳說中的

$HIC$                 ╭╦═════╦╯
                   ║╭═╦═╯║
                   ║╭═╬═╮║
                   ║║  ║  ║║
                   ║╰═╬═╯║
                 ╰╯══╩═╣╰╯$NOR$

                                         -=風的故鄉=-

LONG);
	setup();
	replace_program(ROOM);
}
