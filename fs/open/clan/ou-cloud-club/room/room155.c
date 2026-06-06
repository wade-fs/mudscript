inherit ROOM;
void create() {
	set( "short", "英魂聖殿" );
	set( "object", ([
		"amount7"  : 1,
		"amount9"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/ghost-hole/obj/light-spirit",
		"amount3"  : 1,
		"file3"    : "/open/sky/obj/lucky_grasslink",
		"amount8"  : 1,
		"file8"    : "/open/scholar/obj/icefan",
		"file2"    : "/open/magic-manor/obj/hwa-je-icer",
		"file4"    : "/open/magic-manor/obj/magic-sign",
		"amount2"  : 1,
		"file7"    : "/open/mon/obj/ghost-cloak",
		"file1"    : "/open/ghost-hole/obj/light-spirit",
		"file10"   : "/open/mon/obj/ghost-helmet",
		"amount5"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/killer/obj/soul-hands",
		"file6"    : "/obj/gift/unknowdan",
	]) );
	set( "owner", "dracula" );
	set( "item_desc", ([
		"crystal" : @ITEM
渾天寶鑑博大精深, 總共十層, 依序為:

白雲煙
玫霞蕩
土崑崙
碧雪冰
紫星河
玄混沌
靛滄海
金晨曦
血蒼穹
玄宇宙

ITEM,
	]) );
	set( "build", 10120 );
	set( "exits", ([
		"out"       : "/open/clan/ou-cloud-club/room/room87",
	]) );
	set( "long", @LONG
空氣中飄著濃烈的憂鬱氣息, 彷彿感嘆英雄氣短, 世途多艱, 此地原是一位
無名英雄成名前的修行之地, 在這個英雄為了抵禦外族而毅然踏入魔道, 甚至
受到正道群雄圍剿而失蹤之後, 被許多誤解他的人所摧毀, 直到多年後, 眾人思
及他當日決戰神秘外族的赴死神威時, 才開始尊敬這個下落不明的英雄, 因此,
將他故居重新建立起來, 並祭起代表其流派, 永不熄滅的熊熊聖火, 以表示期盼
他歸來, 繼續統領群倫的一天, 往聖火最幟盛的中心點望去, 依稀可看到插滿了
渾天寶鑑十天晶(crystal)的天壇

    渾天寶鑑傳功水晶(crystal)
LONG);
	setup();
	replace_program(ROOM);
}
