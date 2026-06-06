inherit ROOM;
void create() {
	set( "short", "死亡深淵" );
	set( "object", ([
		"file4"    : "/open/mogi/dragon/obj/key",
		"file7"    : "/daemon/class/blademan/obj/six-neck",
		"amount4"  : 1,
		"amount7"  : 1,
	]) );
	set( "build", 10398 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room6",
		"hole"      : "/open/clan/hell/room/room62",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

        走入這個地方之後發現四周的光線越來越少，前方有如太空中的黑洞
        ，吞噬掉一切物質，甚至連光線也不能存在，是一切能量的盡頭嗎！
        或是通往另一個空間的入口！正在思考這個問題的時候，突然一股不
        可抗拒的吸力將你拉入死亡深淵的中心。


LONG);
	setup();
	replace_program(ROOM);
}
