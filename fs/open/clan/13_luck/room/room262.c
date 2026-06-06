inherit ROOM;
void create() {
	set( "short", "桃花迷霧林" );
	set( "owner", "asfd" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room263",
		"south"     : "/open/clan/13_luck/room/room256.c",
	]) );
	set( "long", @LONG

    桃花林，桃花林，此乃進入桃花島內部的必經之路，但聽說在老東邪
死去前，為了讓外孫小東邪不受到任何外界的打擾，在這裡設了奇門八陣
，據說，這裡號稱有膽入，無命出，地上白骨片片，或許就是那些不知死
活的人，想進入偷取異寶，卻困於此無法逃離的人吧!

LONG);
	setup();
	replace_program(ROOM);
}
