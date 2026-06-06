inherit ROOM;
void create() {
	set( "short", "刀之墓" );
	set( "owner", "hild" );
	set( "object", ([
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/mon/obj/mon_item",
		"file7"    : "/open/mogi/dragon/obj/key",
		"file5"    : "/open/killer/obj/atman_pill",
		"file10"   : "/open/ghost-hole/obj/light-spirit",
		"amount8"  : 1,
		"file2"    : "/open/gsword/obj1/sball",
		"file9"    : "/open/ping/obj/cloud",
		"amount10" : 1,
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount1"  : 1,
		"amount3"  : 67,
		"amount2"  : 1,
		"amount7"  : 1,
		"amount5"  : 1140,
		"amount9"  : 1,
	]) );
	set( "build", 10170 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room306.c",
		"south"     : "/open/clan/sky-wu-chi/room/room90",
		"out"       : "/open/clan/sky-wu-chi/room/hall.c",
		"north"     : "/open/clan/sky-wu-chi/room/room168.c",
	]) );
	set( "long", @LONG
這裡陰風陣陣，讓人不寒而慄，仔細一看，這裡都是擺滿了寶刀，天下
中出名的刀，在這裡都可以看到，邪刀－刁，魚龍寶刀、無名寶刀、獅
頭寶刀、掛日刀一些相當成名的武器，遠處看有一個殺氣十足的守刀者
，凡是想要這裡的刀，全都要通過他的考驗才能拿的到，這個守刀者是
複數零的徒弟，這裡的刀都是由複數零所挑戰各方高守，所奪回的刀，
        他所奪回的刀，全都丟在這由，守刀者保管
LONG);
	setup();
	replace_program(ROOM);
}
