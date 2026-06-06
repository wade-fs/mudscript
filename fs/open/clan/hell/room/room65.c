inherit ROOM;
void create() {
	set( "short", "$HIW$王座後門$NOR$" );
	set( "owner", "radio" );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room38",
	]) );
	set( "long", @LONG
test test test test test test test test
test test test test test test test test
test test test test test test test test
test test test test test test test test
test test test test test test test test
LONG);
	setup();
	replace_program(ROOM);
}
