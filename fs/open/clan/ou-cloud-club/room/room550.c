inherit ROOM;
void create() {
	set( "short", "葵車隊" );
	set( "owner", "aoi" );
	set( "object", ([
		"file4"    : "/open/mon/obj/ghost-helmet",
		"file3"    : "/open/mon/obj/ghost-legging",
		"file9"    : "/open/gblade/obj/sa-head",
		"amount7"  : 1,
		"file8"    : "/open/gblade/obj/sa-head",
		"amount2"  : 1,
		"amount4"  : 1,
		"file7"    : "/open/gblade/obj/sa-head",
		"file6"    : "/open/gblade/obj/sa-head",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"file1"    : "/daemon/class/blademan/obj/shield",
		"amount1"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount3"  : 1,
		"amount10" : 1,
		"file10"   : "/open/gblade/obj/sa-head",
		"amount9"  : 1,
	]) );
	set( "build", 15588 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room533",
	]) );
	set( "long", @LONG
這裡是CF中葵車隊的練車場地以及車隊工廠所在,雖然葵車
隊成績以往並不算很好，不過在新血司馬誠一郎加入後,以他的
實力絕對可以和管生車隊的風見隼人互別苗頭的,也遞補了加賀
再宣布退出賽車界後實力大受影響的車手實力。

LONG);
	setup();
	replace_program(ROOM);
}
