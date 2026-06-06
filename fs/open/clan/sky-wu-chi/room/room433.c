inherit ROOM;
void create() {
	set( "short", "Small專用維他命" );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG

Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...
Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...
Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...
Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...
Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...Small專用維他命 小殺手 ...

LONG);
	setup();
	replace_program(ROOM);
}
