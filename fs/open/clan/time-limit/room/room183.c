inherit ROOM;
void create() {
	set( "short", "$BYEL$雷文克勞走道1$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room81",
		"south"     : "/open/clan/time-limit/room/room182",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
