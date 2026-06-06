inherit ROOM;
void create() {
	set( "short", "童話森林的入口" );
	set( "owner", "panhermes" );
	set( "object", ([
		"amount10" : 4,
		"file6"    : "/open/snow/obj/sky_lin_stone",
		"amount7"  : 2,
		"amount8"  : 1,
		"amount5"  : 11,
		"file8"    : "/open/magic-manor/obj/sun-heart",
		"file5"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 8,
		"file7"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"file3"    : "/open/ping/obj/poison_pill",
		"amount2"  : 205,
		"amount3"  : 51,
		"file10"   : "/open/mogi/castle/obj/sspill",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 1,
		"file1"    : "/open/mon/obj/thousand-nectar",
		"amount1"  : 105,
		"file2"    : "/open/mon/obj/mon-pill",
	]) );
	set( "light_up", 1 );
	set( "build", 10028 );
	set( "item_desc", ([
		"board" : @ITEM
　          ┌─────────────────────┐
            │                                          │
            │           歡 迎 光 臨 白 雪 城           │
            │                                          │
            │    我是這個國家的國王，我們國家已有百    │
            │    年的歷史，可說是無人不知無人不曉，　　│
　　　　　　│　　今日你有幸到本國參觀，希望你能玩的　　│
　　　　　　│　　盡興，請別滋事擾民，否則讓你進得來　　│
　　　　　　│　　出不去。　　　　　　　　　　　　　　　│
　　　　　　│                                          │
            │　　　　　　　　　　　　　　　　working   │
　　　　　　│　　　　　　　　　　　                    │
            └─────────────────────┘
ITEM,
	]) );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room393.c",
		"west"      : "/open/clan/sky-wu-chi/room/room392.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
	]) );
	set( "long", @LONG
這裡是童話森林的入口，一個顯著的告示牌(board)插在路旁。地上鋪滿了一顆一
顆的鵝卵石，路旁種滿了像繡球般的花朵，在陣陣微風的吹拂之下，淡淡的清香
撲鼻而來。你可以看到遠處有一棟白色的城堡，而西邊隱約可以看到一間小木屋。
LONG);
	setup();
	replace_program(ROOM);
}
