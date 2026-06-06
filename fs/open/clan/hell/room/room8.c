inherit ROOM;
void create() {
	set( "short", "$HIM$軟軟$RED$地獄$NOR$" );
	set( "build", 60 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/hell/room/hall.c",
		"down"      : "/open/clan/hell/room/room9.c",
		"west"      : "/open/clan/hell/room/room19.c",
		"east"      : "/open/clan/hell/room/room20",
	]) );
	set( "long", @LONG
    這裡是$MAG$軟軟$HIR$地獄$NOR$，你可以看到這個地獄的掌管者-又小又軟站在這裡。
他正專心的看著到這個地獄受罰的小鬼們，嘴角還露出一絲邪惡的微笑。
看來真是讓人膽顫心驚!!!!!突然他轉過頭來對你奸笑幾聲，你不禁嚇了一大跳!!!
心裡直想著 : 還是快點離開這個鬼地方好了，不然下一個又小又軟的就是我了

   又小又軟的屍體(Corpse)
LONG);
	setup();
	replace_program(ROOM);
}
