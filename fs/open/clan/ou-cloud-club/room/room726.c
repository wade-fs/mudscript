inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$地下室１樓$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/capital/obj/force_book",
		"file9"    : "/open/capital/obj/blade_book",
		"amount4"  : 1,
		"file4"    : "/open/capital/obj/sword_book",
		"amount2"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/capital/obj/fist_book",
		"file1"    : "/open/gsword/obj1/blosword",
		"amount5"  : 1,
		"amount10" : 20,
		"file10"   : "/open/mon/obj/thousand-nectar",
		"file8"    : "/open/capital/obj/steps_book",
		"file5"    : "/obj/gift/hobowdan",
		"file6"    : "/open/mogi/castle/obj/fire-king-head",
		"amount3"  : 1,
		"file7"    : "/obj/gift/lingzhi",
		"amount6"  : 1,
	]) );
	set( "build", 10044 );
	set( "owner", "rayk" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room724",
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
