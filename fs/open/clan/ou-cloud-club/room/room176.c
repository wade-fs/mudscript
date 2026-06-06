inherit ROOM;
void create() {
	set( "short", "$HIC$落雷坪$NOR$" );
	set( "object", ([
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"amount10" : 1,
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount2"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount9"  : 1,
	]) );
	set( "build", 10041 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room173.c",
		"north"     : "/open/clan/ou-cloud-club/room/room181.c",
		"east"      : "/open/clan/ou-cloud-club/room/room179.c",
	]) );
	set( "long", @LONG
震耳欲聾的雷聲在耳邊迴響不已，體內的氣血也因而翻騰
似乎要破體而出，正當你提氣凝神之際，不遠處似乎浮現一道
模糊的人影，手持聚雷杖，身旁刺眼的電光四處亂竄，正是掌
管此處的雷帝『拉姆』，在你還來不及回神之際又消失無蹤‧

左邊是無奇(slayer)的臥房，右邊則是幸福(palla)的幸福泉源．

LONG);
	setup();
	replace_program(ROOM);
}
