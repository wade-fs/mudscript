inherit ROOM;
void create() {
	set( "short", "藥房" );
	set( "object", ([
		"amount10" : 58,
		"file1"    : "/open/fire-hole/obj/y-pill",
		"amount9"  : 82,
		"amount5"  : 5,
		"file8"    : "/open/fire-hole/obj/w-pill",
		"file5"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"amount1"  : 35,
		"file3"    : "/open/fire-hole/obj/p-pill",
		"file4"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 40,
		"amount3"  : 20,
		"amount8"  : 30,
		"amount2"  : 49,
		"file9"    : "/open/ping/obj/poison_pill",
		"amount7"  : 3,
		"file10"   : "/open/fire-hole/obj/k-pill",
		"amount6"  : 10,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"file7"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "owner", "djlh" );
	set( "build", 10017 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room664",
		"east"      : "/open/clan/13_luck/room/room161.c",
	]) );
	set( "long", @LONG

□□□■-他說他很愛她 他說會守護她   他送她玫瑰花 一切美得不像話■              
■從朋友變成情人 她不再只有自己    他愛他愛得徹底 真心溢滿了甜蜜□              
■時間看清一個人 開始令人昏沉沉   他像變了一個人 太蠻橫   □■□■              
□她開始懸著疑問 不想再等他承認 不再要任何傷痕         □-■■□■              
■誰愛誰 誰又流乾了眼淚   誰後悔 難分難捨太傷悲 *Elva-      ■□□              
□他愛誰 誰應該止住眼淚   她心碎 誰又該乾脆離開    他和她的故事*■              
□誰愛誰 誰又能反反覆覆   誰後悔 誰在忍受著孤獨  by-          ■□              
■誰瞭解 他退出 她孤獨[誰退出 誰孤獨]                    Forever■              
□愛得太盲目[誰不滿足]■□■■-□■□■-■□□■-■□□■-□■□□              
  
  
LONG);
	setup();
	replace_program(ROOM);
}
