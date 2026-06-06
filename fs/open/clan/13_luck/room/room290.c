inherit ROOM;
void create() {
	set( "short", "EMC營區大門" );
	set( "object", ([
		"amount9"  : 1,
		"amount10" : 1,
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"file10"   : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"file9"    : "/open/mon/obj/ghost-cloak",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10995 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room284",
	]) );
	set( "long", @LONG
營區大門..除了每天來往的洽公人員..與長官的出入..登記是
一定要的..大門除了兩名衛兵..還有一位哨長..衛兵兩小時一班..
有分單點哨跟雙點哨..都由警衛排安官所帶來上哨..每個衛兵都要
全副武裝以防止敵人的滲入..而且就要叫一分鐘待命班支援了..
LONG);
	setup();
	replace_program(ROOM);
}
