inherit ROOM;
void create() {
	set( "short", "內有惡犬" );
	set( "owner", "roar" );
	set( "object", ([
		"amount4"  : 200,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount1"  : 138,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 1,
		"file6"    : "/obj/gift/bingtang",
		"amount6"  : 1,
		"file2"    : "/open/fire-hole/obj/r-pill",
		"file5"    : "/obj/gift/xiandan",
		"amount7"  : 1,
		"file8"    : "/open/capital/obj/4-1",
		"amount2"  : 100,
		"amount10" : 355,
		"amount3"  : 54,
		"file7"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"amount9"  : 1,
		"file10"   : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/ping/obj/poison_pill",
		"file9"    : "/obj/gift/xiandan",
	]) );
	set( "build", 10427 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room83.c",
		"enter"     : "/open/clan/13_luck/room/room88",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG
你已踏進這地方就被這四個字嚇到了”內有惡犬”？？心想，自己一
生行走江湖，什麼東西沒看過，但這”內有惡犬”是指什麼呢？自己始終
是滿懷疑問，但還是想一看究竟，此時跑出一隻不算小的狗，看似即為可
愛，你忍不住去摸她，發現她叫胖胖，原來是屋主故意要嚇陌生人的大狗
。
LONG);
	setup();
	replace_program(ROOM);
}
