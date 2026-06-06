inherit ROOM;
void create() {
	set( "short", "$HIG$青$HIB$龍$HIC$時$HIR$空$NOR$" );
	set( "build", 947 );
	set( "exits", ([
		"pass"      : "/open/clan/time-limit/room/room177",
		"south"     : "/open/clan/time-limit/room/room2.c",
	]) );
	set( "long", @LONG
這裡是時空秘境中的青龍時空,眼前茂密的森林,讓你彷彿進入亞馬遜流域裡,入口處的
樹木排成龍頭的形狀,張開大嘴對著你,像是要把你吞下去,看到如此格局就知道,這裡頭
必然危機四伏,果不其然,一進入裡頭,四周茂盛的樹木已將你的方向感摧毀,蟲吟鳥鳴則
慢慢侵蝕你的時間感,當你想回頭時,卻發現路徑早已被樹木所吞沒了

LONG);
	setup();
	replace_program(ROOM);
}
