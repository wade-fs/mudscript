inherit ROOM;
void create() {
	set( "short", "$YEL$--虹晶狂牙手套--$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/ping/questsfan/obj/diamond_hands",
		"file3"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount2"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_hands",
		"file4"    : "/open/ping/questsfan/obj/diamond_hands",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 12194 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room390",
	]) );
	set( "long", @LONG
狂牙手套虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套
虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套
虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套
虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套
虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套
虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套虹晶狂牙手套
LONG);
	setup();
	replace_program(ROOM);
}
