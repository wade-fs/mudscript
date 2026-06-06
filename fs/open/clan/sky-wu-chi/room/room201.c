inherit ROOM;
void create() {
	set( "short", "武器房間" );
	set( "owner", "yuki" );
	set( "object", ([
		"amount3"  : 90000,
		"file7"    : "/open/marksman/obj/arrow-g",
		"amount8"  : 90000,
		"file4"    : "/open/marksman/obj/arrow-g",
		"file1"    : "/open/marksman/obj/arrow-g",
		"amount6"  : 90000,
		"file5"    : "/open/marksman/obj/arrow-g",
		"amount1"  : 90000,
		"amount9"  : 90000,
		"amount7"  : 90000,
		"amount2"  : 90000,
		"file3"    : "/open/marksman/obj/arrow-g",
		"file6"    : "/open/marksman/obj/arrow-g",
		"amount4"  : 90000,
		"file9"    : "/open/marksman/obj/arrow-g",
		"file8"    : "/open/marksman/obj/arrow-g",
		"amount10" : 90000,
		"file10"   : "/open/marksman/obj/arrow-g",
		"file2"    : "/open/marksman/obj/arrow-g",
		"amount5"  : 90000,
	]) );
	set( "build", 10260 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room205.c",
		"east"      : "/open/clan/sky-wu-chi/room/room203.c",
	]) );
	set( "long", @LONG
這裡是小二的武器房間
你的眼前一陣七色光芒天那
擺在地上的
不就是
聚靈山莊八傻的武器嘛
怎會出現在這裡
小二憑藉著廣大的人脈
和各方好漢蒐集了各種的武器擺在這裡
看來fs裡面應該沒有他拿不到的優良eq了吧
可是看一看...好像還少了什麼東西....
難道是...
LONG);
	setup();
	replace_program(ROOM);
}
