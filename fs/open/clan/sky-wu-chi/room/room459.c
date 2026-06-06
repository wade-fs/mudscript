inherit ROOM;
void create() {
	set( "short", "拍賣屋" );
	set( "object", ([
		"file9"    : "/u/n/neverend/present/777",
		"file5"    : "/obj/gift/xisuidan",
		"file1"    : "/open/gsword/obj/spsword-1",
		"amount4"  : 318,
		"file4"    : "/open/killer/obj/s_pill",
		"amount9"  : 1,
		"amount5"  : 1,
		"amount2"  : 80,
		"file3"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"file2"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount1"  : 1,
		"file7"    : "/open/mon/obj/flower-claw",
		"amount7"  : 1,
	]) );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room502",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"out"       : "/open/clan/sky-wu-chi/room/room17",
		"east"      : "/open/clan/sky-wu-chi/room/room492.c",
	]) );
	set( "build", 12215 );
	set( "light_up", 1 );
	set( "long", @LONG
這裡是一間拍賣很古老的武器和裝備的房屋..裡面有各式各樣的物
品..可是你卻無法去動到它..因為它是這間屋子的主人GiGa所擁有的..如
果你真的要動到這樣物..一定要經過GiGa本人的同意才可以..否則的話你
是會被下詛咒..永遠也解不了的詛咒........
LONG);
	setup();
	replace_program(ROOM);
}
