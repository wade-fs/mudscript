inherit ROOM;
void create() {
	set( "short", "種族及國家3" );
	set( "owner", "dfyw" );
	set( "object", ([
		"file10"   : "/obj/gift/bingtang",
		"amount7"  : 1,
		"amount3"  : 1,
		"file9"    : "/obj/gift/bingtang",
		"file1"    : "/obj/gift/bingtang",
		"amount8"  : 1,
		"file4"    : "/obj/gift/bingtang",
		"amount4"  : 1,
		"file3"    : "/obj/gift/bingtang",
		"amount9"  : 1,
		"amount2"  : 1,
		"file8"    : "/obj/gift/lingzhi",
		"file6"    : "/obj/gift/bingtang",
		"amount1"  : 1,
		"amount10" : 1,
		"amount5"  : 1,
		"file2"    : "/obj/gift/bingtang",
		"amount6"  : 1,
		"file7"    : "/obj/gift/lingzhi",
		"file5"    : "/obj/gift/bingtang",
	]) );
	set( "build", 10047 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room440",
	]) );
	set( "long", @LONG

獸人
全身長滿毛的種族。普遍來說，文明的水平較低，有相當強烈的排他情節，不喜
和其他種族來往。

大樹海弗雷斯特
弗雷斯特原本是指獸人族南方的森林地區--大樹海，也就是依伯爾大陸南方的森
林地帶。人類擴展版圖、砍伐森林、開闢新市鎮與耕地後，獸人也開始與人類對
抗的長期戰爭。獸人為母系社會，以女性團體為家族單位，現任領道者為多娜。

LONG);
	setup();
	replace_program(ROOM);
}
