inherit ROOM;
void create() {
	set( "short", "不歸路" );
	set( "owner", "mill" );
	set( "object", ([
		"amount1"  : 21,
		"amount2"  : 11,
		"file3"    : "/open/mogi/castle/obj/ninepill",
		"file1"    : "/open/fire-hole/obj/r-pill",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount3"  : 16,
	]) );
	set( "build", 10001 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room488",
	]) );
	set( "long", @LONG

    這裡一片荒涼，一眼望去都是一些以枯死的樹木，天空上不時傳來
烏鴉的叫聲，抬頭往上看去有幾隻禿鷹在上空盤旋不走，似忽是在尋找
食物，路旁有一塊石碑 (stone)，上面的字都以膜糊不清﹗往東看去亦
是一片荒涼，往西有條小路可通往..。

LONG);
	setup();
	replace_program(ROOM);
}
