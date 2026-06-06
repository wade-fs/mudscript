inherit ROOM;
void create() {
	set( "short", "- (弒羽皇天)" );
	set( "owner", "coling" );
	set( "light_up", 1 );
	set( "build", 10130 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room477",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"east"      : "/open/clan/sky-wu-chi/room/room476.c",
	]) );
	set( "long", @LONG
空氣中飄散著清新的香氣，兩旁的楓樹輕舞搖擺著。在這花瓣與
楓葉漫天飛舞著同時，你似乎在楓樹中隱約看見一位天仙，那輕巧的
身影在你眼中牢牢印住。她的身旁插著十二把神兵，據說每一把都是
能毀天滅地的古代神武，而她，就是傳說中的最強刀客『玫緹

LONG);
	setup();
	replace_program(ROOM);
}
