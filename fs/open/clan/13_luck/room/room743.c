inherit ROOM;
void create() {
	set( "short", "雪狼族" );
	set( "object", ([
		"file4"    : "/open/magic-manor/water/obj/water-ribbon",
		"amount9"  : 1,
		"amount1"  : 1,
		"amount8"  : 1,
		"amount5"  : 1,
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"amount4"  : 1,
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount6"  : 1,
		"amount7"  : 1,
		"amount10" : 1,
		"file6"    : "/obj/gift/shenliwan",
		"file3"    : "/open/mon/obj/thousand-nectar",
		"file9"    : "/open/mon/obj/thousand-nectar",
		"file1"    : "/open/mogi/castle/obj/fire-king-head",
		"amount2"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"file7"    : "/obj/gift/unknowdan",
	]) );
	set( "build", 10037 );
	set( "owner", "markw" );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room727",
	]) );
	set( "long", @LONG
相傳在天山山脈有一座天險峰，在這座山峰的南面住著一群人，這群人負責
守護這座山峰，因為在天險峰上有一個洞穴，穴裡住著一群狼，毛色白得發亮，
就像山上的雪一樣，世人喚牠們叫雪狼，牠們棲息的洞穴稱作雪狼穴，而保護這
群狼的人就是─雪狼族。雪狼族個個身懷絕世輕功，因常年居於這高海拔的區域
其心跳較一般人慢，呼吸也較一般人長且流暢，幾乎可以說是環境使得他們個個
都有不錯的內功底子，只要稍加訓練，便可成為武林好手。究竟為何該族人要誓
死保護雪狼呢？據說當年該族人受到匈奴人的侵害，逃到了這個地方，但是許多
族人因這惡劣的環境相繼死亡，就在此時，一群雪狼叼著天山最珍貴的產物─天
山雪蓮，出現在他們眼前，他們在服下後才活了下來，當時的族長便定下族規：
雪狼族人受雪狼之恩澤，其恩澤如同再造父母，使我族得以綿延下去，我僅代表
雪狼族對天起誓，雪狼族族人世世代代，定必誓死保護雪狼，不得有誤！中原的
武林人士皆打著天山雪蓮的算盤，由於這稀世奇珍生長在雪狼穴內，必須殺了雪
狼才能得到，雪狼族為了打退這群武林高手，於是模仿雪狼跳、躍、閃、蹬的方
式創出了 天山雪影步 來保護救了他們一族的大恩人。

LONG);
	setup();
	replace_program(ROOM);
}
