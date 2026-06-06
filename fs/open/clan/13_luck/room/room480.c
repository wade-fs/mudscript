inherit ROOM;
void create() {
	set( "short", "寶號錢莊" );
	set( "object", ([
		"file4"    : "/open/magic-manor/fire/obj/fire-fan",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file3"    : "/open/center/obj/mechoufen-head",
		"file5"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"file10"   : "/open/center/obj/mechoufen-head",
		"file6"    : "/open/center/obj/mechoufen-head",
		"amount6"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"file9"    : "/open/center/obj/mechoufen-head",
		"amount5"  : 1,
		"amount7"  : 1,
		"file7"    : "/open/center/obj/mechoufen-head",
		"amount10" : 1,
		"file2"    : "/open/center/obj/mechoufen-head",
		"amount9"  : 1,
		"amount3"  : 1,
		"file8"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
	]) );
	set( "owner", "zmud" );
	set( "build", 10002 );
	set( "light_up", 1 );
	set( "exits", ([
		"up"        : "/open/clan/13_luck/room/room479",
		"west"      : "/open/clan/13_luck/room/room482.c",
	]) );
	set( "long", @LONG

　　這是一間素來以公平信用著稱的錢莊，老闆是個中年的老實人，錢
莊是他家的祖傳事業，現在已經是第三代了。錢莊的信用可靠，所以許
多的店家商號也喜歡在此存提錢款。櫃檯後邊的牆上貼著大紅紙 (pape
r)，上面寫著錢莊的服務項目，及各種交易須知。

LONG);
	setup();
	replace_program(ROOM);
}
