inherit ROOM;
void create() {
	set( "short", "種族及國家4" );
	set( "owner", "dfyw" );
	set( "object", ([
		"amount1"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/obj/gift/xisuidan",
		"file5"    : "/obj/gift/xisuidan",
		"file1"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"file4"    : "/obj/gift/xisuidan",
		"amount10" : 1,
		"file6"    : "/obj/gift/xisuidan",
		"file8"    : "/obj/gift/xisuidan",
		"file7"    : "/obj/gift/xisuidan",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file3"    : "/obj/gift/xisuidan",
	]) );
	set( "build", 10019 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room440",
	]) );
	set( "long", @LONG

翼族
被大多數得種族視為天人的後裔。擁有古代文明的遺產，並利用這些遺產使自己
和其他種族隔離一般時候根本看不到這個種族的身影。

拉普達
翼人是傳說中*天人*的後裔，隱居於以高度技術建造的天空城市，因此在世界的
地圖上看不到他們居住地點不與地界的種族來往，地上種族也多半不知道翼人的
存在。現任的領導者從缺，繼承人為索妮雅。

LONG);
	setup();
	replace_program(ROOM);
}
