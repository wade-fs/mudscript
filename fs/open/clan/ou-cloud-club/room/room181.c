inherit ROOM;
void create() {
	set( "short", "$HIC$落雷坪$NOR$" );
	set( "object", ([
		"amount10" : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount6"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
	]) );
	set( "build", 10313 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room23.c",
		"east"      : "/open/clan/ou-cloud-club/room/room474",
		"south"     : "/open/clan/ou-cloud-club/room/room176.c",
		"north"     : "/open/clan/ou-cloud-club/room/room184",
	]) );
	set( "long", @LONG
震耳欲聾的雷聲在耳邊迴響不已，體內的氣血也因而翻騰
似乎要破體而出，正當你提氣凝神之際，不遠處似乎浮現一道
模糊的人影，手持聚雷杖，身旁刺眼的電光四處亂竄，正是掌
管此處的雷帝『拉姆』，在你還來不及回神之際又消失無蹤‧

左邊是燕飛(cyrryc)的臥龍居，右邊是劉裕(none)居住。

LONG);
	setup();
	replace_program(ROOM);
}
