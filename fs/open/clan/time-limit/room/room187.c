inherit ROOM;
void create() {
	set( "short", "$HBRED$葛來分多走道3$NOR$" );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room188",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
