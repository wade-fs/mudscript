inherit ROOM;
void create() {
	set( "short", "$HIW$絕境冰壁$NOR$" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount1"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount10" : 1,
		"amount6"  : 1,
		"file1"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file9"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount5"  : 1,
		"file3"    : "/open/magic-manor/water/obj/water-ribbon",
		"file8"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount8"  : 1,
		"amount2"  : 1,
		"file10"   : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
	]) );
	set( "build", 12195 );
	set( "item_desc", ([
		"jon_snow" : @ITEM
臨冬城主艾德‧史塔克的私生子，有著與史塔克家族相同削
瘦但俊俏的臉孔，年紀約莫在二十五左右，身後斜掛著一把
長柄劍，名曰『長爪』，劍柄圓球用琥珀雕成的狼頭形狀，
劍刃則是以瓦雷利亞鋼打造而成，兼具著輕盈及銳利。

ITEM,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room736",
		"east"      : "/open/clan/ou-cloud-club/room/room735.c",
		"south"     : "/open/clan/ou-cloud-club/room/room197.c",
	]) );
	set( "long", @LONG
阻擋在你眼前的是一座數百呎的冰封絕壁，冰壁的顏色隨著
光線移動而改變，有時是河流凍結時的深藍，有時是堆積陳雪的
污白，若有流雲蔽日，則又黯淡無光，成了表面凹陷的淺灰色岩
石。當冰壁隨日光而成透明有如琉璃之時，你彷彿看見冰壁的另
一頭有座高聳入雲的城堡存在另一個未知的世界裡。

  守夜人軍團首席遊騎兵 瓊恩‧雪諾(Jon_snow)

LONG);
	setup();
	replace_program(ROOM);
}
