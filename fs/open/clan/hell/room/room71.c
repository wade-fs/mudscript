inherit ROOM;
void create() {
	set( "short", "$HIW$白龍$NOR$區" );
	set( "build", 12068 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room27",
	]) );
	set( "long", @LONG

你想要堅挺嗎!? 你想要持久嗎!? 
揮別趴趴熊的形象,邁向SUPER MAN的境界,
白龍精元絕對是你最好的選擇!! 

讓你不再是拿著竹筷撈水桶....
保證另一半天天對你讚口不絕...

你還在猶豫什麼,趕快拿起電話訂購...
訂購專線 : 020479979..
來電前五名附贈七叔牌神油一罐..
讓你真正成為一尾活龍!!!

LONG);
	setup();
	replace_program(ROOM);
}
