inherit ROOM;
void create() {
	set( "short", "毒人居" );
	set( "object", ([
		"amount3"  : 1,
		"file2"    : "/open/doctor/obj/needle9",
		"file3"    : "/open/killer/headkill/obj/e_dag",
		"file1"    : "/open/poison/obj/bleed_whip",
		"amount1"  : 1,
		"amount8"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ping/obj/ring-2",
		"file4"    : "/open/wu/npc/obj/armband",
	]) );
	set( "build", 10076 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room92",
		"east"      : "/open/clan/13_luck/room/room188",
	]) );
	set( "long", @LONG
來到這裡空氣中瀰漫的一股令人作嘔的氣息，房間雖然佈置的和
一般居家沒什麼兩樣，但隱隱約約的讓人覺得四週的擺設一定大
有文章，令人想一探此處的主人究竟為何人。  往西走可以回到
綠茶園的前庭，往東走則是通往毒藥房。
LONG);
	setup();
	replace_program(ROOM);
}
