inherit ROOM;
void create() {
	set( "short", "歹勇仔人頭屋" );
	set( "object", ([
		"file5"    : "/open/mogi/castle/obj/fire-king-head",
		"amount1"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"file4"    : "/open/main/obj/unarmed-b",
		"amount4"  : 1,
		"amount3"  : 1,
		"file3"    : "/open/mogi/castle/obj/fire-king-head",
		"file2"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
	]) );
	set( "owner", "biob" );
	set( "light_up", 1 );
	set( "build", 10233 );
	set( "exits", ([
		"enter"     : "/open/clan/13_luck/room/room108",
	]) );
	set( "long", @LONG

    雄貓雄貓! 看我雄貓肉腳, 百戰百敗, 我武必輸, 狂想成軍, 古
堡被蕩, 魔界被殺, 京城大捷下地獄, 百輸雄貓, 花光自己的潛能,
肉角雄貓, 輸掉自己美好的經驗值, 當戰鬥號角響, 我雄貓奮起逃難
, 建樹百世惡名, 敵人貫穿胸膛, 雄貓懦弱無能, 雄貓被定被搶, 弱
視八方, 四海被欺.............改編當時天下第一旅269雄獅戰歌

LONG);
	setup();
	replace_program(ROOM);
}
