inherit ROOM;
void create() {
	set( "short", "$HIC$聚靈武器封印區$HIY$(icer)$NOR$" );
	set( "owner", "blur" );
	set( "object", ([
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"file5"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount3"  : 1,
		"amount2"  : 1,
		"file3"    : "/open/magic-manor/obj/hwa-je-icer",
		"file4"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount5"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount4"  : 1,
	]) );
	set( "build", 11034 );
	set( "exits", ([
		"out"       : "/open/clan/hell/room/room28",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
走進這招待所裡你發現空瓶子是一個很簡僕的人..並不像
外面所講的那樣般邪惡..但是又有誰會相信呢..呵呵..所以只好
在繼續當他的惡人型像遊走於四方..但是他還是多少會
有那麼一些落漠吧..但是他並不氣餒..他還是在這個招待所裡等著大
家來光臨..他會敞開大門的

LONG);
	setup();
	replace_program(ROOM);
}
