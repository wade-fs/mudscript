inherit ROOM;
void create() {
	set( "short", "你會選擇什麼呢?(1)" );
	set( "object", ([
		"amount1"  : 30,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"file9"    : "/open/fire-hole/obj/b-pill",
		"file3"    : "/open/fire-hole/obj/k-pill",
		"amount9"  : 68,
		"amount8"  : 205,
		"amount5"  : 132,
		"file5"    : "/open/mon/obj/mon-pill",
		"amount3"  : 43,
		"amount2"  : 97,
		"file8"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 50,
		"file4"    : "/open/ping/obj/poison_pill",
		"file2"    : "/open/fire-hole/obj/p-pill",
	]) );
	set( "owner", "dfyw" );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room559.c",
		"east"      : "/open/clan/13_luck/room/room556",
		"north"     : "/open/clan/13_luck/room/room558.c",
		"down"      : "/open/clan/13_luck/room/room548",
		"west"      : "/open/clan/13_luck/room/room557.c",
	]) );
	set( "long", @LONG
這個問題很有意思...
遺憾 和 後悔 你會選擇什麼呢?
後悔 和 遺憾 你會選擇什麼呢?
假使有一件事，不做會遺憾，做了會後悔，你會如何?
假使有一個人，愛了會後悔，不愛會遺憾，妳會愛嗎？                                             
似乎，選擇就是這麼一回事。
曾經以為，生命中應該有一些事，是值得我們奮起直追的。
那是什麼？是值得回味留存的愛情？
還是象微肯定與前景的工作？
是女性的最終依歸一家庭？
抑或是那份總愁沒人了解的自我
也許可以是快樂..
也許可以是充實..
也許可以是盡情享受捉模不定的未來.....
LONG);
	setup();
	replace_program(ROOM);
}
