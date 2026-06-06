inherit ROOM;
void create() {
	set( "short", "客房" );
	set( "owner", "kaien" );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room353",
	]) );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/dancer/obj/yuawaist",
		"amount8"  : 1,
		"file5"    : "/daemon/class/blademan/obj/ublade",
		"file8"    : "/open/mon/obj/ghost-cloak",
		"amount5"  : 1,
	]) );
	set( "build", 10140 );
	set( "light_up", 1 );
	set( "long", @LONG

    將軍府把他們的來客招待的周到無比，把款待客人的房間布置的非
常舒適。紅木桌上沏了一壺好茶，放了幾盤點心。屋角香爐裡傳來一陣
陣清香，房間四周掛滿了兵器、防具，每一樣東西都是世上僅存或是稀
有的，中間放著一張寬大柔軟的床上鋪著被褥，讓人不覺昏昏欲睡。

LONG);
	setup();
	replace_program(ROOM);
}
