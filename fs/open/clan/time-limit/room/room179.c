inherit ROOM;
void create() {
	set( "short", "$HBWHT$史萊哲林走道3$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room18",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
