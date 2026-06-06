inherit ROOM;
void create() {
	set( "short", "偶滴偶滴" );
	set( "object", ([
		"file8"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount7"  : 1,
		"file7"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"amount10" : 1,
		"file10"   : "/open/magic-manor/ghost/obj/trigram-pill",
		"file9"    : "/open/gsword/obj1/karmband",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/wu/obj/ya-head",
	]) );
	set( "build", 10008 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room212",
		"west"      : "/open/clan/sky-wu-chi/room/room45.c",
		"south"     : "/open/clan/sky-wu-chi/room/room117.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room124.c",
	]) );
	set( "long", @LONG
這是偶滴地方~~~~~~~這是偶滴地方~~~~~~~這是偶滴地方~~~~~~~
    這是偶滴地方~~~~~~~這是偶滴地方~~~~~~~這是偶滴地方~~~~~~~
    這是偶滴地方~~~~~~~這是偶滴地方~~~~~~~這是偶滴地方~~~~~~~
    這是偶滴地方~~~~~~~這是偶滴地方~~~~~~~這是偶滴地方~~~~~~~
      west ckkks    east marco    south ray    north ilike
LONG);
	setup();
	replace_program(ROOM);
}
