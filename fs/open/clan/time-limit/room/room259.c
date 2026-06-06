inherit ROOM;
void create() {
	set( "short", "星之金字塔頂樓前" );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room258",
	]) );
	set( "long", @LONG
這裡是頂樓前的儲藏室,寶箱四處都是,金銀珠寶散落一地,讓你不禁想把這些寶藏搬回家,正
想動手時卻想起偷拿亡靈的寶物會被亡靈攻擊,奇怪的是看不到守衛的士兵,難道前方還有更
值錢的寶物,而守衛者就在前方,你小心翼翼的往前一看

LONG);
	setup();
	replace_program(ROOM);
}
