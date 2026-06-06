inherit ROOM;
void create() {
	set( "short", "酷的龜房" );
	set( "owner", "cool" );
	set( "object", ([
		"amount2"  : 1,
		"file1"    : "/open/mon/obj/ghost-helmet",
		"amount9"  : 1,
		"amount1"  : 1,
		"file2"    : "/open/mon/obj/ghost-legging",
		"amount3"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"file9"    : "/open/wind-rain/obj/sun_red_cloth",
	]) );
	set( "build", 10197 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room101",
		"enter"     : "/open/clan/13_luck/room/room307",
	]) );
	set( "long", @LONG

－*0*－　小魔女的魔法屋　－>.<－　
＠＠首先粉歡迎你的到來＠＠，這裡面有很多你意想不到的驚喜喔，
向左邊看印入眼簾的是一堆可愛的 kity 喵，向右邊看是一些令人嘆
為觀止的防具及武器，而正前方掛著一幅豬頭人身的畫像，那就是

         ＠我最敬愛的師父＠

　           可愛小豬頭        *@_@*


LONG);
	setup();
	replace_program(ROOM);
}
