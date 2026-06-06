inherit ROOM;
void create() {
	set( "short", "豆干厝" );
	set( "owner", "biom" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room108",
	]) );
	set( "object", ([
		"amount8"  : 300,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 300,
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file6"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 300,
		"amount10" : 300,
		"amount2"  : 300,
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 300,
		"amount3"  : 200,
		"amount7"  : 300,
		"file9"    : "/open/fire-hole/obj/g-pill",
		"amount5"  : 300,
		"amount6"  : 189,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/fire-hole/obj/g-pill",
	]) );
	set( "build", 10027 );
	set( "long", @LONG

      一踏入此地迎面而來的是滿屋子的髒亂，你開始思考
這邊真的是人住的地方嗎?不過看老乞丐怡然自得的樣子，
不免讓你對他感到一絲絲的崇拜，牆壁上有些許獎狀跟照片
，原來他也是有經歷過大風大浪的人，配上破破爛爛的
屋頂，稱這裡為狗窩，實在是在適合不過了！

LONG);
	setup();
	replace_program(ROOM);
}
