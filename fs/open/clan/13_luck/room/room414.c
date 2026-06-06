inherit ROOM;
void create() {
	set( "short", "斷魂橋中央" );
	set( "object", ([
		"amount7"  : 100,
		"amount1"  : 200,
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file7"    : "/open/fire-hole/obj/w-pill",
		"amount5"  : 200,
		"file1"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 155,
		"file5"    : "/open/fire-hole/obj/r-pill",
	]) );
	set( "owner", "mwf" );
	set( "build", 10104 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room413",
		"south"     : "/open/clan/13_luck/room/room415.c",
	]) );
	set( "long", @LONG

    這裡就是橋中央了，兩頭似乎都有敵人要慢慢圍攻過來，兩旁的木頭
很明顯的有砍傷過的痕跡，可見在這裡已經發生過不知道多少驚人的惡鬥
，十三吉祥的掌管者看來也深闇兵法，懂得在不同的地方伏擊敵人，看來
要趕快通過這裡才行，不然就要成為下一個犧牲者了....

LONG);
	setup();
	replace_program(ROOM);
}
