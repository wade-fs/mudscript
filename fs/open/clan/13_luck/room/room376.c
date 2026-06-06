inherit ROOM;
void create() {
	set( "short", "悟劍房" );
	set( "object", ([
		"amount5"  : 1,
		"file10"   : "/open/magic-manor/obj/evil-gwe-blade",
		"amount8"  : 1,
		"amount4"  : 1,
		"file5"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file8"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file9"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount2"  : 1,
		"amount9"  : 1,
		"file1"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount3"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file3"    : "/open/magic-manor/obj/evil-gwe-blade",
	]) );
	set( "owner", "roar" );
	set( "build", 10821 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/13_luck/room/room377",
	]) );
	set( "long", @LONG

    悟劍房因名而之其用意，此處乃劍堂弟子悟劍所在，因劍之所以為劍
，刀之所以為刀，其差異在於世人都認為劍是『正劍』而刀則屬『邪刀』
。而劍邪認為劍之意乃驅於用劍人本身之心，而正劍的局限過多，無法超
越劍術之巔，所以他將正心轉為邪念，以邪御劍，進而悟出天道九劍之第
九劍『極樂劍芒』，故此處是劍堂子弟以正轉邪之地。但在此處悟出第九
劍之人目前僅有兩者，一是劍邪，另一則是劍十三。

LONG);
	setup();
	replace_program(ROOM);
}
