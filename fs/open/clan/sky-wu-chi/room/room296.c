inherit ROOM;
void create() {
	set( "short", "赤龍裝備室" );
	set( "owner", "cdrom" );
	set( "object", ([
		"file5"    : "/open/capital/obj/4-1",
		"file10"   : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/shenliwan",
		"amount3"  : 1,
		"file4"    : "/open/tendo/obj/book",
		"file6"    : "/obj/gift/shenliwan",
		"amount8"  : 1,
		"amount4"  : 1,
		"amount2"  : 1,
		"file8"    : "/open/magic-manor/obj/soil-ball",
		"file9"    : "/obj/gift/shenliwan",
		"amount7"  : 1,
		"amount6"  : 1,
		"file7"    : "/obj/gift/shenliwan",
		"amount10" : 1,
		"amount1"  : 1,
		"file1"    : "/open/capital/obj/book",
		"amount5"  : 1,
		"file2"    : "/obj/gift/xisuidan",
		"amount9"  : 1,
	]) );
	set( "build", 10018 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room237.c",
		"south"     : "/open/clan/sky-wu-chi/room/room621",
		"north"     : "/open/clan/sky-wu-chi/room/room348.c",
	]) );
	set( "long", @LONG
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%                                         %%
    %% ############       ###############      %%
    %% #                  #             #      %%
    %% #                  #             #      %%
    %% #                  #             #      %%
    %% #                  #             #      %%
    %% #                  #             #      %%
    %% ############       #             #      %%
    %% #                  #             #      %%
    %% #                  #             #      %%
    %% #                  #             #      %%
    %% #                  #   ######### #      %%
    %% #                  #  #        ######   %%
    %% ############       ###############  ### %%
    %%                                         %%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
LONG);
	setup();
	replace_program(ROOM);
}
