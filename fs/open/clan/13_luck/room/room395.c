inherit ROOM;
void create() {
	set( "short", "閉關室" );
	set( "owner", "roar" );
	set( "object", ([
		"amount8"  : 1,
		"file1"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount1"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount6"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gloves",
	]) );
	set( "build", 10029 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room397",
	]) );
	set( "long", @LONG

    這裡是提供拳堂弟子悟出更高拳義的地方，為了使自己變的更強就必
讓自己的武學更上一層樓，當練武練到瓶頸之時，所需要的並不是師父的
一再指導，而是將自己的心靜下來，思考武學奧妙之處。若能突破這道難
關成為武者中的佼佼者並非一件難事。

LONG);
	setup();
	replace_program(ROOM);
}
