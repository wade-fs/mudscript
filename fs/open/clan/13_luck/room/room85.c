inherit ROOM;
void create() {
	set( "short", "殿前斜坡" );
	set( "object", ([
		"amount2"  : 123,
		"amount10" : 50,
		"amount6"  : 1,
		"file8"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file7"    : "/open/fire-hole/obj/r-pill",
		"amount9"  : 190,
		"file9"    : "/open/mogi/castle/obj/sspill",
		"file4"    : "/open/fire-hole/obj/y-pill",
		"file10"   : "/open/killer/obj/atman_pill",
		"amount5"  : 1,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file1"    : "/open/fire-hole/obj/p-pill",
		"file5"    : "/obj/gift/shenliwan",
		"amount1"  : 14,
		"file2"    : "/open/fire-hole/obj/b-pill",
		"amount3"  : 449,
		"file6"    : "/obj/gift/unknowdan",
		"amount8"  : 3,
		"amount4"  : 100,
		"amount7"  : 50,
	]) );
	set( "build", 10728 );
	set( "exits", ([
		"out"       : "/open/clan/13_luck/room/room81.c",
		"west"      : "/open/clan/13_luck/room/room106",
		"north"     : "/open/clan/13_luck/room/room500",
		"south"     : "/open/clan/13_luck/room/room491.c",
		"down"      : "/open/clan/13_luck/room/room87.c",
	]) );
	set( "light_up", 1 );
	set( "long", @LONG

    從門外巨龍口中進入，這才發現原來狂龍居是把整個鳳凰堐鑿空
，整座狂龍殿的走向是由鳳凰山峰向下延伸，把山內走道闢成樓梯一
直蜿蜒而下。四周圍並沒有火把照明，光線也無法照射進來，可是就
是能看到附近的環境，原來走道兩旁岩壁中鑲著一顆顆價值連城的夜
明珠。看著山洞形勢險峻，沒有上好輕功還站不住腳，僅慎之餘不禁
佩服其鬼斧神工。

LONG);
	setup();
	replace_program(ROOM);
}
