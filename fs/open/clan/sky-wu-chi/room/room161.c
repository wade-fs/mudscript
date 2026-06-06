inherit ROOM;
void create() {
	set( "short", "天涯海閣" );
	set( "owner", "cong" );
	set( "object", ([
		"file8"    : "/open/capital/obj/blade2",
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount8"  : 1,
		"file1"    : "/open/badman/obj/sword_book",
		"amount2"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"amount5"  : 1,
		"file4"    : "/open/magic-manor/gold/obj/golden-blade",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10160 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"up"        : "/open/clan/sky-wu-chi/room/room240.c",
		"down"      : "/open/clan/sky-wu-chi/room/room315.c",
		"north"     : "/open/clan/sky-wu-chi/room/room239.c",
		"south"     : "/open/clan/sky-wu-chi/room/room217.c",
	]) );
	set( "long", @LONG
這裡是一代舞者----$MAG$夢魂殘星$NOR$----隱居避世的地方。當經過
了重重的考驗之後，夢魂殘星深深感到江湖險惡、人心難測。同
時也深感武學的浩瀚無涯。因此隱居在此，不理俗世雜務，全心
投入鑽研更高深的武學，以其所學來傳承舞者一脈。
LONG);
	setup();
	replace_program(ROOM);
}
