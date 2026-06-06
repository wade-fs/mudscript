inherit ROOM;
void create() {
	set( "short", "$HIC$波-健身房(8)$NOR$" );
	set( "object", ([
		"amount2"  : 205,
		"file9"    : "/obj/gift/xisuidan",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 77,
		"file4"    : "/open/fire-hole/obj/p-pill",
		"amount10" : 1,
		"file7"    : "/open/quests/snake/npc/obj/snake-key-2",
		"file8"    : "/open/quests/snake/npc/obj/snake-3",
		"amount5"  : 534,
		"amount8"  : 1,
		"amount1"  : 73,
		"amount9"  : 1,
		"file3"    : "/open/ping/obj/poison_pill",
		"file5"    : "/open/fire-hole/obj/k-pill",
		"amount6"  : 628,
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount7"  : 1,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"file10"   : "/obj/gift/xisuidan",
		"amount4"  : 117,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room327.c",
		"east"      : "/open/clan/ou-cloud-club/room/room318",
	]) );
	set( "owner", "perth" );
	set( "build", 15349 );
	set( "long", @LONG
健身健身健身健身健身健身健身健身健身健身
健身健身健身健身健身健身健身健身健身健身健身
健身健身健身健身健身健身健身健身健身健身健身
健身健身健身健身健身健身健身健身健身健身健身
健身健身健身健身健身健身健身健身健身健身健身
健身健身健身健身健身健身健身健身健身健身健身

LONG);
	setup();
	replace_program(ROOM);
}
