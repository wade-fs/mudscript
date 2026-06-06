inherit ROOM;
void create() {
	set( "short", "$HIB$nevermind$NOR$" );
	set( "owner", "nirvana" );
	set( "object", ([
		"file6"    : "/open/fire-hole/obj/p-pill",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount8"  : 1189,
		"amount2"  : 49,
		"amount1"  : 10,
		"amount3"  : 44,
		"amount6"  : 4,
		"amount4"  : 99,
		"file5"    : "/open/fire-hole/obj/k-pill",
		"file7"    : "/open/doctor/pill/human_pill",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"file8"    : "/open/doctor/pill/taii_pill",
		"amount5"  : 19,
		"file1"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount7"  : 348,
	]) );
	set( "build", 10121 );
	set( "exits", ([
		"north"     : "/open/clan/hell/room/room50.c",
		"west"      : "/open/clan/hell/room/room54.c",
		"east"      : "/open/clan/hell/room/room9",
		"south"     : "/open/clan/hell/room/room51.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
話說kalin的音樂經...那有的說了..
在kalin高三的那....經歷了一場大浩劫...
在身心俱疲時....megadeth進駐了他的小小心靈...
kalin之後深信rock 'N roll never die......
一直到大一時...kalin拋棄了thrash 擁抱了punk....
這是一個很關鍵的轉折點...
聽了一年的heavy... thrash... kalin的rock很傳統...
但接觸到punk後..,kalin像是找到寶的小孩..欣喜不矣..
若說rock 'N roll是上帝，那punk就是撒旦了...
LONG);
	setup();
	replace_program(ROOM);
}
