inherit ROOM;
void create() {
	set( "short", "惋惜洞" );
	set( "owner", "imissyou" );
	set( "object", ([
		"amount10" : 1,
		"file6"    : "/open/killer/obj/fire-knife",
		"amount8"  : 1,
		"amount7"  : 1,
		"amount5"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file7"    : "/open/gblade/obj/sa-head",
		"file3"    : "/open/killer/obj/kill_yar_head",
		"file9"    : "/open/killer/obj/soul-hands",
		"amount2"  : 111,
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"amount6"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount1"  : 1,
		"file2"    : "/open/doctor/pill/sky_pill",
	]) );
	set( "build", 10205 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room437",
	]) );
	set( "long", @LONG
李白從安陸移居山東，在任城安家。又隱居徂徠山，與孔巢父等五人時時酣飲，號稱竹谿六逸。其
間曾回漢、襄一次，並且北遊東都、南陽，返東魯不久，又南下吳越，遇到道士吳筠。天寶元年
(公元742年)在南陵奉召入長安。

LONG);
	setup();
	replace_program(ROOM);
}
