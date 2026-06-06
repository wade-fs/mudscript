inherit ROOM;
void create() {
	set( "short", "天杖堂大門" );
	set( "object", ([
		"amount3"  : 1,
		"file2"    : "/open/mon/obj/ghost-cloak",
		"amount1"  : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
		"file3"    : "/open/mon/obj/ghost-cloak",
		"amount2"  : 1,
	]) );
	set( "build", 10059 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room516.c",
		"enter"     : "/open/clan/13_luck/room/room504",
		"east"      : "/open/clan/13_luck/room/room514.c",
	]) );
	set( "long", @LONG
你在不知不覺中走到了一個大門口，在此地你感到空氣中迷漫著濃
濃的殺氣，使你渾身覺得很不舒服，在門上懸掛著一個水晶匾，上面寫
著「天杖堂」三個大字．這才恍然大悟原來這裡便是武林傳說中的殺手
重地之一，在門兩旁的守衛也冷冷地瞧了你一眼，令人覺得膽顫心驚，
在往前走便是大廳，但由於此地濃厚的殺氣，使人沒有繼續走下去的勇
氣。
LONG);
	setup();
	replace_program(ROOM);
}
