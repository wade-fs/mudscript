inherit ROOM;
void create() {
	set( "short", "遊龍廊道" );
	set( "owner", "mill" );
	set( "object", ([
		"amount1"  : 290,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 300,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 300,
	]) );
	set( "build", 10189 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room530",
		"east"      : "/open/clan/13_luck/room/room497.c",
	]) );
	set( "long", @LONG

    此為清流一廊道，勢若遊龍，兩邊石欄上皆以朱墨彩繪，雕龍刻
鳳，點如銀光雪亮，雖無花葉，卻用以各色綢綾紙絹，或以通草為花
，更兼池中荷荇上下爭輝。池旁俱是奇岩怪石，又有芭蕉桃花崇光泛
彩，紅香綠玉翠帶飄飄，溶溶蕩蕩，曲折瀅蕍。

LONG);
	setup();
	replace_program(ROOM);
}
