inherit ROOM;
void create() {
	set( "short", "小喵道具房" );
	set( "object", ([
		"amount10" : 1,
		"amount8"  : 103,
		"file4"    : "/open/fire-hole/obj/w-pill",
		"amount9"  : 69,
		"file8"    : "/open/fire-hole/obj/p-pill",
		"amount1"  : 294,
		"file6"    : "/open/fire-hole/obj/b-pill",
		"file2"    : "/open/fire-hole/obj/k-pill",
		"file3"    : "/open/fire-hole/obj/r-pill",
		"file1"    : "/open/fire-hole/obj/g-pill",
		"amount2"  : 10,
		"amount4"  : 55,
		"amount6"  : 79,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount3"  : 165,
		"file9"    : "/open/fire-hole/obj/y-pill",
	]) );
	set( "build", 10307 );
	set( "owner", "cong" );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room99",
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "long", @LONG
這是一小喵專用的道具間 , 這裡放著各式各樣的道具 , 為
世界道具最為齊全之地 , 你看到各種奇怪的道具 , 所謂工欲善
其事 ,必先利其器 , 看來 ,你也該為自己選把像樣的道具 , 好
闖蕩江湖 .你可以看看(list)參觀一下這裡的防具 ?

LONG);
	setup();
	replace_program(ROOM);
}
