inherit ROOM;
void create() {
	set( "short", "天璣堂大門" );
	set( "object", ([
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount1"  : 1,
		"amount5"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/ping/obj/iceger",
		"file1"    : "/open/ping/obj/iceger",
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file5"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"file3"    : "/open/gblade/obj/sa-head",
		"amount9"  : 1,
		"file2"    : "/open/ping/obj/iceger",
		"amount7"  : 1,
		"file7"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "owner", "aaabc" );
	set( "build", 12152 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room519.c",
		"enter"     : "/open/clan/13_luck/room/room510",
		"east"      : "/open/clan/13_luck/room/room521.c",
	]) );
	set( "long", @LONG
你在不知不覺中走到了一個大門口，在此地你感到空氣中迷漫著濃
濃的殺氣，使你渾身覺得很不舒服，在門上懸掛著一個水晶匾，上面寫
著「天璣堂」三個大字．這才恍然大悟原來這裡便是武林傳說中的殺手
重地之一，在門兩旁的守衛也冷冷地瞧了你一眼，令人覺得膽顫心驚，
在往前走便是大廳，但由於此地濃厚的殺氣，使人沒有繼續走下去的勇
氣。
LONG);
	setup();
	replace_program(ROOM);
}
