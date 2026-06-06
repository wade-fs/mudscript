inherit ROOM;
void create() {
	set( "short", "學武之道" );
	set( "owner", "smalloo" );
	set( "object", ([
		"amount9"  : 1,
		"amount8"  : 6,
		"file10"   : "/open/sky/obj10/maple_yin",
		"amount2"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"file9"    : "/obj/gift/shenliwan",
		"file8"    : "/open/fire-hole/obj/w-pill",
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/fire-hole/obj/r-pill",
		"file4"    : "/open/mogi/castle/obj/sspill",
		"amount7"  : 14,
		"amount1"  : 1,
		"amount3"  : 37,
		"file5"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount10" : 1,
		"amount4"  : 30,
		"file6"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file1"    : "/daemon/class/bonze/puty_pullium",
	]) );
	set( "build", 11358 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room336",
		"south"     : "/open/clan/13_luck/room/room333.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    松林中靜俏俏地沒半點聲息，下弦月不甚明亮，映著野松林。照
得人面皆轉過了良久忽聽得林中一聲呼哨，左側和右側各有一行黑衣
漢子奔出，原來是神風堂的門徒正在努力練習輕功。此時厚厚黑黑的
雲層吹過來，壓得你喘不過氣來，連忙運功自保。


LONG);
	setup();
	replace_program(ROOM);
}
