inherit ROOM;
void create() {
	set( "short", "$HIR$麥當勞$HIY$大廳$HIC$一樓$NOR$" );
	set( "owner", "hild" );
	set( "object", ([
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount1"  : 1,
		"amount3"  : 1,
		"file4"    : "/daemon/class/bonze/puty_pullium",
		"file1"    : "/open/sky/obj/lucky_grasslink",
		"amount7"  : 1,
		"amount4"  : 1,
		"file7"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 10264 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room444.c",
		"south"     : "/open/clan/sky-wu-chi/room/room442.c",
		"north"     : "/open/clan/sky-wu-chi/room/room446.c",
		"southeast" : "/open/clan/sky-wu-chi/room/room449.c",
		"northwest" : "/open/clan/sky-wu-chi/room/room448.c",
		"dragon"    : "/open/clan/sky-wu-chi/room/room481",
		"east"      : "/open/clan/sky-wu-chi/room/room443.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"southwest" : "/open/clan/sky-wu-chi/room/room447",
		"blade"     : "/open/clan/sky-wu-chi/room/room545",
		"up"        : "/open/clan/sky-wu-chi/room/room445.c",
		"northeast" : "/open/clan/sky-wu-chi/room/room450.c",
		"enter"     : "/open/clan/sky-wu-chi/room/room460.c",
	]) );
	set( "long", @LONG
你身處在麥當勞的大廳，這裡有可愛的女服務生正在對著你微笑，正用親切的
笑容在問你要點何物，不過這裡好像是某個人的管區，最好不要隨便亂來的好。不
過你可以問一下這裡到底有何物，可是說不說就在於店員和管理者了喔。
LONG);
	setup();
	replace_program(ROOM);
}
