inherit ROOM;
void create() {
	set( "short", "入魔之道" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/hell/room/room60",
	]) );
	set( "long", @LONG
    這是一條詭異的走道，充滿著鬼魅的邪氣，沿途的牆壁上刻滿著宇宙
        間禁忌的武功及強大的魔法，凌駕著人間所有東西的威力，並且記載
        著歷來神魔大戰只不過世一群自稱勇者的半調子借用神的力量暫時封
        印魔力而不讓這些強大的力量流入人界。
LONG);
	setup();
	replace_program(ROOM);
}
