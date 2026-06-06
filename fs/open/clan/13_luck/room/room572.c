inherit ROOM;
void create() {
	set( "short", "茶室" );
	set( "owner", "roarii" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room573",
		"east"      : "/open/clan/13_luck/room/room571.c",
		"west"      : "/open/clan/13_luck/room/room570",
	]) );
	set( "long", @LONG
這裡窗明几淨，地上鋪著一張虎皮地毯，為了使招待的遠客有
賓至如歸的感覺，還擺設了泡茶用具，此具據說是明朝王陽明所用
的，隱隱約約還看見上面有『知行合一』四個小字。茶香滿室，令
你神清氣爽。左右兩旁的房間是招待用的客房。
LONG);
	setup();
	replace_program(ROOM);
}
