inherit ROOM;
void create() {
	set( "short", "黃昏" );
	set( "owner", "airwalk" );
	set( "object", ([
		"amount5"  : 10,
		"amount1"  : 1,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount8"  : 18,
		"file8"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount4"  : 10,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"file10"   : "/open/magic-manor/obj/dark-soul-dagger",
		"file5"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 84,
		"file2"    : "/open/mon/obj/mon-pill",
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"amount10" : 1,
		"amount2"  : 15,
	]) );
	set( "build", 10570 );
	set( "light_up", 1 );
	set( "exits", ([
		"enter"     : "/open/clan/nine-sky-dragon/room/room38",
		"south"     : "/open/clan/nine-sky-dragon/room/room14",
	]) );
	set( "long", @LONG

過完整個夏天　憂傷並沒有好一些
開車行駛在公路無際無邊　有離開自己的感覺
唱不完一首歌　疲倦還剩下黑眼圈
感情的世界傷害在所難免　黃昏再美終要黑夜
依然記得從你口中說出再見堅決如鐵　昏暗中有種烈日灼身的錯覺
黃昏的地平線　劃出一句離別　愛情進入永夜
依然記得從你眼中滑落的淚傷心欲絕　混亂中有種熱淚燒傷的錯覺
黃昏的地平線　割斷幸福喜悅　相愛已經幻滅

LONG);
	setup();
	replace_program(ROOM);
}
