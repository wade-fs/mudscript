inherit ROOM;
void create() {
	set( "short", "紫雲的書房" );
	set( "object", ([
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount7"  : 1,
		"file5"    : "/obj/gift/shenliwan",
		"file2"    : "/open/fire-hole/obj/p-pill",
		"amount2"  : 20,
		"file7"    : "/open/capital/obj/force_book",
		"file9"    : "/open/capital/obj/blade2",
		"amount5"  : 1,
		"file8"    : "/open/capital/obj/sword_book",
		"file3"    : "/open/fire-hole/obj/g-pill",
		"amount8"  : 1,
		"amount3"  : 5,
		"amount9"  : 1,
		"file6"    : "/open/capital/obj/steps_book",
		"amount1"  : 15,
		"amount6"  : 1,
		"file1"    : "/open/fire-hole/obj/w-pill",
		"amount4"  : 1,
	]) );
	set( "build", 10246 );
	set( "light_up", 1 );
	set( "owner", "scsf" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room236",
	]) );
	set( "long", @LONG
這是紫雲花費上萬兩銀票四處蒐集到的書本,左邊書架上放的是
基本技能之書,舉凡任一基本技能均可在此看到
而在中間這個書架上,放滿了小說,雜誌,漫畫.是
紫雲在空閒時的一大娛樂之一.右手邊的書架上放的則是狂想中
的珍藏書籍,例如:極火真經.連陽劍譜.魔日劍譜.先天乾坤功正卷.
魔界金典.英雄真經.英雄新經.等等
LONG);
	setup();
	replace_program(ROOM);
}
