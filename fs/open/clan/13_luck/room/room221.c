inherit ROOM;
void create() {
	set( "short", "三樓走道" );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room222",
		"north"     : "/open/clan/13_luck/room/room220",
	]) );
	set( "long", @LONG

　　大戰三百回合後，你好不容易將白滴子給打敗了，來到鎖龍塔第
三層的走道，空氣中迷漫著濃濃的血腥味。此地牆上刻畫著龍的圖騰
，似乎是在述說著此地的故事，地上的骸骨無數，看來這裡也是十分
的兇險，必需小心不要成為地上的骸骨之一。

LONG);
	setup();
	replace_program(ROOM);
}
