inherit ROOM;
void create() {
	set( "short", "$HIC$傲$HIW$雲$HIY$閤$HIG$三樓$HIM$中庭$NOR$" );
	set( "object", ([
		"file6"    : "/open/magic-manor/obj/fire-ball",
		"amount9"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/magic-manor/obj/water-ball",
		"amount5"  : 1,
		"file7"    : "/open/magic-manor/obj/fire-ball",
		"amount1"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/magic-manor/obj/water-ball",
		"file5"    : "/open/magic-manor/obj/wood-ball",
		"file10"   : "/open/magic-manor/obj/water-ball",
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/obj/wood-ball",
		"file8"    : "/open/magic-manor/obj/wood-ball",
		"file1"    : "/open/magic-manor/obj/wood-ball",
		"amount8"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
	]) );
    set( "item_desc", ([
		"empire_sword" : @ITEM

正當你凝視這把長劍的時候，劍端的紋章化成無數的光點 ，
慢慢的在你的眼前凝聚成細小的文字 ...

東邊：海龍利拜亞桑之海潮之聲
西邊：炎獸伊弗利特之火焰之舞
南邊：雷帝拉姆掌管之落雷坪
北邊：戰神奧丁掌管之戰神道

ITEM,

    ]) );
	set( "build", 11143 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room441.c",
		"north"     : "/open/clan/ou-cloud-club/room/room211.c",
		"down"      : "/open/clan/ou-cloud-club/room/room118",
		"up"        : "/open/clan/ou-cloud-club/room/room479",
		"south"     : "/open/clan/ou-cloud-club/room/room193.c",
		"west"      : "/open/clan/ou-cloud-club/room/room419.c",
	]) );
	set( "long", @LONG
傲雲山莊的三樓，東西南北延伸過去都是寬大的走道，透露
著肅穆莊嚴的氣氛，令你不敢在此嘻鬧，因此正在休息的傲雲幫
眾們都能得到充分的休息，或許正是傲雲提供如此舒適的地方，
使得幫眾們練功事半功倍，也得以維持住幫派龍頭的地位。

在你正前方放著一把刻有鷹獅紋章的皇家聖劍(Empire_sword)‧

LONG);
	setup();
	replace_program(ROOM);
}
