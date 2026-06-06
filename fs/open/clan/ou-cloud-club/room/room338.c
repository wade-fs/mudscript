inherit ROOM;
void create() {
	set( "short", "ω冥魔帝冠ω" );
	set( "object", ([
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file6"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount1"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"file7"    : "/open/magic-manor/obj/evil-kill-claw",
		"file8"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount8"  : 1,
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file1"    : "/open/magic-manor/obj/dark-soul-dagger",
	]) );
	set( "owner", "enter" );
	set( "build", 10477 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room339",
		"west"      : "/open/clan/ou-cloud-club/room/room337",
	]) );
	set( "long", @LONG

        ω冥魔帝冠ω
        ω冥魔帝冠ω
        ω冥魔帝冠ω
        ω冥魔帝冠ω
        ω冥魔帝冠ω
        ω冥魔帝冠ω
        ω冥魔帝冠ω
        ω冥魔帝冠ω
        ω冥魔帝冠ω
        ω冥魔帝冠ω

LONG);
	setup();
	replace_program(ROOM);
}
