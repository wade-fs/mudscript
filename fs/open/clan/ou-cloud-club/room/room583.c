inherit ROOM;
void create() {
	set( "short", "貝多芬第三號降E大調交響曲-英雄交響曲" );
	set( "owner", "ctx" );
	set( "item_desc", ([
		"instruction" : @ITEM
第一樂章：燦爛的快板(Allegro con brio)
第二樂章：流暢的行板(Marcia funebre. Adagio assai)
第三樂章：活潑的詼諧曲(Scherzo. Allegro vivace)
第四樂章：快板(Finale. Allegro molto)
ITEM,
	]) );
	set( "object", ([
		"file9"    : "/obj/gift/hobowdan",
		"file2"    : "/obj/gift/hobowdan",
		"file10"   : "/obj/gift/hobowdan",
		"amount6"  : 1,
		"file4"    : "/obj/gift/shenliwan",
		"file6"    : "/obj/gift/hobowdan",
		"amount2"  : 1,
		"amount9"  : 1,
		"amount3"  : 1,
		"file8"    : "/obj/gift/hobowdan",
		"file3"    : "/obj/gift/hobowdan",
		"file7"    : "/obj/gift/hobowdan",
		"amount7"  : 1,
		"amount5"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"file1"    : "/obj/gift/hobowdan",
		"amount8"  : 1,
		"file5"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
	]) );
	set( "build", 10026 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room592",
		"north"     : "/open/clan/ou-cloud-club/room/room582.c",
		"east"      : "/open/clan/ou-cloud-club/room/room590.c",
		"down"      : "/open/clan/ou-cloud-club/room/room545.c",
		"south"     : "/open/clan/ou-cloud-club/room/room591.c",
	]) );
	set( "long", @LONG
原本是準備獻給革命時代英雄拿破侖，貝多芬曾把拿破侖視
為偶像、英雄乃至神格化。但是，當他聽到這個原本為自由革命
的人，竟然重新恢復皇權加冕稱帝，貝多芬怒不可遏，痛責拿破
崙「不過是個凡夫俗子」! 他撕去了寫在樂譜上的獻詞。作品出
版時，標題改為《英雄交響曲》-- 紀念一位偉人而作。

       牆上貼了一本樂曲介紹(Instruction)

LONG);
	setup();
	replace_program(ROOM);
}
