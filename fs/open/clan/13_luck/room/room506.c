inherit ROOM;
void create() {
	set( "short", "天旋堂大廳" );
	set( "object", ([
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file1"    : "/open/fire-hole/obj/p-pill",
		"file5"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"file8"    : "/open/fire-hole/obj/k-pill",
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount3"  : 7,
		"amount7"  : 5,
		"amount6"  : 40,
		"amount1"  : 5,
		"file7"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/fire-hole/obj/b-pill",
		"amount5"  : 148,
		"amount8"  : 17,
		"amount4"  : 11,
		"amount2"  : 25,
	]) );
	set( "build", 10712 );
	set( "owner", "fireer" );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room517.c",
		"north"     : "/open/clan/13_luck/room/room505",
	]) );
	set( "long", @LONG
你冒著必死的決心來到了天旋堂，你看到有二個人在大廳中對話，
一個坐在大廳的正中間，一個坐在一旁的椅子上，於是你定眼一看，坐
在大廳中間的是寒鐵衣，坐在一旁的是他的愛徒烈無雙，他們仿佛在談
論一些大事，當你接近他們時，二人身上突然散發出濃濃的殺氣，好像
要把你殺了的樣子，於是你機警的離開了此地。
LONG);
	setup();
	replace_program(ROOM);
}
