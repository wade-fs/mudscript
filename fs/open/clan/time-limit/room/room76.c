inherit ROOM;
void create() {
	set( "short", "$BWHT$純水控制室$NOR$" );
	set( "build", 3126 );
	set( "owner", "kerr" );
	set( "exits", ([
		"east"      : "/open/clan/time-limit/room/room77",
	]) );
	set( "long", @LONG
明顯可見許多大大小小的桶槽, 還有比人還粗的水管, 許多管線塞滿了這數百
坪大的房間, 這裡可以清楚看見純水的製造流程, 經由FF, AC, 2B3T, 3B4T, 
UV殺菌, Ro過濾, 產生出超純水, 供應現場高科技的用水, 往裡面有一間負責
純水製造流程的控制室, 可以看見有人員正在忙碌的處理狀況.

LONG);
	setup();
	replace_program(ROOM);
}
