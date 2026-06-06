inherit ROOM;
void create() {
	set( "short", "$GRN$砲陣地$NOR$" );
	set( "owner", "really" );
	set( "object", ([
		"amount2"  : 3331,
		"amount9"  : 40,
		"amount7"  : 1,
		"amount6"  : 11,
		"amount1"  : 1,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"file6"    : "/open/fire-hole/obj/k-pill",
		"file10"   : "/obj/gift/xiandan",
		"amount3"  : 1,
		"file8"    : "/obj/gift/unknowdan",
		"file5"    : "/open/magic-manor/obj/fire-ball",
		"amount10" : 1,
		"file1"    : "/obj/gift/unknowdan",
		"file2"    : "/open/fire-hole/obj/g-pill",
		"amount4"  : 259,
		"file7"    : "/obj/gift/lingzhi",
		"file3"    : "/obj/gift/lingzhi",
		"amount8"  : 1,
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount5"  : 1,
	]) );
	set( "build", 10010 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room88.c",
		"east"      : "/open/clan/ou-cloud-club/room/room147.c",
		"north"     : "/open/clan/ou-cloud-club/room/room254.c",
	]) );
	set( "long", @LONG
這裡是一片空曠的草原，綠油油的一片讓人看了心曠神
怡，正前方有一塊焦黑的地皮，原來那邊架了一門火砲，上
面寫著『國造六三式一二○公厘迫擊砲』，旁邊還站了幾個
身穿迷彩軍服正在操練的阿兵哥。不遠處有幾條不知道通往
何處的深邃小徑，好奇的你有點躍躍欲試想去探險的感覺。
  
  一二○公厘迫擊砲(Ternch mortar)
  迫擊砲砲班班長(Mortar corporal)  
  迫擊砲砲班砲手(Mortar man1 - 3)
  
LONG);
	setup();
	replace_program(ROOM);
}
