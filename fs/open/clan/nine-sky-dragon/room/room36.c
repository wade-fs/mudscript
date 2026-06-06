inherit ROOM;
void create() {
	set( "short", "醉仙樓六樓" );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/nine-sky-dragon/room/room35",
	]) );
	set( "long", @LONG

　　你繞過一道淡綠綢屏風，順著樓梯來到醉仙樓六樓的走郎上，心
情愉悅地走著。徐徐晚風從透過窗戶吹進房裡，感覺十分的舒暢。站
在窗前靜靜的望著天上的明月及滿天的星斗，寧聽夜裡蟲兒的鳴叫聲
，忘卻了所有苦悶，此乃一大樂事啊！

LONG);
	setup();
	replace_program(ROOM);
}
