inherit ROOM;
void create() {
	set( "short", "龍元貯藏室" );
	set( "object", ([
		"amount1"  : 162,
		"amount4"  : 143,
		"file2"    : "/open/fire-hole/obj/w-pill",
		"file1"    : "/open/fire-hole/obj/b-pill",
		"file3"    : "/open/fire-hole/obj/k-pill",
		"amount2"  : 153,
		"file4"    : "/open/fire-hole/obj/r-pill",
		"amount3"  : 38,
	]) );
	set( "owner", "julio" );
	set( "build", 10819 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room158",
	]) );
	set( "long", @LONG
殘破的支柱,古老的建築,顯示出這邊是有深遠歷史的古城,由城內種種;遺跡的文化程度判斷,顯示此城就是封印著上古神器的封印之城,傳說千年前;在神話時代中所爆發的魔大戰中,神界於戰爭末期被魔族全面攻陷,倉皇逃出;的眾神,來到人間天國交界的此處,以初代戰神的遺體,配合珍貴聖獸的體質,;製作出毀天滅地的十二神器,藉此十二神器之助,終於逆轉戰局,擊潰焚天火王;的大軍,戰後,鑒於十二神器威力過大,不宜再度使用,遂封印於此城
LONG);
	setup();
	replace_program(ROOM);
}
