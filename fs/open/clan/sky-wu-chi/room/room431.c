inherit ROOM;
void create() {
	set( "short", "詭異的屋子" );
	set( "owner", "match" );
	set( "object", ([
		"file6"    : "/open/main/room/sp/stone",
		"file10"   : "/open/main/room/sp/stone",
		"file4"    : "/open/main/room/sp/stone",
		"amount10" : 1,
		"amount2"  : 1,
		"file1"    : "/open/main/room/sp/stone",
		"amount1"  : 1,
		"file5"    : "/open/main/room/sp/stone",
		"file3"    : "/open/main/room/sp/stone",
		"amount5"  : 1,
		"file7"    : "/open/main/room/sp/stone",
		"amount4"  : 1,
		"file8"    : "/open/main/room/sp/stone",
		"file2"    : "/open/main/room/sp/stone",
		"file9"    : "/open/main/room/sp/stone",
		"amount7"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount9"  : 1,
		"amount8"  : 1,
	]) );
	set( "build", 10068 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room432",
	]) );
	set( "long", @LONG
這裡不知道是什麼地方，只見空間的分隔正逐漸的裂開，許多回
憶漸漸的湧上心頭，亂七八糟的事也一件件的在你眼前出現，你的心
頭難耐，心情逐漸煩躁，手中的武器也不自覺得放了下來，只見你自
己跪在地上，不斷的哭喊著叫媽媽，好像一個白癡的三歲小孩一般。
LONG);
	setup();
	replace_program(ROOM);
}
