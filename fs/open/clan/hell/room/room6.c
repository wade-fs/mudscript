inherit ROOM;
void create() {
	set( "short", "血地獄" );
	set( "objects", ([
		"/open/clan/hell/npc/npc32" : 1,
		"/open/clan/hell/npc/npc31" : 1,
	]) );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/hell/room/room41",
		"up"        : "/open/clan/hell/room/room12.c",
		"enter"     : "/open/clan/hell/room/room61.c",
	]) );
	set( "long", @LONG
        的地獄景象之中....一時之間你被嚇的魂飛魄散一步也不敢停留....
        機而動....但是你憑著本身高強的武功修為及與生俱來的勇氣一步一
        步的向前探索....緊接著發現面前有一個怪異的地方....
        一個有如世界末日的景象出現在眼前....所有的景色都被淹沒在血紅
        的顏色當中....有著各式各樣的殘酷的畫面....全部都淹沒在這血紅
        的地獄景象之中....一時之間你被嚇的魂飛魄散一步也不敢停留....


LONG);
	setup();
	replace_program(ROOM);
}
