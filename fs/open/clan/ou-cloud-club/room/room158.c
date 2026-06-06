inherit ROOM;
void create() {
	set( "short", "歐胡的家" );
	set( "object", ([
		"amount1"  : 638,
		"amount4"  : 236,
		"amount5"  : 3,
		"file3"    : "/open/mon/obj/mon-pill",
		"file2"    : "/open/ping/obj/poison_pill",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file5"    : "/open/fire-hole/obj/b-pill",
		"amount2"  : 378,
		"amount3"  : 957,
		"file4"    : "/open/mogi/castle/obj/sspill",
	]) );
	set( "owner", "julio" );
	set( "exits", ([
		"east"      : "/open/clan/ou-cloud-club/room/room156.c",
		"south"     : "/open/clan/ou-cloud-club/room/room701",
		"west"      : "/open/clan/ou-cloud-club/room/room227.c",
		"north"     : "/open/clan/ou-cloud-club/room/room702",
	]) );
	set( "light_up", 1 );
	set( "build", 11043 );
	set( "long", @LONG
殘破的支柱,古老的建築,顯示出這邊是有深遠歷史的古城,由城內種種;遺跡的文化程度判斷,顯示此城就是封印著上古神器的封印之城,傳說千年前;在神話時代中所爆發的魔大戰中,神界於戰爭末期被魔族全面攻陷,倉皇逃出;的眾神,來到人間天國交界的此處,以初代戰神的遺體,配合珍貴聖獸的體質,;製作出毀天滅地的十二神器,藉此十二神器之助,終於逆轉戰局,擊潰焚天火王;的大軍,戰後,鑒於十二神器威力過大,不宜再度使用,遂封印於此城
LONG);
	setup();
	replace_program(ROOM);
}
