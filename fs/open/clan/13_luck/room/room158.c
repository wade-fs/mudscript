inherit ROOM;
void create() {
	set( "short", "霧之林" );
	set( "build", 24 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room158",
		"east"      : "/open/clan/13_luck/room/room157.c",
		"west"      : "/open/clan/13_luck/room/room163.c",
		"north"     : "/open/clan/13_luck/room/room158.c",
	]) );
	set( "long", @LONG

　　謎樣般的森林，終年濃霧不散，眼前只見白茫茫的一大片，伸手
不見五指。遠處飄來一陣陣的惡臭，四週一片死寂，了無生氣。越往
裡面走去，心裡的那種不安全感越來越濃，而接踵而來的壓迫感，讓
人有種往回走的衝動。

LONG);
	setup();
	replace_program(ROOM);
}
