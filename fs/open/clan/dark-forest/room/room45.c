inherit ROOM;
void create() {
	set( "short", "四號右邊" );
	set( "object", ([
		"file2"    : "/open/quests/snake/npc/obj/snake-key-1",
		"amount1"  : 1,
		"amount2"  : 1,
		"file1"    : "/open/quests/snake/npc/obj/snake-key-1",
	]) );
	set( "build", 10074 );
	set( "owner", "mika" );
	set( "exits", ([
		"west"      : "/open/clan/dark-forest/room/room44",
	]) );
	set( "long", @LONG
四號右邊四號右邊四號右邊四號右邊四號右邊
    四號右邊四號右邊四號右邊四號右邊四號右邊
    四號右邊四號右邊四號右邊四號右邊四號右邊
    四號右邊四號右邊四號右邊四號右邊四號右邊
    四號右邊四號右邊四號右邊四號右邊四號右邊
    四號右邊四號右邊四號右邊四號右邊四號右邊
    四號右邊四號右邊四號右邊四號右邊四號右邊
l
LONG);
	setup();
	replace_program(ROOM);
}
