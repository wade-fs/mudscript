inherit ROOM;
void create() {
	set( "short", "聖堂練槍場" );
	set( "owner", "roarii" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room599",
		"north"     : "/open/clan/13_luck/room/room595",
	]) );
	set( "long", @LONG
現在你來到了聖堂的長槍練習場，在這裡你可以看到許
多的聖堂弟子在這裡練習她們熟練的槍術，歷代聖堂出了無
數的槍術高手。他們全部都曾經在此留下他們練習的槍痕！
所以在此地練習的弟子都可以說是即將可以步入江湖的能手
，所以你最好別挑釁他們。他們可不是像你之前遇到的嫩腳
一樣是可以讓你欺負的。

LONG);
	setup();
	replace_program(ROOM);
}
