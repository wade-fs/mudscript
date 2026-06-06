inherit ROOM;
void create() {
	set( "short", "$BRED$時$BGRN$空$BYEL$倉$BBLU$庫$BMAG$之$BCYN$聚靈珠$NOR$" );
	set( "object", ([
		"file1"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"file3"    : "/open/magic-manor/ghost/obj/five-turn-ball",
		"amount1"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 13265 );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room89.c",
		"west"      : "/open/clan/time-limit/room/room85",
		"up"        : "/open/clan/time-limit/room/room96",
		"north"     : "/open/clan/time-limit/room/room91.c",
		"south"     : "/open/clan/time-limit/room/room87",
		"down"      : "/open/clan/time-limit/room/hall.c",
	]) );
	set( "long", @LONG
五轉聚靈珠(five turn ball)是打倒聚靈山莊外的鳳翔天所遺留下來的寶物,
其功能在於能增加五轉聚靈盤(Five turn)閃動的機率,尤其是配合五色靈光時
更是好用的不得了,不過使用時要注意一顆珠子只能使用一次,用完就沒了,而
且一旦離線,珠子也將失去作用

LONG);
	setup();
	replace_program(ROOM);
}
