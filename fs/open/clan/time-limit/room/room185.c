inherit ROOM;
void create() {
	set( "short", "$BGRN$赫夫帕夫走道2$NOR$" );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room184",
		"south"     : "/open/clan/time-limit/room/room186.c",
	]) );
	set( "long", @LONG
此地初建, 空無一物。
LONG);
	setup();
	replace_program(ROOM);
}
