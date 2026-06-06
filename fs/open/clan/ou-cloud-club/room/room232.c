inherit ROOM;
void create() {
	set( "short", "邪‧心‧界" );
	set( "object", ([
		"file3"    : "/open/mogi/castle/obj/fire_book",
		"amount4"  : 1,
		"file9"    : "/open/ghost-hole/obj/light-spirit",
		"file2"    : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/ghost-hole/obj/light-spirit",
		"amount9"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/wu/obj/ya-head",
		"amount5"  : 1,
		"file4"    : "/open/gblade/obj/sa-head",
		"amount3"  : 1,
		"amount6"  : 1,
		"file7"    : "/open/ghost-hole/obj/light-spirit",
		"file1"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 1,
		"file6"    : "/open/prayer/obj/lin-head",
	]) );
	set( "owner", "del" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room33",
	]) );
	set( "build", 11076 );
	set( "light_up", 1 );
	set( "long", @LONG
沿著小徑緩緩前進，來到了一間空間廣闊的石室，光線
是從較為上層的石壁透光而來，石室的正中央放著一個琉璃
座，上面放著一把水藍色的刀，隱隱泛著誘人的藍光，當你
接近的時候突然感覺到一股妖氣在空氣中瀰漫，四週的聲音
彷彿都被在一瞬間被抽空，只有你的心跳聲依然撲通、撲通
的在耳邊圍繞。
  
LONG);
	setup();
	replace_program(ROOM);
}
