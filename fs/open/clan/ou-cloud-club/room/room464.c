inherit ROOM;
void create() {
	set( "short", "血魔殿入口" );
	set( "owner", "mekyn" );
	set( "object", ([
		"amount4"  : 1,
		"file5"    : "/open/gsword/obj/dragon-sword",
		"amount6"  : 1,
		"amount7"  : 1,
		"file2"    : "/open/mogi/castle/obj/sspill",
		"file10"   : "/obj/stone/jiao",
		"amount2"  : 89,
		"file9"    : "/open/killer/obj/atman_pill",
		"amount3"  : 1,
		"file6"    : "/open/wind-rain/obj/bird-blade",
		"file4"    : "/open/gsword/obj/silver_sword",
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 1,
		"file7"    : "/open/killer/headkill/obj/world_dag",
		"file8"    : "/open/gsword/obj/dragon-sword",
		"amount5"  : 1,
		"amount8"  : 1,
		"file3"    : "/open/mogi/dragon/obj/scale",
		"amount1"  : 415,
		"amount9"  : 147,
	]) );
	set( "build", 10189 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/ou-cloud-club/room/room458",
		"out"       : "/open/clan/ou-cloud-club/room/room199.c",
		"east"      : "/open/clan/ou-cloud-club/room/room463.c",
	]) );
	set( "long", @LONG


                 _.-=▔▔=-._      _.-=▔▔=-._
               /'            \    /            `\
              ''              `\/'              ``
             #                     /﹌﹌﹌\       #
             #        /﹌﹌﹌\   （﹏﹏﹏/\)      #
             #      （(((())))）  `( @  @ )'      #
             #     （ ( @  @ ) ）  ╰╮╭╯       #
             #     （(╰╮╭╯)）/~◥|▼|◤~\     #
             #       /~\\﹍//~\ │  █║█  │    #
             ﹨     |＝| Ｙ |＝|││◥◣◤││   ∕
              `.    ▕│.﹍.│▏││   .▏││  .'
                \\           \\／／           //
                  \\    ＦＯＲＥＶＥＲ～～  //
                    `\_                  _/'
                       `\ __        __ /'
                             ▔  ▔


LONG);
	setup();
	replace_program(ROOM);
}
