inherit ROOM;
void create() {
	set( "short", "$RED$貓神界$NOR$" );
	set( "object", ([
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"amount4"  : 1,
	]) );
	set( "item_desc", ([
		"corpse" : @ITEM
這是$RED$霹靂貓$NOR$的屍體，裡面什麼東西都沒有，
有股惡臭從裡面散發出來，哇勒，
到底幾天沒洗澡了........   有夠豬
ITEM,
	]) );
	set( "light_up", 1 );
	set( "build", 10566 );
	set( "exits", ([
		"up"        : "/open/clan/hell/room/room5.c",
		"down"      : "/open/clan/hell/room/room6.c",
		"west"      : "/open/clan/hell/room/room16",
		"east"      : "/open/clan/hell/room/room14.c",
	]) );
	set( "long", @LONG
    這裡就是著名的陰間入口「貓界」﹐在你面前矗立著一座高大的
黑色城樓﹐所多亡魂正哭哭啼啼地列隊前進﹐因為一進鬼門關就無法再
回陽間了。你在門前徘徊了許多，深怕一進就出不來，此時此刻。你的
神在不知覺中被拉了進去。

  霹靂貓的屍體(Corpse)
LONG);
	setup();
	replace_program(ROOM);
}
