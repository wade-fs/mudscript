inherit ROOM;
void create() {
	set( "short", "武器裝備室" );
	set( "owner", "roarii" );
	set( "object", ([
		"file10"   : "/open/sky/obj/lucky_grasslink",
		"amount5"  : 1,
		"amount8"  : 1,
		"amount2"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount9"  : 1,
		"file6"    : "/open/capital/obj/blade2",
		"file1"    : "/open/capital/obj/blade2",
		"file4"    : "/open/capital/obj/blade2",
		"file2"    : "/open/capital/obj/blade2",
		"amount6"  : 1,
		"amount1"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/capital/obj/blade2",
		"amount10" : 1,
		"amount3"  : 1,
		"amount7"  : 1,
		"file3"    : "/open/capital/obj/blade2",
		"file5"    : "/open/capital/obj/blade2",
	]) );
	set( "build", 10151 );
	set( "light_up", 1 );
	set( "exits", ([
		"down"      : "/open/clan/13_luck/room/room569",
	]) );
	set( "long", @LONG
一間很乾淨的武器裝備室，易水樓中的師兄弟在離開前都會把
裝備放在這兒，看著地上成堆的裝備，你不禁熱淚盈匡....四面灰
白的壁上砌滿一格一格老舊紅灰色磚塊，在你面前有個半開的暗道
，似乎經常使用的樣子，不知道是通往何方的呢，可以(pass)過去
看看吧。
LONG);
	setup();
	replace_program(ROOM);
}
