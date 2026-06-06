inherit ROOM;
void create() {
	set( "short", "劍堂堂主休息室" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room624",
	]) );
	set( "long", @LONG

    詩劍山莊的偏廳，牆壁上放的盡是無數的寶劍，這裡就是詩劍山莊
的劍堂所在，詩堂的好手在武林極負盛名，所以別亂動詩劍的堂級弟子 
，以免自己自討苦吃，落到受傷的下場，而在往裡面看進去，光看其雄
厚的背影，冷肅的氣息，就該知道面前的人是詩劍山莊劍堂堂主雷明，
身為上代詩劍山莊所留下來的兩位耆老之一，其能力是無庸至疑的，其
無上詩意秘劍已螓至無劍發招的境界‧

LONG);
	setup();
	replace_program(ROOM);
}
