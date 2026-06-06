inherit ROOM;
void create() {
	set( "short", "早安少女組" );
	set( "owner", "borkiller" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file1"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount4"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount7"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"file7"    : "/open/mogi/dragon/obj/scale",
		"amount5"  : 1,
		"amount2"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 10704 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room240",
	]) );
	set( "long", @LONG
早安少女
吉澤瞳
1985/4/12/O型/琦玉縣出生
加護亞依
1988/2/7/AB型/奈良縣出生
過希美
1987/6/17/O型/東京都出生
矢口真里
1983/1/20/A型/神奈川縣出生
這四個是我覺得最可愛的
LONG);
	setup();
	replace_program(ROOM);
}
