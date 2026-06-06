inherit ROOM;
void create() {
	set( "short", "盤龍池" );
	set( "owner", "mill" );
	set( "object", ([
		"file10"   : "/open/mogi/castle/obj/seven1-dark-head",
		"amount10" : 1,
		"amount8"  : 1,
		"file3"    : "/obj/stone/suipian",
		"amount4"  : 1,
		"file6"    : "/obj/gift/shenliwan",
		"amount5"  : 1,
		"amount7"  : 1,
		"amount3"  : 32,
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 48,
		"file8"    : "/open/gsword/obj1/blosword",
		"file1"    : "/obj/stone/jiao",
		"amount2"  : 388,
		"file2"    : "/obj/stone/powder",
		"file7"    : "/open/mogi/castle/obj/fire-king-head",
		"file4"    : "/open/ghost-hole/obj/fire-spirit",
		"amount6"  : 1,
	]) );
	set( "build", 10250 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room183",
		"south"     : "/open/clan/13_luck/room/room496.c",
	]) );
	set( "long", @LONG

　　此池畔柳煙溿然，一時間翠綠相映，池石刻雕龍游百狀，水光瀲
豔如星點。又觀水上，蓮荷交妍，蘆花飄飄，蜻蜓點水，湖面如鏡風
吹不漪，水洇氤氳，一字涼。此處水氣縱橫，泉湧不休，頗有生生不
息循環之氣。卻不知水源的源頭在何方。

LONG);
	setup();
	replace_program(ROOM);
}
