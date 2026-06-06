inherit ROOM;
void create() {
	set( "short", "$HIG$指令測試房二$NOR$" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/new_heaven/room/room6",
		"north"     : "/open/clan/new_heaven/room/room10",
	]) );
	set( "long", @LONG
別鬧了, long還叫我要寫一堆, 不然就不給我算有long, 看了code,
說要sizeof(long)>100才算數, 拜託一下, 本大爺沒那麼多時間寫敘述啦,
哈啦半天, 應該有100字了吧
LONG);
	setup();
	replace_program(ROOM);
}
