inherit ROOM;
void create() {
	set( "short", "殺神齋" );
	set( "owner", "piccolo" );
	set( "item_desc", ([
		"painting" : @ITEM
你仔細的端詳了這幅字畫，才勉強的看出了上面寫的赫然竟是「殺神齋」，這裡的主人看
來真是好大的口氣啊！
ITEM,
	]) );
	set( "light_up", 1 );
	set( "object", ([
		"amount10" : 4,
		"file8"    : "/open/fire-hole/obj/r-pill",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/obj/gift/xisuidan",
		"amount8"  : 12,
		"amount9"  : 4,
		"amount1"  : 1,
		"file3"    : "/open/mogi/castle/obj/sspill",
		"amount4"  : 228,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file4"    : "/open/mogi/castle/obj/ninepill",
		"amount6"  : 1,
		"amount7"  : 1,
		"file10"   : "/open/fire-hole/obj/g-pill",
		"file2"    : "/open/mon/obj/mon-pill",
		"file6"    : "/open/mogi/dragon/obj/power",
		"amount2"  : 465,
		"file9"    : "/open/ping/obj/poison_pill",
		"amount3"  : 36,
		"amount5"  : 1,
	]) );
	set( "build", 12138 );
	set( "exits", ([
		"down"      : "/open/clan/sky-wu-chi/room/room453",
		"east"      : "/open/clan/sky-wu-chi/room/room491.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall.c",
		"north"     : "/open/clan/sky-wu-chi/room/room523",
	]) );
	set( "long", @LONG
剛踏進這間不大的小屋時，一種異樣的感覺瀰漫在你的心頭，你很難解釋那種漫天的
殺氣中卻充滿著浩然盈沛的天地正氣的那種對立，這種矛盾的感覺讓你難受的想要吐血，
小屋的中央牆壁上掛著一幅以狂草書寫的字畫(painting)，幾張簡單的桌椅，乾淨而明亮
的擺設，實在看不出這裏為什麼會有讓你那麼難受的那種壓迫感的產生，看來得好好的研
究一下這個令人充滿好奇的地方了。
LONG);
	setup();
	replace_program(ROOM);
}
