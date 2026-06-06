inherit ROOM;
void create() {
	set( "short", "小二的丹藥房" );
	set( "light_up", 1 );
	set( "build", 10040 );
	set( "exits", ([
		"south"     : "/open/clan/demon_castle/room/room12",
	]) );
	set( "owner", "suzukiami" );
	set( "long", @LONG
這裡擺著小二由世界各地蒐集來的丹藥
各式各樣的丹藥琳瑯滿目
看的你眼花撩亂
但是...它們都放在保險櫃裡
你只能看到它們卻拿不到
LONG);
	setup();
	replace_program(ROOM);
}
