inherit ROOM;
void create() {
	set( "short", "$HIC$落雷坪$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"amount9"  : 1,
		"amount1"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount7"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"amount3"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10032 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room183.c",
		"north"     : "/open/clan/ou-cloud-club/room/room193",
		"east"      : "/open/clan/ou-cloud-club/room/room192.c",
		"south"     : "/open/clan/ou-cloud-club/room/room181.c",
	]) );
	set( "long", @LONG
震耳欲聾的雷聲在耳邊迴響不已，體內的氣血也因而翻騰，
似乎要破體而出，正當你提氣凝神之際，不遠處似乎浮現一道模
糊的人影，手持聚雷杖，身旁刺眼的電光四處亂竄，正是掌管此
處的雷帝『拉姆』，在你還來不及回神之際又消失無蹤‧

左邊是團長(aspsa)的黃金梅麗號甲板，右方則是張拾來(assassin)的神秘地帶．

LONG);
	setup();
	replace_program(ROOM);
}
