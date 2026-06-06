inherit ROOM;
void create() {
	set( "short", "虛擬海洋" );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room47.c",
		"north"     : "/open/clan/13_luck/room/room46",
		"south"     : "/open/clan/13_luck/room/room51",
		"east"      : "/open/clan/13_luck/room/room50.c",
	]) );
	set( "long", @LONG

    向著四周望去盡眼力能看到最遠的地方，也似乎看不見陸地，只
看見一大片的藍藍大海，喝著小酒吃著小菜，盡興的欣賞。過了許久
不知船開的方向對不對，向著遠方望去還是看不到任何一塊空地，心
理想著是不是迷路了。

LONG);
	setup();
	replace_program(ROOM);
}
