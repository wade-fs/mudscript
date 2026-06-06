inherit ROOM;
void create() {
	set( "short", "血痕居-俠客廳" );
	set( "owner", "holeman" );
	set( "build", 10189 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room518.c",
		"west"      : "/open/clan/sky-wu-chi/room/room520.c",
		"northeast" : "/open/clan/sky-wu-chi/room/room525",
		"northwest" : "/open/clan/sky-wu-chi/room/room524",
		"southeast" : "/open/clan/sky-wu-chi/room/room527",
		"north"     : "/open/clan/sky-wu-chi/room/room522.c",
		"south"     : "/open/clan/sky-wu-chi/room/room514.c",
		"east"      : "/open/clan/sky-wu-chi/room/room521.c",
		"southwest" : "/open/clan/sky-wu-chi/room/room526",
	]) );
	set( "long", @LONG

趙客縵胡纓，吳鉤霜雪明。銀鞍照白馬，瘋沓如流星。

十步殺一人，千裡不留行。事了拂衣去，深藏身與名。

閑過信陵飲，脫劍膝前橫。將炙啖朱亥，持觴勸侯嬴。

三杯吐然諾，五岳倒為輕。眼花耳熱後，意氣素霓生。

救趙揮金錘，邯鄲先震驚。千秋二壯士，烜赫大梁城。

縱死俠骨香，不慚世上英。誰能書閣下，白首太玄經？



LONG);
	setup();
	replace_program(ROOM);
}
