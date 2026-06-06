inherit ROOM;
void create() {
	set( "short", "光碟片 寶物室" );
	set( "owner", "cdrom" );
	set( "object", ([
		"file4"    : "/open/capital/obj/4-4",
		"amount8"  : 54,
		"amount4"  : 1,
		"file6"    : "/obj/stone/suipian",
		"amount7"  : 706,
		"file3"    : "/open/killer/obj/s_pill",
		"amount10" : 1,
		"amount1"  : 345,
		"amount2"  : 1,
		"file7"    : "/obj/stone/powder",
		"amount3"  : 1875,
		"file8"    : "/open/killer/obj/black",
		"amount5"  : 129,
		"file10"   : "/open/area/fortress/npc/obj/pants01",
		"file1"    : "/open/ping/obj/poison_pill",
		"file9"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount9"  : 1,
		"file5"    : "/obj/stone/jiao",
		"file2"    : "/open/gsword/obj/spsword-1",
		"amount6"  : 65,
	]) );
	set( "build", 10148 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room618.c",
		"north"     : "/open/clan/sky-wu-chi/room/room619.c",
		"east"      : "/open/clan/sky-wu-chi/room/room237.c",
		"pray"      : "/open/clan/sky-wu-chi/room/room658",
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
