inherit ROOM;
void create() {
	set( "short", "$HIY$Ｒａｙｋ$HIW$的$HIC$地下室１Ｆ$NOR$" );
	set( "object", ([
		"amount1"  : 1,
		"amount7"  : 1,
		"amount2"  : 1714,
		"file2"    : "/open/killer/obj/atman_pill",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file4"    : "/obj/gift/xiandan",
		"amount8"  : 1,
		"amount9"  : 1,
		"file3"    : "/open/capital/obj/steps_book",
		"file1"    : "/open/capital/obj/force_book",
		"amount5"  : 1,
		"file8"    : "/open/capital/obj/sword_book",
		"file10"   : "/open/capital/obj/blade_book",
		"amount10" : 1,
		"file5"    : "/obj/gift/unknowdan",
		"file6"    : "/open/clan/area/home/hae_bag",
		"amount3"  : 1,
		"file7"    : "/open/capital/obj/fist_book",
		"amount6"  : 1,
	]) );
	set( "build", 10002 );
	set( "owner", "rayk" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room725.c",
		"south"     : "/open/clan/ou-cloud-club/room/room727.c",
		"up"        : "/open/clan/ou-cloud-club/room/room430",
		"down"      : "/open/clan/ou-cloud-club/room/room756",
		"north"     : "/open/clan/ou-cloud-club/room/room728",
		"west"      : "/open/clan/ou-cloud-club/room/room726.c",
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
