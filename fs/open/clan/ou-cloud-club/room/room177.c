inherit ROOM;
void create() {
	set( "short", "$HIY$Radiohead$NOR$" );
	set( "owner", "devil" );
	set( "light_up", 1 );
	set( "object", ([
		"file7"    : "/open/doctor/pill/gnd_pill",
		"file9"    : "/open/magic-manor/obj/soil-ball",
		"file1"    : "/open/fire-hole/obj/k-pill",
		"amount7"  : 20,
		"file8"    : "/obj/gift/xisuidan",
		"amount3"  : 1,
		"amount9"  : 1,
		"file2"    : "/obj/gift/lingzhi",
		"amount8"  : 1,
		"amount2"  : 1,
		"amount1"  : 14,
		"file6"    : "/open/capital/guard/gring",
		"amount6"  : 1,
		"file3"    : "/open/killer/memory/static",
	]) );
	set( "build", 10024 );
	set( "exits", ([
		"down"      : "/open/clan/ou-cloud-club/room/room251",
		"out"       : "/open/clan/ou-cloud-club/room/room139.c",
		"up"        : "/open/clan/ou-cloud-club/room/room141.c",
	]) );
	set( "long", @LONG

沒有傳統媒體的過度包裝，電台司令以其近乎「藝術品」的後搖滾
實驗樂風，直接證明他們身為「九０年代另類搖滾代言人」的創作
實力其實，在製作Kid A 的同時，電台司令便已譜寫了二十三首作
品，其中已有十首收錄在Kid A 中。時隔半年有餘，他們又從其中
擇選十一首作品，發表了第五張專輯Amnesiac。雖是同時期的創作
，Amnesiac卻與Kid A融入大量電氣聲響、鼓擊的後搖滾格調不同。 

LONG);
	setup();
	replace_program(ROOM);
}
