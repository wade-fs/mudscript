inherit ROOM;
void create() {
	set( "short", "酒莊" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room627",
	]) );
	set( "long", @LONG

    這裡就是聞名全武林，詩劍山莊專屬酒莊==醉仙居==，一入醉仙居，就看到
正廳掛著一幅好大的醉八仙圖，醉仙居名產【清溪流泉】名動天下，據說連神仙
都會忍不住下凡來喝他個兩杯，到這買酒時如果有看到神仙的話，可千萬別驚訝
喔。

LONG);
	setup();
	replace_program(ROOM);
}
