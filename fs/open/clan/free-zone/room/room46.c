inherit ROOM;
void create() {
	set( "short", "雷峰試煉塔二樓" );
	set( "object", ([
		"file1"    : "/open/center/obj/mechoufen-head",
		"file3"    : "/open/center/obj/mechoufen-head",
		"file4"    : "/open/center/obj/mechoufen-head",
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount1"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10037 );
	set( "exits", ([
		"up"        : "/open/clan/free-zone/room/room48",
		"down"      : "/open/clan/free-zone/room/room44.c",
		"north"     : "/open/clan/free-zone/room/room47.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
