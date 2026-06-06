inherit ROOM;
void create() {
	set( "short", "拓荒地" );
	set( "owner", "marshal" );
	set( "object", ([
		"amount9"  : 1,
		"amount2"  : 304,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file6"    : "/obj/gift/unknowdan",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount1"  : 376,
		"amount5"  : 1,
		"amount4"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"file5"    : "/obj/gift/xiandan",
		"file4"    : "/obj/gift/xiandan",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/obj/gift/xiandan",
	]) );
	set( "light_up", 1 );
	set( "build", 10432 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room512",
	]) );
	set( "long", @LONG
這是Ddt新申請的房間...很明顯的似乎還沒完工
四處都是雜亂的雜物和建材﹐前方還有一個人辛苦的在敲敲打打
難道那就是Ddt嗎?你想起來此地的目的加快腳步往前走去
你定眼一看怎會是機器人在工作?那Ddt到底在哪裡?
你以好奇的眼神看著機器人工作順便等待Ddt回來
LONG);
	setup();
	replace_program(ROOM);
}
