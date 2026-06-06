inherit ROOM;
void create() {
	set( "short", "江山如此多嬌" );
	set( "object", ([
		"file4"    : "/obj/gift/xiandan",
		"amount10" : 1,
		"file10"   : "/obj/gift/xiandan",
		"amount2"  : 1,
		"amount7"  : 1,
		"file1"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount8"  : 1,
		"amount9"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount6"  : 1,
		"amount3"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"file2"    : "/obj/gift/xiandan",
		"file3"    : "/obj/gift/xiandan",
		"file8"    : "/obj/gift/xiandan",
		"file9"    : "/obj/gift/xiandan",
		"file5"    : "/obj/gift/xiandan",
		"amount1"  : 1,
		"amount5"  : 1,
	]) );
	set( "light_up", 1 );
	set( "build", 14811 );
	set( "owner", "ctx" );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room528",
	]) );
	set( "long", @LONG
魔門和隱湖小築一戰後宣告解散,少林武當成為武林的仲裁
。大江盟一統江南武林,和江北慕容世家、蜀中唐門一道挾龐大
的資金，逐漸形成了三強鼎立的局面,武林一片歌舞昇平。其實
平靜的水面下暗流洶湧。大江盟盟主齊放的摯友、 鷹爪門掌門
況天被人暗殺於賀壽路上，拉開了武林大混戰的帷幕。而此時,
身負恩師遺命立志征服隱湖小築的王動正在踏往江湖的路上 。
是拯救武林於水火的大俠還是把道德踩在腳下的淫賊,王動短暫
的江湖生活演繹的一段奇異故事。

LONG);
	setup();
	replace_program(ROOM);
}
