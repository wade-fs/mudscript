inherit ROOM;
void create() {
	set( "short", "$BGRN$赫夫帕夫走道3$NOR$" );
	set( "exits", ([
		"south"     : "/open/clan/time-limit/room/room185",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
