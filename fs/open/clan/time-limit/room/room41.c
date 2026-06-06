inherit ROOM;
void create() {
	set( "short", "$GRN$圖$RED$書$MAG$館$NOR$" );
	set( "owner", "goldblade" );
	set( "object", ([
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/gold/obj/golden-blade",
		"file1"    : "/open/magic-manor/gold/obj/golden-blade",
		"file9"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount2"  : 1,
		"amount6"  : 1,
		"file2"    : "/open/magic-manor/gold/obj/golden-blade",
		"amount1"  : 1,
	]) );
	set( "build", 10154 );
	set( "exits", ([
		"north"     : "/open/clan/time-limit/room/room43",
	]) );
	set( "long", @LONG
圖書館是學生們追求新知的好地方,用功的學生都會在這邊唸書,
瞧!'妙麗-格蘭傑'正在翻閱一本超強咒語全集,圖書館分成一般區和禁書區,
其中禁書區需要有教授的同意書,圖書館長'平斯夫人'才會允許進入閱讀,
主要因為有些禁書記載著邪惡的黑魔法,或是會有困在書中的惡靈傷害學生,
才會分成兩個區域,另外平斯夫人絕對禁止學生在圖書館裡練習魔法,
因為一不小心就會把書給炸掉!

LONG);
	setup();
	replace_program(ROOM);
}
