inherit ROOM;
void create() {
	set( "short", "$HIC$星$HIY$月$HIW$閣～$HIR$神$HIW$兵$WHT$藏$NOR$" );
	set( "owner", "left" );
	set( "object", ([
		"file4"    : "/open/capital/obj/4-2",
		"amount2"  : 1,
		"file6"    : "/open/capital/obj/4-2",
		"amount4"  : 1,
		"amount9"  : 1,
		"file9"    : "/open/capital/obj/4-3",
		"amount1"  : 1,
		"file2"    : "/open/capital/obj/4-4",
		"amount6"  : 1,
		"amount8"  : 1,
		"file8"    : "/open/capital/obj/blade2",
		"file1"    : "/open/capital/obj/4-1",
	]) );
	set( "build", 13176 );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room185",
	]) );
	set( "long", @LONG
    
    ║║═╬═╯╔═══╗╭╮  ╭—═╦═╦═╦╩╦═╮
    ║║═╬═╯║═══║║║╔╬╗  ║  ╠═╬═╬╗∣
    ╚╬╦╩╦╯  ╔╦╗◎║║╚╬╝  ║  ╠╦╩╦╩╝∣
      ║╠═╣   ╚╩╝  ║║  ║    ║  ╠╬═╬═╮∣
      ║╠═╣    ╠╮╠╮  ║◎║╭╮║  ║╚═╬═╯∣
    ◎╯╯  ╰——╯╰╯╰—╯╰╩╯╰╩═╯◎═╩═—╯

    ◎◎   展情絲   ◎◎            ◎◎   背眾生   ◎◎ 
    ◎◎   尋飄邈   ◎◎            ◎◎   想別離   ◎◎ 
    ◎◎   幻夢想   ◎◎            ◎◎   劍幻緣   ◎◎ 
                    ◎◎   敵星辰   ◎◎ 

LONG);
	setup();
	replace_program(ROOM);
}
