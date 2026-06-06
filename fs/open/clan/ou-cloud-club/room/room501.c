inherit ROOM;
void create() {
	set( "short", "剛強的遊戲室" );
	set( "object", ([
		"file1"    : "/open/mogi/castle/obj/ninepill",
		"file3"    : "/open/magic-manor/ghost/obj/trigram-pill",
		"amount8"  : 1363,
		"amount9"  : 666,
		"amount3"  : 76,
		"file6"    : "/open/fire-hole/obj/w-pill",
		"file8"    : "/open/mon/obj/thousand-nectar",
		"amount5"  : 511,
		"amount1"  : 444,
		"amount6"  : 102,
		"amount2"  : 9,
		"file9"    : "/open/ping/obj/poison_pill",
		"amount7"  : 255,
		"file5"    : "/open/mogi/castle/obj/sspill",
		"file2"    : "/open/fire-hole/obj/y-pill",
		"amount4"  : 634,
		"file7"    : "/open/fire-hole/obj/k-pill",
		"file4"    : "/open/mon/obj/mon-pill",
	]) );
	set( "build", 10386 );
	set( "light_up", 1 );
	set( "owner", "roboii" );
	set( "exits", ([
		"north"     : "/open/clan/ou-cloud-club/room/room505",
	]) );
	set( "long", @LONG
$HIR$                                                       #####
$HIR$                                               ###########
$HIR$                                            ##########
$HIR$                                        ###########
$HIR$                                     ##########
$HIR$                          ##       ##########
$HIR$                         #       #########
$HIR$                       ###    ############
$HIR$                       ##    ###########
$HIR$                     ###   ############
$HIR$                     ###   ############
$HIR$                    ###################           ###
$HIR$                   #################################
$HIR$                  ##############################
$HIR$                 #########################
$HIR$                 #######################
$HIR$         #      #################### 
$HIR$         ####  ##################
$HIR$          ##############    ###
$HIR$           ###########     ###
$HIR$           ##########
$HIR$          #########                        #####
$HIR$          ########                ##########
$HIR$           #######     ###   #########
$HIR$           #### ##   ####  ######
$HIR$           ### # #  ##########
$HIR$           #####  #### ####
$HIR$           ## ### ########
$HIR$          ### ##########
$HIR$         ### ###########
$HIR$         #################     ######
$HIR$         ###############       #####      #####
$HIR$        #####     ######      ##############
$HIR$      #######       ######################
$HIR$      #####        ###################
$HIR$         ##       ###############
$HIR$               ######
$HIR$               #######
$HIR$                  ### 
$NOR$
LONG);
	setup();
	replace_program(ROOM);
}
