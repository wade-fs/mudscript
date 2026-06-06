inherit ROOM;
void create() {
	set( "short", "阿魯發研究室" );
	set( "owner", "kanon" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount9"  : 5441,
		"amount1"  : 1423,
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"file10"   : "/open/fire-hole/obj/p-pill",
		"file9"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 1203,
		"amount4"  : 6198,
		"amount8"  : 1028,
		"amount2"  : 64,
		"amount6"  : 4991,
		"amount10" : 706,
		"file4"    : "/open/fire-hole/obj/g-pill",
		"file8"    : "/open/ping/obj/poison_pill",
		"file7"    : "/open/fire-hole/obj/y-pill",
		"amount5"  : 598,
		"file5"    : "/open/fire-hole/obj/k-pill",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount7"  : 1317,
		"file6"    : "/open/fire-hole/obj/w-pill",
	]) );
	set( "build", 12024 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room425",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
此間研究所是主要負責研發阿魯發產品,而阿魯發產品即是
阿魯巴產品的兄弟作, 或許你會想問為何要做這個產品呢,因為
該研究所所長發現此產品在FS有無限的商機,故特別襏下金費研
發該產品,相信在不久的將來這個新產品就會上市了。

LONG);
	setup();
	replace_program(ROOM);
}
