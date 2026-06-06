inherit ROOM;
void create() {
	set( "short", "詩堂堂主休息室" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room624",
	]) );
	set( "long", @LONG

    詩劍山莊的偏廳，牆壁上放的盡是無數的寶劍，這裡就是詩劍山莊的
詩堂所在，詩堂的好手在武林極負盛名，所以別亂動詩劍的堂級弟子，避
免自己自討苦吃，落到受傷的下場而堂主看起來才四十多歲的詩劍山莊詩
堂主刑雲飛，事實上已經快六十了，據說他的內功與前莊主不遑多讓，且
劍走靈動，配合其內力所形成之無形劍氣更可無聲無息的穿透敵人的防禦
，毫無阻礙下革殺敵人

LONG);
	setup();
	replace_program(ROOM);
}
