inherit ROOM;
void create() {
	set( "short", "初級女子修練場" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room631.c",
		"north"     : "/open/clan/13_luck/room/room629",
	]) );
	set( "long", @LONG

    這裡是為詩劍山莊的接待廳，陣陣梅花的香氣，隨著清風令人神清
氣爽，這邊種植著許多的梅花，莫怪乎有梅花的淡雅的清香撲鼻，許多
的江湖朋友在此拜會詩劍山莊的人‧而風微微的吹來女子的香味，耳朵
不時聽到女子的武鬥聲，寬廣的練武場地，場上有許多的女弟子在互相
練武過招，且看女子的服色不同，應該是分強度在練武吧‧

LONG);
	setup();
	replace_program(ROOM);
}
