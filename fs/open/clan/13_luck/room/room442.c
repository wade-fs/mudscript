inherit ROOM;
void create() {
	set( "short", "幻世錄故事簡介2" );
	set( "object", ([
		"amount5"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount6"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/magic-manor/fire/obj/fire-fan",
		"file8"    : "/open/magic-manor/fire/obj/fire-fan",
		"file5"    : "/open/magic-manor/fire/obj/fire-fan",
	]) );
	set( "owner", "dfyw" );
	set( "build", 10018 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room443",
	]) );
	set( "long", @LONG

但是，馬扥爾王的野心無止盡的擴大，
以統一伊伯爾大陸為理由對外侵略其他種族的領土，而展開了種族戰爭。
期間，有睦鄰反目、親友相殘，友情親情乃至於愛情都在一瞬間隨風散去。
眼中只有同族和他族、我方與敵人之分。
就在戰局呈現泥沼化之時，
突然而來的災難打僵局，從引裂的大地中出現了三個巨大的魔神。

LONG);
	setup();
	replace_program(ROOM);
}
