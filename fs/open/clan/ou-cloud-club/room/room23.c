inherit ROOM;
void create() {
	set( "short", "水澗香泉" );
	set( "owner", "cyrryc" );
	set( "object", ([
		"file1"    : "/open/mon/obj/thousand-nectar",
		"amount6"  : 1,
		"amount7"  : 127,
		"amount8"  : 1,
		"file6"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"file5"    : "/open/mon/obj/mon-pill",
		"amount10" : 1,
		"file2"    : "/obj/gift/xisuidan",
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"amount1"  : 1,
		"amount2"  : 1,
		"amount5"  : 90,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount4"  : 20,
	]) );
	set( "build", 10405 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room181",
	]) );
	set( "long", @LONG

    森林間有一大片房舍般建築,建造的形式頗為別緻,屋子蓋的
不高,從上面望下去看不太清楚,但似乎頂多兩層,可是佔地卻不小
,先是長條形的房舍各自成圈,圍成一組內有長方形空地的集合,而
這樣的四組屋群又分佔四面,只見到屋頂上一塊塊黑色東西斜躺堆
疊,十分整齊規律

LONG);
	setup();
	replace_program(ROOM);
}
