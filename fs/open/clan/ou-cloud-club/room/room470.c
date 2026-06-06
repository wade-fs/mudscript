inherit ROOM;
void create() {
	set( "short", "懶趴熊的雜物堆" );
	set( "object", ([
		"amount4"  : 15,
		"amount8"  : 210,
		"amount1"  : 163,
		"file9"    : "/obj/stone/suipian",
		"file5"    : "/open/fire-hole/obj/p-pill",
		"file2"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 357,
		"amount5"  : 195,
		"amount10" : 254,
		"file4"    : "/obj/stone/jiao",
		"amount9"  : 7,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file6"    : "/obj/stone/powder",
		"amount2"  : 162,
		"file7"    : "/open/fire-hole/obj/w-pill",
		"file10"   : "/open/fire-hole/obj/r-pill",
		"amount6"  : 34,
		"file1"    : "/open/fire-hole/obj/k-pill",
		"amount7"  : 266,
		"file8"    : "/open/fire-hole/obj/y-pill",
	]) );
	set( "owner", "sula" );
	set( "build", 10008 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room135",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
 
    這是一間不起眼的小閣樓，，地上凌亂地堆了一些有的沒的東西，讓
走進這的人連站的地方都沒有。實在是因為趴趴熊太懶了，一回到家後就
把在路上撿到的垃圾當寶物藏起來，沒分類也更沒清洗，只看到滿天飛舞
的蒼蠅和蚊子在你耳邊嗡嗡地叫，讓人只想趕快離開這裡。

LONG);
	setup();
	replace_program(ROOM);
}
