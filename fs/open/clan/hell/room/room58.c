inherit ROOM;
void create() {
	set( "short", "神之左手" );
	set( "object", ([
		"file2"    : "/open/ping/obj/gold_hand",
		"file1"    : "/open/ping/obj/chilin_legging",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 10133 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room25",
		"east"      : "/open/clan/hell/room/room62",
	]) );
	set( "long", @LONG
     
        一進入這裡，立刻被一股溫暖的氣勁所包圍，除此之外還有一股聖潔
        不可侵犯的氣勢，而目光馬上被眼前的一座雕像(statue)所吸引，只
        見雕像全身穿滿前所未見的神聖裝備，突然四周所有的力量及裝備結
        合在你的身上，你感覺到自己有一個重大的使命及擁有天神般的力量


LONG);
	setup();
	replace_program(ROOM);
}
