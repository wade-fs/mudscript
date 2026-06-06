inherit ROOM;
void create() {
	set( "short", "迷之迴廊" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file10"   : "/obj/gift/bingtang",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount2"  : 1,
		"amount5"  : 1,
		"file2"    : "/daemon/class/bonze/puty_pullium",
		"amount8"  : 1,
		"file6"    : "/open/capital/room/king/obj/dagger1",
		"file8"    : "/open/dancer/obj/yuaboots",
		"amount10" : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file1"    : "/daemon/class/fighter/figring",
		"amount9"  : 1,
		"amount3"  : 1,
		"file4"    : "/open/killer/headkill/obj/world_dag",
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file7"    : "/open/mogi/village/obj/mogi_ring",
		"file9"    : "/open/killer/headkill/obj/bluekill",
		"file5"    : "/obj/gift/hobowdan",
	]) );
	set( "build", 10055 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room220.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
你走進了一條黑暗的長廊，在這裡，時間，空間都不再存在，
無盡的虛空包圍著你，生命在這裡彷彿是多餘的東西，你只
能在前一個人所留下的屍體上得到一點餘溫，繼續尋找傳聞
中絕世殺手的隱居處，突然，一道幻影從你背後出現，殺氣，
前所為有的殺氣，一把利劍插入你的體內，剎那間你的靈魂
殺氣，一把利劍插入你的體內，剎那間你的靈魂
LONG);
	setup();
	replace_program(ROOM);
}
