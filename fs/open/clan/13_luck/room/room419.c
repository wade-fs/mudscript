inherit ROOM;
void create() {
	set( "short", "石板大道" );
	set( "object", ([
		"file1"    : "/open/magic-manor/fire/obj/fire-fan",
		"file7"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 1,
		"amount8"  : 160,
		"amount7"  : 160,
		"amount1"  : 1,
		"amount2"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"file9"    : "/obj/gift/bingtang",
		"file6"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount4"  : 1,
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount10" : 1,
		"file10"   : "/obj/gift/lingzhi",
		"file8"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "owner", "mwf" );
	set( "build", 10368 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room418",
		"south"     : "/open/clan/13_luck/room/room420.c",
	]) );
	set( "long", @LONG

    離開了廣場往北走，十三吉祥的大門已經可以從這裡望見，是和廣場
中的塔臺遙遙相對著，可以互相支援對抗敵人，北邊的大門非常巨大，但
卻沒有莊嚴的感覺，只有在陰森中透著肅穆，門前有守衛在來來往往地巡
邏著，他們的臉上都透著一股肅殺之氣，給人一股有死無生的感覺，讓人
不禁望之卻步!!

LONG);
	setup();
	replace_program(ROOM);
}
