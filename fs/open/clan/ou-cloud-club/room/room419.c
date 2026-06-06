inherit ROOM;
void create() {
	set( "short", "$HIR$火焰之舞$NOR$" );
	set( "light_up", 1 );
	set( "build", 10190 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room418.c",
		"east"      : "/open/clan/ou-cloud-club/room/room203.c",
		"south"     : "/open/clan/ou-cloud-club/room/room412",
		"north"     : "/open/clan/ou-cloud-club/room/room413.c",
	]) );
	set( "long", @LONG
 這一道迴廊是用硬度極高的『焱石』所建造的，據說是掌管
火焰的上古炎獸『伊弗利特』所製造的，除了水火不侵之外還兼
具了冬暖夏涼的特點，而兩旁的牆壁上有不少的小孔，聽說裡頭
暗藏機關，但詳細情形只有幫主以及長老知道而已。

北邊是Alus休息練功的地方，南邊是Juzn的家。

LONG);
	setup();
	replace_program(ROOM);
}
