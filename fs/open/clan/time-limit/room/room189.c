inherit ROOM;
void create() {
	set( "short", "$HBRED$葛來分多走道1$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room254",
		"west"      : "/open/clan/time-limit/room/room83",
		"east"      : "/open/clan/time-limit/room/room188",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
