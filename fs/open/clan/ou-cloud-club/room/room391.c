inherit ROOM;
void create() {
	set( "short", "--虹晶神行靴--" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_boots",
	]) );
	set( "light_up", 1 );
	set( "build", 27508 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room390",
		"west"      : "/open/clan/ou-cloud-club/room/room392",
	]) );
	set( "long", @LONG
神行靴虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴
虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴
虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴
虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴
虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴
虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴虹晶神行靴
LONG);
	setup();
	replace_program(ROOM);
}
