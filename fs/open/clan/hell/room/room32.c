inherit ROOM;
void create() {
	set( "short", "$HIB$刀墳$NOR$" );
	set( "owner", "neun" );
	set( "light_up", 1 );
	set( "build", 10072 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room28",
	]) );
	set( "long", @LONG
一個不起眼的土堆上面差著數十把金光閃閃的刀,仔細看看不全都是各著名刀
手所常用的兵刃嘛,她們死後生前所賴以成名的武器,也全都被閻羅王收集到此處
想到地府鬼師深不可測的實力,能夠拿到這些兵刃,你不禁不寒而慄,此地也不定時
的透出陣陣陰寒之氣

LONG);
	setup();
	replace_program(ROOM);
}
