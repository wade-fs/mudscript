inherit ROOM;
void create() {
	set( "short", "小小邦屋" );
	set( "object", ([
		"amount3"  : 53,
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount8"  : 10,
		"amount7"  : 34,
		"file8"    : "/open/fire-hole/obj/w-pill",
		"amount1"  : 9,
		"file1"    : "/obj/stone/powder",
		"file6"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/fire-hole/obj/k-pill",
		"amount5"  : 16,
		"amount9"  : 5,
		"file4"    : "/open/fire-hole/obj/p-pill",
		"file10"   : "/obj/stone/jiao",
		"file9"    : "/open/fire-hole/obj/w-pill",
		"amount6"  : 6,
		"amount4"  : 57,
		"file7"    : "/open/fire-hole/obj/y-pill",
		"amount10" : 5,
		"amount2"  : 50,
		"file5"    : "/open/fire-hole/obj/b-pill",
	]) );
	set( "build", 10138 );
	set( "owner", "yken" );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room580",
		"enter"     : "/open/clan/13_luck/room/room758",
	]) );
	set( "long", @LONG
        你來到了小小邦的房間，明亮而寬敞讓你覺得舒適，
兩旁的落地窗照進來些許的陽光，灑在中國風的屏風上，
你抬頭看見『君子之風』的匾額，似乎可以猜到主人的性格。

房間的角落擺著一台畫著山水畫的筆記型電腦，
螢幕裡跳動的文字，一瞬間你陷入了～狂～想～空～間～
LONG);
	setup();
	replace_program(ROOM);
}
