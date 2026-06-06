inherit ROOM;
void create() {
	set( "short", "$HIC$波-桌球室(6)$NOR$" );
	set( "object", ([
		"amount2"  : 1,
		"file6"    : "/open/killer/obj/s_pill",
		"file8"    : "/obj/gift/hobowdan",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file10"   : "/obj/gift/xiandan",
		"amount10" : 1,
		"amount8"  : 1,
		"amount7"  : 1,
		"amount1"  : 80,
		"file5"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"amount6"  : 500,
		"file3"    : "/obj/gift/hobowdan",
		"file9"    : "/open/fire-hole/obj/y-pill",
		"file2"    : "/open/quests/snake/npc/obj/snake-3",
		"amount5"  : 1,
		"amount3"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"file7"    : "/obj/gift/xisuidan",
		"amount9"  : 8,
	]) );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room325.c",
		"north"     : "/open/clan/ou-cloud-club/room/room327",
		"east"      : "/open/clan/ou-cloud-club/room/room174.c",
	]) );
	set( "owner", "perth" );
	set( "build", 11146 );
	set( "long", @LONG
  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓
乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓
乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓
乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓
乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓
乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓  乒乓

LONG);
	setup();
	replace_program(ROOM);
}
