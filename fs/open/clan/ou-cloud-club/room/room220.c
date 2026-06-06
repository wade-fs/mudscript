inherit ROOM;
void create() {
	set( "short", "$BLU$無亟魔道$NOR$" );
	set( "owner", "del" );
	set( "object", ([
		"file2"    : "/open/mogi/castle/obj/ninepill",
		"amount9"  : 1200,
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file9"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/fire-hole/obj/p-pill",
		"amount4"  : 1100,
		"amount3"  : 200,
		"amount1"  : 200,
		"amount5"  : 80,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount8"  : 1200,
		"file1"    : "/open/fire-hole/obj/b-pill",
		"amount10" : 150,
		"amount7"  : 33,
		"file5"    : "/open/fire-hole/obj/k-pill",
		"file4"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 187,
		"file6"    : "/open/fire-hole/obj/y-pill",
		"file10"   : "/open/mon/obj/thousand-nectar",
		"amount6"  : 50,
	]) );
	set( "build", 10950 );
	set( "exits", ([
		"add"       : "/open/clan/ou-cloud-club/room/room356",
		"westup"    : "/open/clan/ou-cloud-club/room/room201.c",
	]) );
	set( "long", @LONG
沿著階梯緩緩而下，來到了一間空無一物的石室，光線
是從較為上層的石壁透光而來，仔細端詳才發現四周圍的牆
上，地面，甚至是天花板都有著密密麻麻、深淺不一的刀痕
，看來像是歷經多次刀意的淬煉才會如此。左手邊的牆壁上
有一個半人高的凹陷處，裡面放了五顏六色的藥丸。
ˉ
LONG);
	setup();
	replace_program(ROOM);
}
