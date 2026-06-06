inherit ROOM;
void create() {
	set( "short", "【天外天】" );
	set( "owner", "working" );
	set( "object", ([
		"amount9"  : 1,
		"file6"    : "/open/magic-manor/obj/fon-sky-sword",
		"amount5"  : 1,
		"file5"    : "/open/gsword/obj/dragon-sword",
		"file4"    : "/open/poison/obj/blue_key",
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/capital/obj/4-4",
		"amount3"  : 1,
		"file9"    : "/open/gsword/obj/silver_sword",
	]) );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room397.c",
		"west"      : "/open/clan/sky-wu-chi/room/room399.c",
	]) );
	set( "build", 17268 );
	set( "long", @LONG

    天使伸手用力地拽下身後的潔白雙翅。
    大量的鮮血噴出，濺紅了那些塵土，天使俯在塵土上，再也沒張開過眼睛。

    若能克服慾望，你能支配眾人，若屈服於慾望，你將貧賤而成為眾人的奴隸。

    以汝黑暗的靈魂清淨吾身  冥王啊  將至高無上的力量   
    與我的死亡暴風雪結合為一 以新的契約 統率冰雪之力
    拉下生的華麗極光之幕 你將看到死神的面貌....... 

LONG);
	setup();
	replace_program(ROOM);
}
