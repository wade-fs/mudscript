inherit ROOM;
void create() {
	set( "short", "港口" );
	set( "owner", "amdxp" );
	set( "object", ([
		"amount4"  : 1,
		"amount10" : 1,
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"amount8"  : 1,
		"file7"    : "/open/killer/obj/k_ring",
		"amount1"  : 1,
		"file2"    : "/open/ghost-hole/obj/fire-spirit",
		"file3"    : "/open/ghost-hole/obj/fire-spirit",
		"file5"    : "/open/ghost-hole/obj/fire-spirit",
		"amount2"  : 1,
		"file1"    : "/obj/gift/bingtang",
		"amount7"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"amount3"  : 1,
	]) );
	set( "build", 10092 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room31",
		"enter"     : "/open/clan/13_luck/room/room29.c",
	]) );
	set( "long", @LONG

    這裡是可以搭船去日郡的唯一水路，港口邊停了幾艘小船，妳向
船家租了一艘船，一個人自由自在的漂泊在海上，吹著涼涼的海風，
哇！！是多麼浪漫愜意的事，當妳準備要啟程時，你看了看海面上的
波浪，發現似乎好像有一定的規律，妳猜想著難道這片海有被下過陣
法。

LONG);
	setup();
	replace_program(ROOM);
}
