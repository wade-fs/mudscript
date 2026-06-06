inherit ROOM;
void create() {
	set( "short", "蟻窩" );
	set( "outdoors", "/open/clan/13_luck" );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room168",
		"down"      : "/open/clan/13_luck/room/room192",
	]) );
	set( "long", @LONG

　　一進到洞穴裡，眼前出現的是一個巨大的螞蟻窩，你差點被嚇的
屁滾尿流。不知是這裡環境好，還是不受打擾的原因，這裡的螞蟻竟
都大的像隻貓一樣，突然你發現幾隻工蟻從洞內下方深處不懷好意的
看著你，你感到一股殺氣包圍在你的四周。

LONG);
	setup();
	replace_program(ROOM);
}
