inherit ROOM;
void create() {
	set( "short", "$HBRED$葛來分多走道2$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room187",
		"west"      : "/open/clan/time-limit/room/room189.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
