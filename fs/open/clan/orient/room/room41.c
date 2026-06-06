inherit ROOM;
void create() {
	set( "short", "$HIW$『$HIY$風郡主室$HIW$』$NOR$" );
	set( "build", 24 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/orient/room/room38",
	]) );
	set( "long", @LONG

此地初建, 空無一物。此地初建, 空無一物。此地初建, 空無一物。
此地初建, 空無一物。此地初建, 空無一物。此地初建, 空無一物。
此地初建, 空無一物。此地初建, 空無一物。此地初建, 空無一物。
此地初建, 空無一物。此地初建, 空無一物。此地初建, 空無一物。

LONG);
	setup();
	replace_program(ROOM);
}
