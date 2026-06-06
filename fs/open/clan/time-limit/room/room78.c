inherit ROOM;
void create() {
	set( "short", "$BYEL$劍房$NOR$" );
	set( "owner", "tsmc" );
	set( "object", ([
		"amount5"  : 1,
		"amount1"  : 353,
		"amount10" : 35,
		"amount2"  : 80,
		"file5"    : "/open/gsword/obj1/blosword",
		"amount3"  : 520,
		"amount6"  : 1,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file6"    : "/open/scholar/obj/icefan",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 1,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/scholar/obj/icefan",
		"file10"   : "/open/ping/obj/poison_pill",
	]) );
	set( "build", 10474 );
	set( "exits", ([
		"west"      : "/open/clan/time-limit/room/room81",
	]) );
	set( "long", @LONG
這裡是憶秋年修練劍術的房間,裡頭還藏有一些武器與丹藥,牆壁四周留有數不
盡的劍痕,前方的黑鋼石上刻著兩條劍痕,相傳是憶秋年與風之痕所留下,當年兩
人就以此比劍,看誰的劍痕先突破頂端誰就是勝利者,仔細一看,兩條劍痕還在緩
緩上升當中,如此劍術令人嘖嘖稱奇,而憶秋年和風之痕這段亦敵亦友的故事,更
是人們茶餘飯後的話題之一

LONG);
	setup();
	replace_program(ROOM);
}
