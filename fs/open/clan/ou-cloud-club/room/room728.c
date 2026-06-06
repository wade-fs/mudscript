inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$地下室１樓$NOR$" );
	set( "object", ([
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount9"  : 1,
		"file2"    : "/open/gsword/obj1/bpball",
		"amount8"  : 1,
		"amount5"  : 1,
		"amount10" : 1,
		"file10"   : "/open/gsword/obj1/bbladeball",
		"file5"    : "/open/gsword/obj1/bpball",
		"file1"    : "/open/gsword/obj1/bpball",
		"amount7"  : 1,
		"file9"    : "/open/gsword/obj1/bbladeball",
		"file8"    : "/open/gsword/obj1/bbladeball",
		"file7"    : "/open/gsword/obj1/bbladeball",
		"amount2"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"file4"    : "/open/gsword/obj1/bpball",
	]) );
	set( "build", 10002 );
	set( "owner", "rayk" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room724",
	]) );
	set( "long", @LONG

    看來Ｒａｙｋ似乎真的不是善於整理空間的人，偌大的地下室也
堆疊的亂七八糟、不堪入目，而且上面居然還布滿了厚厚的一堆灰塵
，不禁讓人懷疑這裡真的是Ｒａｙｋ收藏許多神兵利器以及各門各派
武學秘笈的地方嗎？

LONG);
	setup();
	replace_program(ROOM);
}
