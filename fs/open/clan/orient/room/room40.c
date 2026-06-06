inherit ROOM;
void create() {
	set( "short", "$HIW$『$HIY$龍郡主室$HIW$』$NOR$" );
	set( "build", 792 );
	set( "owner", "evla" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/orient/room/room38",
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
