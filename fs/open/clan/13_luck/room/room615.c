inherit ROOM;
void create() {
	set( "short", "醉仙樓" );
	set( "owner", "mill" );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room617",
		"up"        : "/open/clan/13_luck/room/room614",
	]) );
	set( "long", @LONG
方圓數百裏內提起醉仙樓可以說是無人不知，無人不曉。當年蘇學士雲
遊到此，對醉仙樓的花雕酒贊不絕口，欣然為其題匾，流下一段傳遍海內的
佳話，從此醉仙樓名聲大震。樓下布置簡易，顧客多是匆匆的行人，買點包
子、雞腿、米酒就趕路去了。樓上是雅座。
LONG);
	setup();
	replace_program(ROOM);
}
