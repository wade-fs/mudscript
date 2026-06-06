inherit ROOM;
void create() {
	set( "short", "血痕居-號叫地獄" );
	set( "owner", "holeman" );
	set( "build", 16580 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room528.c",
		"west"      : "/open/clan/sky-wu-chi/room/room535.c",
		"east"      : "/open/clan/sky-wu-chi/room/room536",
	]) );
	set( "long", @LONG

    這個地獄的眾生被關在沒有門、又炙熱的房子中，因為無法逃
脫，在裡面慘叫哀號，所以稱為號叫地獄。就像人們把鍋子燒得紅
，把所謂可以補身體的小生命放到裡面去煮、熬、燉。當他們被活
生生的放進去時，一定會有慘叫聲，可是卻很少有人會去想到他們
的痛苦。不要說在地獄中，有時我們的手稍微觸電，或是炒菜、做
事時被熱鍋或火碰到，也都會大喊大叫啊！

    這個地獄眾生的壽命是：人間的四百年是兜率天的一天，兜率
天的四千年是號叫地獄的一天，號叫地獄要在此受苦四千年。


LONG);
	setup();
	replace_program(ROOM);
}
