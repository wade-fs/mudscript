inherit ROOM;
void create() {
	set( "short", "水雲廳" );
	set( "build", 10512 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room524",
	]) );
	set( "long", @LONG
這裡散發一股浩然正氣，正前方的水晶翠玉壁上刻了一幅『飛龍在
天』圖，圖中龍栩栩如生，兩眼似發出寒光，氣勢高傲，象徵所向無敵
。而廳堂兩旁陳列著許多上等檀木打造的太師椅，看似整齊，其實是依
照著五行八卦陣來排列。四周看去，如此排場，心裡不免一陣讚嘆。
LONG);
	setup();
	replace_program(ROOM);
}
