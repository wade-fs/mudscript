inherit ROOM;
void create() {
	set( "short", "$HIR$丹藥室$NOR$" );
	set( "owner", "taa" );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room611",
	]) );
	set( "long", @LONG

                                          ┌──┐
                                        ┌┘    │
                                        |   煉   |
                                        |   丹   |
                                        |   爐   |
                                      __|__ 　 __|__


LONG);
	setup();
	replace_program(ROOM);
}
