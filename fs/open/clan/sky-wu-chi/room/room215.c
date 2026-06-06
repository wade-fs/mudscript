inherit ROOM;
void create() {
	set( "short", "gloves" );
	set( "owner", "hild" );
	set( "object", ([
		"amount4"  : 1,
		"amount3"  : 1,
		"amount5"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file9"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount6"  : 1,
		"amount2"  : 1,
		"file4"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file3"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount7"  : 1,
		"amount9"  : 1,
		"file5"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file2"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"amount10" : 1,
		"file6"    : "/open/ghost-hole/obj/eq/ghost-gloves",
		"file10"   : "/open/ghost-hole/obj/eq/ghost-gloves",
	]) );
	set( "build", 10055 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room49",
		"east"      : "/open/clan/sky-wu-chi/room/room235.c",
		"west"      : "/open/clan/sky-wu-chi/room/room236.c",
	]) );
	set( "long", @LONG
 ╭┬──┬──╮       ★         ╭─    ‧   ─┼─╮  ╭╯    ●    ╭╯
   ├──┤  ╭┴─╮ ───     ╭┤    │││   │  │╭╯╭  ╭─╮╭╯╭
   ├──┤  │    │   ─   ─╮╯│╭╮│││   │  │╰─┤  ╞═╡╰─┤
 ─┴──┼─╰──╯   ─   ╭╯  │╰╯│││   │  │  ╭╯  │  │  ╭╯
  ‧        ╭──╮ ╭──╮╰╮││    │││ ─┼─┴─╰─╯╰─╯  ╰─╯
    ╭──┬╯╭─╮ │    │╭╯││    │││   │      ────┼────
╰─╯──┼─╯     │    │├╮┴┴─  ╰┼╯ ╭╯╰╮    ╭╯  │  ╰╮╮
．────┴───． ╰──╯╯╰────  │ ╭╯    ╰╮╰╯  ╰╯    ╰╯
                             ☆                                     ‧
    ★    ★         も            ‧        ★    ★        - ★ -     ★
                    **       ‧        ★                  ◢█◣
   ☆     ★                            ‧        ‧    ◢██◣       ‧
                 *          ┼         ‧            ◢██‧◣
                   *       │___________           ◢█‧██◣  ‧
                *       ◢◣◥████◣        ◢███▇█◣   ‧
      *     * #  # #  ◢██◣◥▇█▇█◣     ◢█★█○█▇◣
      *         *# ◢████◣◥▇█▇█◣  ◢▇███▇▇█◣‧
            * *     █◤◥█           |   ◢██▇▇█‧█▇◣
 ▁▁▃▄▃▂▁▁▂▂Ⅲ▃▄▅▇█████████████▇▇▆█▇▆████
LONG);
	setup();
	replace_program(ROOM);
}
