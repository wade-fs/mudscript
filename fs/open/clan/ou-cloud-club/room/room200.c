inherit ROOM;
void create() {
	set( "short", "失去才能領略更多美麗" );
	set( "owner", "hys" );
	set( "item_desc", ([
		"不想" : @ITEM
ITEM,
	]) );
	set( "object", ([
		"amount3"  : 1,
		"file9"    : "/obj/gift/hobowdan",
		"amount4"  : 1,
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"amount2"  : 8,
		"amount9"  : 1,
		"file4"    : "/obj/gift/hobowdan",
		"file8"    : "/obj/gift/hobowdan",
		"file1"    : "/obj/stone/powder",
		"amount5"  : 1,
		"file2"    : "/obj/stone/suipian",
		"amount8"  : 1,
		"amount1"  : 116,
		"file3"    : "/open/mogi/dragon/obj/dragon-head",
	]) );
	set( "build", 10114 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room227",
		"west"      : "/open/clan/ou-cloud-club/room/room197",
	]) );
	set( "long", @LONG
在我們擁有的時候，總是害怕著失去，
但?許必須藉由失去，我們才能夠不再畫地自限，
反而擁有更多美麗的經驗。
失戀了，斤斤計較你辜負我多少，我有哪些不甘，是人之常情，
但分手自有分手的理由，何不在痛過之後，自我安慰；
以前老是擔心會分手，現在沒什麼好擔心了；
以前總在抱怨他對我不好，現在我再?不必受到不好的對待。
以前只能守著一株草，現在到處都可能有芳草。
如果不要只著眼於一時的失去，
失戀，失業，失婚，都可能帶來更寬闊的視野。
只要不失去生命，我們依然大有可為。
LONG);
	setup();
	replace_program(ROOM);
}
