inherit ROOM;
void create() {
	set( "short", "燕雲閣" );
	set( "object", ([
		"amount8"  : 1,
		"amount10" : 1,
		"amount7"  : 1,
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount1"  : 1,
		"amount6"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount2"  : 1,
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"amount9"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gem",
	]) );
	set( "owner", "roar" );
	set( "build", 10311 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room391",
	]) );
	set( "long", @LONG

    一間打掃的清潔雅致的小房間，是給門主的家眷居住之用的，裝潢
非常具有文雅的氣氛，和十三吉祥的風格不同，就好像是一股清流流入
這裡一般，讓人到了這裡就有一股舒適安祥的感覺，小桌前站著一位美
女，應該是堂主的妻子吧???看來在這避難的人也不全是窮凶惡極之輩

LONG);
	setup();
	replace_program(ROOM);
}
