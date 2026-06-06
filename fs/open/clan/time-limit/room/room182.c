inherit ROOM;
void create() {
	set( "short", "$BYEL$雷文克勞走道2$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room183.c",
		"south"     : "/open/clan/time-limit/room/room181",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
