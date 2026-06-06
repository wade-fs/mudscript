inherit ROOM;
void create() {
	set( "short", "正殿大門" );
	set( "owner", "roariv" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room629",
		"enter"     : "/open/clan/13_luck/room/room624",
	]) );
	set( "long", @LONG
 
    詩劍山莊的大殿，樓高三層，用紅色與水藍色的屋瓦搭建而成，感
覺富麗堂皇中流露出一股不可侵犯的威嚴之勢，讓你心中不免佩服不已
，詩劍山莊建在較高的丘陵平原上，而其他五軒則環繞於四周較低的平
原，做為守護山莊之用，鄰近的各區皆有通道，以便相互支援‧

LONG);
	setup();
	replace_program(ROOM);
}
