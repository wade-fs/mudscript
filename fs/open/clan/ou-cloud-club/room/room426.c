inherit ROOM;
void create() {
	set( "short", "ctx專屬實驗室入口" );
	set( "object", ([
		"amount10" : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/obj/golden-ball",
		"amount1"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/obj/soil-ball",
		"file3"    : "/open/gsword/obj/may_ring",
		"amount5"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/daemon/class/blademan/obj/shield",
		"file7"    : "/open/magic-manor/obj/water-ball",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/wood-ball",
		"file6"    : "/open/magic-manor/obj/fire-ball",
		"file1"    : "/open/magic-manor/obj/soil-ball",
		"file10"   : "/open/tendo/obj/chaosbelt",
	]) );
	set( "build", 10048 );
	set( "light_up", 1 );
	set( "exits", ([
		"char"      : "/open/clan/ou-cloud-club/room/room533",
		"north"     : "/open/clan/ou-cloud-club/room/room437",
		"enter"     : "/open/clan/ou-cloud-club/room/room425",
	]) );
	set( "long", @LONG
這裡是ctx專屬實驗室大門,裡面擺滿了各種實驗器具,不過
這裡的主人常常發呆不做事,所以裡面的東西大部分只是擺好看
的,至於想要進入裡面觀賞的同好們,請先跟主人報備,如果有未
徵求同意擅自入內的,一律阿魯巴到死。

LONG);
	setup();
	replace_program(ROOM);
}
