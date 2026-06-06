inherit ROOM;
void create() {
	set( "short", "鬼門大道" );
	set( "build", 10412 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/hell/room/room16",
	]) );
	set( "long", @LONG
你走在一條陰森森的路上, 濃濃的霧環繞在你的四周, 好像永
遠都不會散去似的. 往南看去你勉強可以分辨出一個城樓的模樣，
往北隱約可以看到幾盞燈籠, 在濃霧中顯得格外的詭異. 路的兩旁
各有一棟木造的建築, 門都是半開的, 但你看不清楚裡面有什麼.

LONG);
	setup();
	replace_program(ROOM);
}
