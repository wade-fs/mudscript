inherit ROOM;
void create() {
	set( "short", "$HIW$『$HIC$湘王居$HIW$』$NOR$" );
	set( "owner", "working" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/gsword/obj1/bpball",
		"file1"    : "/open/gsword/obj1/bbladeball",
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/magic-sign",
	]) );
	set( "exits", ([
		"east"      : "/open/clan/orient/room/room66.c",
		"south"     : "/open/clan/orient/room/room58",
		"west"      : "/open/clan/orient/room/room37.c",
	]) );
	set( "build", 10159 );
	set( "light_up", 1 );
	set( "long", @LONG

$HIR$    天使伸手用力地拽下身後的潔白雙翅。
$HIR$    大量的鮮血噴出，濺紅了那些塵土，天使俯在塵土上，再也沒張開過眼睛。

$HIY$    若能克服慾望，你能支配眾人，若屈服於慾望，你將貧賤而成為眾人的奴隸。

$HIC$    以汝黑暗的靈魂清淨吾身  冥王啊  將至高無上的力量   
$HIC$    與我的死亡暴風雪結合為一 以新的契約 統率冰雪之力
$HIC$    拉下生的華麗極光之幕 你將看到死神的面貌....... $NOR$

LONG);
	setup();
	replace_program(ROOM);
}
