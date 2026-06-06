inherit ROOM;
void create() {
	set( "short", "$HIG$--虹晶識皇披風--$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_cloak",
	]) );
	set( "light_up", 1 );
	set( "build", 10506 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room392",
		"out"       : "/open/clan/ou-cloud-club/room/room162.c",
		"west"      : "/open/clan/ou-cloud-club/room/room395.c",
	]) );
	set( "long", @LONG
識皇披風虹晶識皇披風虹晶識皇披風虹晶識皇披風
虹晶識皇披風虹晶識皇披風虹晶識皇披風虹晶識皇披風
虹晶識皇披風虹晶識皇披風虹晶識皇披風虹晶識皇披風
虹晶識皇披風虹晶識皇披風虹晶識皇披風虹晶識皇披風
虹晶識皇披風虹晶識皇披風虹晶識皇披風虹晶識皇披風
虹晶識皇披風虹晶識皇披風虹晶識皇披風虹晶識皇披風

LONG);
	setup();
	replace_program(ROOM);
}
