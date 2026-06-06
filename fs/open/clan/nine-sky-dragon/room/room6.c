inherit ROOM;
void create() {
	set( "short", "冥想室" );
	set( "build", 10055 );
	set( "exits", ([
		"west"      : "/open/clan/nine-sky-dragon/room/room4",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是讓劍如冰冥想的地方，由於他持續的冥想的終於突破了大限
達到學究天人之境界，如果你也想達學究天人，可以考慮是否來
這裡與她一起冥想，一起突破學究天人的境界，一起探討無盡深遠
的武學奧妙之處，期望可以達到武學的功力無限深遠。
LONG);
	setup();
	replace_program(ROOM);
}
