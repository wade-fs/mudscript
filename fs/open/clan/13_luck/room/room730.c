inherit ROOM;
void create() {
	set( "short", "我家牛排" );
	set( "owner", "mary" );
	set( "build", 10046 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room670",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG


      包好吃  , 一家在金山街快速竄紅的餐館, 亮麗的招牌高掛在上,
但門面卻顯得不太撘, 怎麼會有油漆在門窗上呢? 原來是因為生意太好遭
同業報復才被潑的, 由此可見可能真的很好吃吧一走進裡頭, 寬敞的用餐
空間, 讓人覺得心曠神怡, 找個位子坐了下來, 點個牛肉麵, 好好享受一
頓美食吧!


LONG);
	setup();
	replace_program(ROOM);
}
