inherit ROOM;
void create() {
	set( "short", "EMC營區停車場" );
	set( "object", ([
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount8"  : 1,
		"file4"    : "/open/gblade/obj/sa-head",
		"file3"    : "/open/magic-manor/obj/dark-soul-dagger",
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"file2"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"amount3"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/mon/obj/ghost-cloak",
	]) );
	set( "owner", "adeyzit" );
	set( "build", 10605 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room111",
		"north"     : "/open/clan/13_luck/room/room289",
		"east"      : "/open/clan/13_luck/room/room292.c",
		"south"     : "/open/clan/13_luck/room/room290.c",
		"west"      : "/open/clan/13_luck/room/room291.c",
	]) );
	set( "long", @LONG
停車場..放著很多車車..軍用大卡..悍馬車..跟得力卡..及砲車
悍馬可以跑荒郊野外的山地..馬力夠強..上面還可以架四零榴彈槍與
一些砲..而砲車可以裝大一點的砲..得力卡為用車..加上指揮車..大
卡可以運兵..採買..但只能走大馬路..
LONG);
	setup();
	replace_program(ROOM);
}
