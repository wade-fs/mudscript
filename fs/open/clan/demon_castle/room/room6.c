// Room : /open/clan/demon_castle/room/room6.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "no_clean_up", 0 );
	set( "no_transmit", 1 );
	set( "cmkroom", 1 );
	set( "short", "ζ紫星堂ζ" );
	set( "owner", "mory" );
	set( "object", ([
		"amount7"  : 1,
		"file1"    : "/open/killer/headkill/obj/world_dag",
		"file7"    : "/open/main/obj/firesword",
		"amount5"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/doctor/pill/gnd_pill",
		"file5"    : "/open/ping/obj/iceger",
		"amount8"  : 11,
		"amount3"  : 5,
		"amount1"  : 1,
		"file4"    : "/open/magic-manor/obj/magic-sign",
		"amount9"  : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/open/gsword/obj/ring-1",
		"file8"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 1,
		"amount2"  : 1,
		"file10"   : "/open/killer/weapon/k_torch",
	]) );
	set( "light_up", 1 );
	set( "build", 10661 );
	set( "clan_room", "惡魔城" );
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/demon_castle/room/room20.c",
		"south"     : "/open/clan/demon_castle/room/room5.c",
		"west"      : "/open/clan/demon_castle/room/room19.c",
]) );
	set( "long", @LONG

    走進此地隱約有一股無名的殺氣緊盯著妳，四周的空氣有如寒冰
結霜般的令妳透不過氣來，寒風颼颼的吹，妳的心跳亦隨著加速跳動
眼前一位神秘之人盤坐於七彩靈石之上吸收著大地精華，透露出一種
詭異的感覺，看來此處不是你久留之地，還是趁早離開為妙。

LONG);
	setup();

	}
