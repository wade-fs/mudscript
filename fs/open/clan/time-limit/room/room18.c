inherit ROOM;
void create() {
	set( "short", "$HBWHT$史萊哲林走道2$NOR$" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room180.c",
		"west"      : "/open/clan/time-limit/room/room179",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
