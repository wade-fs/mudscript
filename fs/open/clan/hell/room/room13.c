inherit ROOM;
void create() {
	set( "short", "$HIB$閻羅王「哼」的一聲﹐從袖中掏出一本像帳冊的東西翻看著。$BLK$" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 6,
		"file2"    : "/open/gsword/obj1/bbladeball",
		"file3"    : "/obj/stone/powder",
	]) );
	set( "build", 10285 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room127",
		"east"      : "/open/clan/hell/room/room143.c",
		"south"     : "/open/clan/hell/room/room2.c",
		"west"      : "/open/clan/hell/room/room99.c",
	]) );
	set( "long", @LONG

$RED$鬼門關$NOR$ - 
    這裡就是著名的陰間入口「鬼門關」﹐在你面前矗立著一座高大的
黑色城樓﹐所多亡魂正哭哭啼啼地列隊前進﹐因為一進鬼門關就無法再
回陽間了。你在門前徘徊了許多，深怕一進就出不來，此時此刻。你的
神在不知覺中被拉了進去。

  閻羅王(Ghost king)
LONG);
	setup();
	replace_program(ROOM);
}
