inherit ROOM;
void create() {
	set( "short", "『祠堂』" );
	set( "owner", "poll" );
	set( "object", ([
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gem",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-armband",
		"amount7"  : 1,
		"file3"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"amount3"  : 1,
		"amount2"  : 1,
		"amount10" : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-armband",
	]) );
	set( "build", 10407 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room446",
		"east"      : "/open/clan/13_luck/room/room448",
	]) );
	set( "long", @LONG

     這裡是墨教的祠堂，墨教歷代總鉅子和執法、賞善二使的牌位都在此，
 這裡也放著各式各樣的書，都是有關墨教的歷史，和武功記載，看著桌前的
 鮮花素果不禁讓你生出一股思古之幽情，桌上放著牌位，從墨子開始，道此
 代應該有三十個牌位，可是你算來算去卻只有二十九個牌位，你心中不禁生
 出疑問，到底那一個到那裡去了呢？


LONG);
	setup();
	replace_program(ROOM);
}
