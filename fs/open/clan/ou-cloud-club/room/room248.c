inherit ROOM;
void create() {
	set( "short", "$CYN$望 $RED$萍 $GRN$軒$NOR$" );
	set( "owner", "perth" );
	set( "object", ([
		"file6"    : "/open/mon/obj/ghost-cloak",
		"amount10" : 1,
		"file8"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"file7"    : "/daemon/class/bonze/puty_pullium",
		"amount8"  : 1,
		"amount4"  : 1,
		"file3"    : "/obj/gift/unknowdan",
		"amount5"  : 1,
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount3"  : 1,
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/magic-manor/obj/lin-cloud-fan",
		"file5"    : "/open/mon/obj/ghost-legging",
		"file10"   : "/obj/gift/xiandan",
		"file1"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
		"file9"    : "/obj/gift/shenliwan",
		"amount9"  : 1,
	]) );
	set( "build", 10232 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room257.c",
	]) );
	set( "long", @LONG
這裡是speed 的家, 每當想起家萍時, 他就會
一個人到這裡來靜靜沉思, 後悔當時做的錯誤決定
現在只期盼有一天家萍會回到他的身邊. 牆壁上刻
著當初送給家萍的詩, 上面寫著 :

              句  鍾 令  萍  家    
              句  愛 吾  水  喻
              真  一 初  相  戶
              情  生 識  逢  曉
              皆  亦 便  東  聲
              為  不 頃  吳  如
              妳  悔 心  裡  鶯                         



LONG);
	setup();
	replace_program(ROOM);
}
