inherit ROOM;
void create() {
	set( "short", "焚天魔域" );
	set( "object", ([
		"amount9"  : 56,
		"amount8"  : 100,
		"file4"    : "/open/mogi/castle/obj/sspill",
		"file3"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount2"  : 1,
		"file9"    : "/open/fire-hole/obj/b-pill",
		"amount1"  : 300,
		"amount4"  : 100,
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file2"    : "/open/magic-manor/fire/obj/fire-fan",
		"amount7"  : 100,
		"file7"    : "/open/mogi/castle/obj/sspill",
		"amount3"  : 1,
		"file8"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "build", 10224 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room179",
	]) );
	set( "long", @LONG

    這裡是傳說中的魔界之主焚天魔王的所在地古堡，裡面有許
多的機關，也有許多厲害的部下鎮守著各關卡，七魔將和黑白雙
煞更是其中的佼佼者，也許能僥倖打敗這些人，但是焚天魔王卻
比他們不知變態幾倍，以極火三掌打遍天下無敵手，要挑戰他要
有見小黑小白的心理準備，如果你已經準備好了，那就推開大門
進去吧。


LONG);
	setup();
	replace_program(ROOM);
}
