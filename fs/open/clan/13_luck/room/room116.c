inherit ROOM;
void create() {
	set( "short", "藏龍閣" );
	set( "owner", "papt" );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room62.c",
	]) );
	set( "long", @LONG
龍，狂想空間中的一位傳奇人物，有著高深莫測的武學修
詣，但當其在狂想中成為第一個將武學修為突破成學究天人的
同時，他也就像在人世間蒸發般，使人無法得知其去像，卻原
來是隱居在十三吉祥中的相思林中，過著隱士般的生活．

LONG);
	setup();
	replace_program(ROOM);
}
