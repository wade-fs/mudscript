inherit ROOM;
void create() {
	set( "short", "$HIY$--虹晶鈗鋮腰帶--$NOR$" );
	set( "light_up", 1 );
	set( "object", ([
		"file2"    : "/open/ping/questsfan/obj/diamond_belt",
		"file3"    : "/open/ping/questsfan/obj/diamond_belt",
		"amount2"  : 1,
		"file1"    : "/open/ping/questsfan/obj/diamond_belt",
		"file4"    : "/open/ping/questsfan/obj/diamond_belt",
		"amount3"  : 1,
		"amount4"  : 1,
		"amount1"  : 1,
	]) );
	set( "build", 13937 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room397",
		"west"      : "/open/clan/ou-cloud-club/room/room391.c",
	]) );
	set( "long", @LONG
鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶
虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶
虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶
虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶
虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶
虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶虹晶鈗鋮腰帶
LONG);
	setup();
	replace_program(ROOM);
}
