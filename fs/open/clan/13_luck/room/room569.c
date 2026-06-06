inherit ROOM;
void create() {
	set( "short", "水雲廳" );
	set( "owner", "roarii" );
	set( "object", ([
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"file6"    : "/open/capital/guard/gring",
		"file1"    : "/open/capital/guard/gring",
		"file4"    : "/open/capital/guard/gring",
		"file2"    : "/open/capital/guard/gring",
		"amount6"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/sky/obj/lucky_grasslink",
		"amount10" : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file5"    : "/open/capital/guard/gring",
		"file3"    : "/open/capital/guard/gring",
	]) );
	set( "build", 13075 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room576.c",
		"down"      : "/open/clan/13_luck/room/room567",
		"up"        : "/open/clan/13_luck/room/room568.c",
	]) );
	set( "long", @LONG
這裡散發一股浩然正氣，正前方的水晶翠玉壁上刻了一幅『飛
龍在天』圖，圖中龍栩栩如生，兩眼似發出寒光，氣勢高傲，象徵
所向無敵。而廳堂兩旁陳列著許多上等檀木打造的太師椅，看似整
齊，其實是依五行八卦陣排列。四周看去，如此排場，心裡不免一
LONG);
	setup();
	replace_program(ROOM);
}
