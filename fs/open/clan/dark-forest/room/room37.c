inherit ROOM;
void create() {
	set( "short", "橫小弟的碎夢刀塚" );
	set( "owner", "jong" );
	set( "exits", ([
		"down"      : "/open/clan/dark-forest/room/room27",
	]) );
	set( "long", @LONG
橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚
橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚
橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚
橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚橫小弟的碎夢刀塚
LONG);
	setup();
	replace_program(ROOM);
}
