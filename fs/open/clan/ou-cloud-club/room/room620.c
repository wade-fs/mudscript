inherit ROOM;
void create() {
	set( "short", "$HIC$劍$HIB$塚$NOR$" );
	set( "build", 3042 );
	set( "owner", "taa" );
	set( "exits", ([
		"up"        : "/open/clan/ou-cloud-club/room/room619",
	]) );
	set( "long", @LONG

                                      ██
                                       █
                               ██    █    ██
                                █     █     █
                         ██   █  ◢██◣  █   ██
                          █    █   ｜朝｜   █    █
                   ██   █  ◢█◣ ｜陽｜ ◢█◣  █   ██
                    █    █  ｜冬｜  ◣◢  ｜夕｜  █    █
                    █  ◢█◣｜陽｜  ██  ｜陽｜◢█◣  █
                    █  ｜豔｜｜  ｜  ██  ｜  ｜｜暖｜  █
                  ◢█◣｜陽｜｜  ｜  ██  ｜  ｜｜陽｜◢█◣
                  ｜烈｜｜  ｜｜  ｜  ██  ｜  ｜｜  ｜｜殘｜
                  ｜陽｜｜  ｜｜  ｜  ██  ｜  ｜｜  ｜｜陽｜
                  ｜  ｜｜  ｜｜  ｜  ██  ｜  ｜｜  ｜｜  ｜
                  ｜  ｜｜  ｜｜  ｜  ██  ｜  ｜｜  ｜｜  ｜
                  ｜  ｜｜  ｜｜  ｜  ◥◤  ｜  ｜｜  ｜｜  ｜
                  ｜  ｜｜  ｜｜  ｜        ｜  ｜｜  ｜｜  ｜
                  ｜  ｜｜  ｜ ＼／          ＼／ ｜  ｜｜  ｜
                  ｜  ｜｜  ｜                    ｜  ｜｜  ｜
                  ｜  ｜ ＼／                      ＼／ ｜  ｜
                  ｜  ｜                                ｜  ｜
                   ＼／                                  ＼／


LONG);
	setup();
	replace_program(ROOM);
}
