inherit ROOM;
void create() {
	set( "short", "天杖堂大廳" );
	set( "build", 10420 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room515.c",
		"north"     : "/open/clan/13_luck/room/room503",
	]) );
	set( "long", @LONG
你冒著必死的決心來到了天杖堂，你看到廳內沒有半個人在裡面，
於是你向廳內走了過去，當你走到大廳的正中間時，突然吹起了一陣大
風，然後你感覺到身後多了一股殺氣，這時你聽到焦柏衣說道：「請盡
速離去，不然別怪我不客氣了。」於是你快速的離開了天杖堂。
LONG);
	setup();
	replace_program(ROOM);
}
