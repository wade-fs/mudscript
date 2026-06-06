inherit ROOM;
void create() {
	set( "short", "地雷" );
	set( "owner", "hild" );
	set( "build", 10382 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room283",
		"east"      : "/open/clan/sky-wu-chi/room/room168.c",
	]) );
	set( "long", @LONG
這房間跟天雷一樣，五行八卦排列，但是這裡有四大聖獸的石像有青龍
白虎、朱雀、玄武，這四大聖獸的排列位置讓人覺得有一種，怪異的感
覺，好像這四大聖獸好像會幻化成真的一樣，再加上這四大聖獸的雕刻
技術真是鬼斧神工，原來這是由ＨＩＬＤ運用內勁所雕刻出來的東西，
只要擁有高強的內力運在這四大神獸像，就會幻化成真的四大神獸。

LONG);
	setup();
	replace_program(ROOM);
}
