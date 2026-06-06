inherit ROOM;
void create() {
	set( "short", "小二的武器房間二" );
	set( "owner", "yuki" );
	set( "object", ([
		"file1"    : "/open/magic-manor/wood/obj/wood-sword",
		"file3"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount7"  : 1,
		"file10"   : "/obj/gift/xiandan",
		"amount6"  : 1,
		"amount2"  : 1,
		"file5"    : "/open/magic-manor/soil/obj/soil-claw",
		"file7"    : "/open/magic-manor/water/obj/water-ribbon",
		"file6"    : "/open/magic-manor/soil/obj/soil-claw",
		"amount10" : 1,
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"amount8"  : 3,
		"file2"    : "/open/magic-manor/obj/evil-kill-claw",
		"file9"    : "/obj/gift/lingzhi",
		"file4"    : "/open/magic-manor/soil/obj/soil-claw",
		"file8"    : "/open/mogi/castle/obj/ninepill",
	]) );
	set( "build", 10068 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room410",
		"east"      : "/open/clan/sky-wu-chi/room/room201",
	]) );
	set( "long", @LONG
    這裡是小二的武器房間
你的眼前一陣七色光芒跟隔壁依樣
地上擺著各式各樣的武器
也有聚靈山莊八傻的武器嘛
小二憑藉著廣大的人脈
和各方好漢蒐集了各種的武器擺在這裡
看來fs裡面應該沒有他拿不到的優良eq了吧
此外還有各種master的優良武器
也都擺在這裡
只要是不能save的這裡幾乎都有
LONG);
	setup();
	replace_program(ROOM);
}

