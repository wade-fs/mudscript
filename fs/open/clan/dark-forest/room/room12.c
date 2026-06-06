inherit ROOM;
void create() {
	set( "short", "護城樹梢" );
	set( "owner", "really" );
	set( "object", ([
		"file5"    : "/open/gsword/obj/silver_sword",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount9"  : 1,
		"file10"   : "/obj/gift/lingzhi",
		"file2"    : "/open/fire-hole/obj/w-pill",
		"amount2"  : 24,
		"amount4"  : 1,
		"file9"    : "/open/dancer/obj/yuawaist",
		"file4"    : "/obj/gift/shenliwan",
		"file1"    : "/obj/gift/lingzhi",
		"amount1"  : 1,
		"amount10" : 1,
		"file8"    : "/obj/gift/xisuidan",
		"file7"    : "/obj/gift/xisuidan",
		"amount8"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 39,
		"file6"    : "/open/ghost-hole/obj/light-spirit",
	]) );
	set( "build", 10089 );
	set( "exits", ([
		"south"     : "/open/clan/dark-forest/room/room13",
		"westdown"  : "/open/clan/dark-forest/room/room3",
	]) );
	set( "long", @LONG
沿著巨樹周圍以精靈織法者製作的幽暗階梯拾級而上，你
來到了護城樹群的上方，在這裡你可以看到彼此交錯的枝葉形
成一道平坦的走道往南方延伸而去，偶而會有路過的精靈與你
擦肩而過並對你報以親切的微笑。

  $HIC$高地精靈$NOR$ 熙亞儂(Rhiannon)
LONG);
	setup();
	replace_program(ROOM);
}
