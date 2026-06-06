inherit ROOM;
void create() {
	set( "short", "裝備貯藏室" );
	set( "owner", "julio" );
	set( "object", ([
		"amount1"  : 1,
		"file2"    : "/open/mogi/dragon/obj/scale",
		"amount3"  : 1,
		"amount7"  : 1,
		"file6"    : "/open/mogi/dragon/obj/scale",
		"amount2"  : 1,
		"amount6"  : 1,
		"amount4"  : 1,
		"amount10" : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file8"    : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
		"amount5"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount8"  : 1,
		"file4"    : "/open/mogi/dragon/obj/scale",
		"file1"    : "/open/mogi/dragon/obj/scale",
		"file7"    : "/open/mogi/dragon/obj/scale",
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
	]) );
	set( "build", 17255 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/ou-cloud-club/room/room158",
	]) );
	set( "long", @LONG
殘破的支柱,古老的建築,顯示出這邊是有深遠歷史的古城,由城內種種;遺跡的文化程度判斷,顯示此城就是封印著上古神器的封印之城,傳說千年前;在神話時代中所爆發的魔大戰中,神界於戰爭末期被魔族全面攻陷,倉皇逃出;的眾神,來到人間天國交界的此處,以初代戰神的遺體,配合珍貴聖獸的體質,;製作出毀天滅地的十二神器,藉此十二神器之助,終於逆轉戰局,擊潰焚天火王;的大軍,戰後,鑒於十二神器威力過大,不宜再度使用,遂封印於此城
LONG);
	setup();
	replace_program(ROOM);
}
