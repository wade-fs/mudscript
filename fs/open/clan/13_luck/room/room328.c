inherit ROOM;
void create() {
	set( "short", "風雲道" );
	set( "owner", "woan" );
	set( "object", ([
		"file10"   : "/obj/gift/unknowdan",
		"file7"    : "/open/gsword/obj/ring-1",
		"amount4"  : 1,
		"file6"    : "/open/love/obj/shield",
		"file8"    : "/open/port/obj/wolf_ring",
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"amount9"  : 1,
		"file1"    : "/open/port/obj/wolf_ring",
		"amount10" : 1,
		"file3"    : "/open/gsword/obj/yuboots",
		"amount7"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/love/obj/cloth1",
		"file9"    : "/open/gsword/obj/yuskirt",
		"amount3"  : 1,
		"file2"    : "/open/gsword/obj/yugem",
		"amount1"  : 1,
		"amount6"  : 1,
	]) );
	set( "build", 10155 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room327.c",
		"west"      : "/open/clan/13_luck/room/room329",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
    
    古巴比倫王頒布了漢摩拉比法典，刻在黑色的玄武岩，
距今已經三千七百多年。你在櫥窗前，凝視碑文的字眼，我
卻在旁靜靜欣賞你那張我深愛的臉。祭司、神殿、征戰、弓
箭，是誰的從前，喜歡在人潮中只屬於我的那畫面，經過蘇
美女神身邊，我以女神之名許願，思念像底格里斯河般的漫
延。當古文明只剩下難解的語言，傳說就成了永垂不朽的詩
篇。我給你的愛寫在西元前，深埋在美索不達米亞平原，幾
十個世紀後出土發現，泥板上的字跡依然清晰可見。我給你
的愛寫在西元前，深埋在美索不達米亞平原，用楔形文字刻
下了永遠，那已風化千年的誓言，一切又重演。
我感到很疲倦離家鄉還是很遠，害怕再也不能回到你身邊！ 
           
             愛在西元前    愛在西元以前 


LONG);
	setup();
	replace_program(ROOM);
}
