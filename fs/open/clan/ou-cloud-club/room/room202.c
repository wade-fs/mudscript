inherit ROOM;
void create() {
	set( "short", "千羽居" );
	set( "owner", "peasant" );
	set( "object", ([
		"file8"    : "/open/killer/obj/bellstar",
		"amount10" : 1000,
		"file3"    : "/open/magic-manor/obj/water-ball",
		"file2"    : "/open/ghost-hole/obj/wind-spirit",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 363,
		"amount8"  : 2768,
		"file10"   : "/open/killer/obj/hate_knife",
		"amount2"  : 1,
		"file9"    : "/open/killer/headkill/obj/world_dag",
		"amount6"  : 1,
		"amount3"  : 1,
		"amount4"  : 123,
		"file1"    : "/open/killer/obj/atman_pill",
		"file4"    : "/open/mon/obj/mon-pill",
		"amount5"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10024 );
	set( "item_desc", ([
		"漂亮的海" : @ITEM
ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room125.c",
	]) );
	set( "long", @LONG
這是段家小子lnergy的家,
他是水手出身,水上功夫了得.
素有浪裡白龍之稱,一張俊俏
的臉,深受眾女子的愛慕
他與懶蟲是生死之交...一同
闖蕩江湖多年,最近生出退隱
之心,在這個風光明媚的湖邊
搭起這間草廬,做其退隱之處
LONG);
	setup();
	replace_program(ROOM);
}
