inherit ROOM;
void create() {
	set( "short", "$BWHT$史萊哲林$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room24.c",
		"north"     : "/open/clan/time-limit/room/room77.c",
		"west"      : "/open/clan/time-limit/room/room180",
	]) );
	set( "long", @LONG
史萊哲林的代表動物是蛇,精明機智的史萊哲林,生活在沼澤泥淖,創辦了史萊
哲林學院,在這裡可以遇到臭味相投的兄弟,那些狡猾多謀的人將會不擇任何
手段,只求達到他們的目的,史萊哲林只挑選足智多謀且具有稀有天賦的學生,
相信他的學生都能利用計謀通過層層的難關

LONG);
	setup();
	replace_program(ROOM);
}
