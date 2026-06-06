inherit ROOM;
void create() {
	set( "short", "$HIC$--虹晶雙翼鎧--$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"amount2"  : 1,
		"file2"    : "/open/ping/questsfan/obj/diamond_armor",
		"amount3"  : 1,
		"amount1"  : 1,
		"file3"    : "/open/ping/questsfan/obj/diamond_armor",
		"amount4"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_armor",
		"file4"    : "/open/ping/questsfan/obj/diamond_armor",
	]) );
	set( "build", 10324 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room396.c",
		"west"      : "/open/clan/ou-cloud-club/room/room394",
	]) );
	set( "long", @LONG
雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧
虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧
虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧
虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧
虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧
虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧虹晶雙翼鎧
LONG);
	setup();
	replace_program(ROOM);
}
