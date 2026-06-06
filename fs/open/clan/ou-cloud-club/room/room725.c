inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$地下室１樓$NOR$" );
	set( "object", ([
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file7"    : "/open/magic-manor/obj/sun-heart",
		"file8"    : "/open/ghost-hole/obj/eq/ghost-helmet",
		"amount1"  : 1,
		"amount5"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount9"  : 1,
		"amount3"  : 1,
		"amount8"  : 1,
		"amount6"  : 1,
		"file1"    : "/obj/gift/hobowdan",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
		"file3"    : "/open/ghost-hole/obj/dark-spirit",
		"amount10" : 1,
		"file9"    : "/obj/gift/bingtang",
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/obj/lunar-heart",
		"amount7"  : 1,
	]) );
	set( "build", 10044 );
	set( "owner", "rayk" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room724",
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
