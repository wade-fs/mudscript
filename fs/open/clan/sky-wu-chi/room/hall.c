// Room : /open/clan/sky-wu-chi/room/hall.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "light_up", 1 );
        set( "cmkroom", 1 );
        set( "exits", ([ /* sizeof() == 7 */
		"down"      : "/open/clan/sky-wu-chi/room/room3.c",
		"room"      : "/open/clan/sky-wu-chi/room/room17.c",
		"east"      : "/open/clan/sky-wu-chi/room/room6.c",
		"south"     : "/open/clan/sky-wu-chi/room/room177.c",
		"up"        : "/open/clan/sky-wu-chi/room/room5.c",
		"west"      : "/open/clan/sky-wu-chi/room/room4.c",
]) );
        set( "no_clean_up", 0 );
        set( "short", "$HIC$ξ$HIY$天極殿$HIC$ξ$NOR$" ); 
	set( "object", ([
		"file4"    : "/obj/poison/rose_poison",
		"amount4"  : 110,
		"file6"    : "/open/ghost-hole/obj/light-spirit",
		"amount7"  : 1,
		"file3"    : "/obj/poison/faint_poison",
		"amount10" : 1,
		"amount2"  : 50,
		"file7"    : "/open/gblade/mob/lotch",
		"amount3"  : 109,
		"amount5"  : 111,
		"file10"   : "/open/doctor/obj/d-mark",
		"file2"    : "/obj/poison/dark_poison",
		"file5"    : "/obj/poison/five_poison",
		"amount6"  : 1,
	]) );
	set( "build", 11947 );
        set("long",@LONG
這裡是本幫的大廳，也是各方英雄好漢在此聚集開會，宴客之地
。一踏入此廳，可見所有物品擺設皆井然有序，條理分明。相傳是由
高人所設計，和天上的三垣二十八星宿，五星日月的運轉行度，有一
種玄妙的契合，故而可以萬古常存。在大廳後面的牆上，掛著一把絕
世神器「屠魔刀」，這是「無上先師」令東來贈送幫主的禮物。在大
廳的兩側牆上，則掛了兩句對聯，左是「藉武道以窺天道」，右是「
藉太極以窺無極」。是幫主勉勵幫眾的話也是幫名「天道無極」的由
來，由此可知幫主的學問知識之深幾近天人。在大廳右方的石板上，
刻了『天下風雲』四個大字，為的是能使本幫派能更進步，更加壯大
，以求各英雄豪傑多多留言，不吝指教。(look board)

LONG);
 set( "no_transmit", 1 );

        setup();                                             
        call_other( "/obj/board/sky-wu-chi_b", "???" );
        }

