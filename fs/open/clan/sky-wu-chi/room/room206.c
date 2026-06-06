inherit ROOM;
void create() {
	set( "short", "天外天" );
	set( "owner", "roboo" );
	set( "object", ([
		"amount6"  : 1,
		"file4"    : "/open/common/obj/liz_meat",
		"file5"    : "/obj/example/besttea",
		"amount3"  : 1,
		"file7"    : "/obj/gift/xiandan",
		"amount5"  : 1,
		"amount2"  : 1,
		"file2"    : "/obj/gift/xiandan",
		"amount4"  : 1,
		"amount7"  : 1,
		"file6"    : "/obj/gift/xiandan",
		"file3"    : "/open/killer/obj/fire-knife",
	]) );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room16.c",
		"south"     : "/open/clan/sky-wu-chi/room/room358.c",
		"east"      : "/open/clan/sky-wu-chi/room/room245",
	]) );
	set( "light_up", 1 );
	set( "build", 10061 );
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
