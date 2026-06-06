inherit ROOM;
void create() {
	set( "short", "秋陽流" );
	set( "owner", "amdxp" );
	set( "object", ([
		"file6"    : "/open/magic-manor/obj/master_snake_head",
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/killer/outsea/dstone",
		"amount1"  : 56,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 188,
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount3"  : 1,
	]) );
	set( "build", 10033 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room28",
		"east"      : "/open/clan/13_luck/room/room26.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    你已經到了吉祥水道的正中央了，你看看四周覺得綠意盎然水道邊
有不少的小孩在嘻戲著，令你想起自己小時的種種，歷歷在目，當你一
回神發現四周的景象慢慢變了，綠葉稍稍轉紅宛如入秋，你稍微拉拉衣
服，你覺得天氣有點轉涼了，這裡是十三吉祥著名的秋陽流只要過了這
，秋天氣息就非常濃了。

LONG);
	setup();
	replace_program(ROOM);
}
