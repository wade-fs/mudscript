inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$地下室１樓$NOR$" );
	set( "object", ([
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"file7"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount5"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/magic-manor/wood/obj/wood-sword",
		"file10"   : "/open/magic-manor/soil/obj/soil-claw",
		"file3"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount10" : 1,
		"file6"    : "/open/magic-manor/wood/obj/wood-sword",
		"amount8"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"amount7"  : 1,
		"file9"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
	]) );
	set( "build", 10020 );
	set( "owner", "rayk" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room724",
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
