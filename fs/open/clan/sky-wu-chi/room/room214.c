inherit ROOM;
void create() {
    set( "short", "ω草房ω");
	set( "owner", "match" );
	set( "object", ([
		"amount10" : 33,
		"file9"    : "/open/fire-hole/obj/g-pill",
		"file7"    : "/open/fire-hole/obj/p-pill",
		"amount6"  : 19,
		"amount3"  : 92,
		"file1"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/fire-hole/obj/k-pill",
		"amount7"  : 40,
		"amount9"  : 34,
		"file8"    : "/open/fire-hole/obj/w-pill",
		"file5"    : "/open/fire-hole/obj/r-pill",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file4"    : "/open/fire-hole/obj/b-pill",
		"amount1"  : 19,
		"file10"   : "/open/fire-hole/obj/y-pill",
		"file2"    : "/open/killer/obj/s_pill",
		"amount2"  : 990,
		"amount8"  : 10,
		"amount4"  : 33,
		"amount5"  : 25,
	]) );
	set( "build", 10016 );
	set( "light_up", 1 );
	set( "exits", ([
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"north"     : "/open/clan/sky-wu-chi/room/room432",
		"west"      : "/open/clan/sky-wu-chi/room/room395.c",
		"east"      : "/open/clan/sky-wu-chi/room/room130.c",
	]) );
	set( "long", @LONG
這是傳說中的----ω草房ω----，一進來就聞到濃濃的血腥味，
因為他是傳說中●●獨二無一●●的殺手，殺遍天下無敵手，可不小
看他喔，小心他會隨時出來殺掉你的手指頭喔，也不要隨便亂逛，這
裡所有的一切都是屬於草的，你看多了對你沒好處的，左右兩邊分別
是放裝備用的，因為他要殺的手指頭太多了，所以需要不同的武器來
應付。
LONG);
	setup();
	replace_program(ROOM);
}
