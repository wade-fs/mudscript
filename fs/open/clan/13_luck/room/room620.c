inherit ROOM;
void create() {
	set( "short", "後殿走道" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room624",
	]) );
	set( "long", @LONG

    詩劍山莊的後殿走道，是通往另一個詩劍山莊修練場的地方，詩劍山莊
是武林中有名的名門正宗，慕名拜師的人數眾多，所以詩劍山莊人數與佔地
非常的大，讓你自己也想進入詩劍山莊拜師，聽到兇猛的比鬥叫量聲，讓你
心中悸動不已，前方的弟子一定是很強的

LONG);
	setup();
	replace_program(ROOM);
}
