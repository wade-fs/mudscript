inherit ROOM;
void create() {
	set( "short", "秘密藥房" );
	set( "object", ([
		"amount1"  : 1,
		"file1"    : "/open/gblade/obj/sa-head",
		"amount9"  : 1,
		"amount2"  : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/obj/stone/powder",
		"file2"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 10815 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room292.c",
		"south"     : "/open/clan/sky-wu-chi/room/room411",
		"west"      : "/open/clan/sky-wu-chi/room/room286.c",
		"back"      : "/open/clan/sky-wu-chi/room/room251",
		"east"      : "/open/clan/sky-wu-chi/room/room233.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
	]) );
	set( "long", @LONG
這裡是AMEI的秘密藥房，這裡擺滿了救命三靈丹這些丹藥十分的珍貴
，假如你沒有得到同意別隨便亂拿O，尤其是幫裡需要去打大魔王時一定
會用到這些丹藥，不過你有急需的話也可以跟AMEI說一聲她會拿些給你的
千萬不要自己拿O.......
LONG);
	setup();
	replace_program(ROOM);
}
