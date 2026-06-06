inherit ROOM;
void create() {
	set( "short", "剛強的A片收藏室" );
	set( "object", ([
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount4"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/mogi/dragon/obj/dragon-head",
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
		"amount10" : 1,
		"amount3"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file10"   : "/open/magic-manor/obj/master_snake_head",
	]) );
	set( "build", 10086 );
	set( "light_up", 1 );
	set( "owner", "roboii" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room505",
	]) );
	set( "long", @LONG

壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹壹

枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝枝

筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆筆

哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦哦
啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊啊
LONG);
	setup();
	replace_program(ROOM);
}
