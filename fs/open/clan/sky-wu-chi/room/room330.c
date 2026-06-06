inherit ROOM;
void create() {
	set( "short", "boots" );
	set( "owner", "hild" );
	set( "object", ([
		"amount2"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount7"  : 1,
		"amount5"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file6"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"file7"    : "/open/ghost-hole/obj/eq/ghost-boots",
		"amount10" : 1,
		"amount6"  : 1,
		"file10"   : "/open/ghost-hole/obj/eq/ghost-boots",
	]) );
	set( "build", 10125 );
	set( "light_up", 1 );
	set( "exits", ([
		"north"     : "/open/clan/sky-wu-chi/room/room49",
		"east"      : "/open/clan/sky-wu-chi/room/room316.c",
	]) );
	set( "long", @LONG




                                                    江           君    .   .
                                                         長  住   .   .....
                                                 頭        .   ☆  . ...
                                                    ☆ .     .       .
                                              我    .    .      .        ☆
                                          住      .   .     .︵ ︵ ─╮
                                                 .  .☆ . （  ' ╮ ） ╮
                                           長   .  .   .    ）q（ (===┤
                                               .  .  .    （  │, ）  ◢
                                          江  . .   .       ）╰┬)（ ）
                    共               日       . . . ☆       .* /  |（)
                        君               尾   ..            ,wWw（ ）（)◢ 　
                  飲                日       .               '','-╯ （╰╮
              長           見                                , │  ＼ ╰ ）
          江                  不       思                      │    ＼
     水                            君                          └～～～～

LONG);
	setup();
	replace_program(ROOM);
}
